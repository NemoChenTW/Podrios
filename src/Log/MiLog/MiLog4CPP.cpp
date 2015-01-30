/*
 * MiLog4CPP.cpp
 *
 *  Created on: 2014/4/22
 *      Author: nemo
 */

#include "header/MiLog4CPP.h"
#include "header/MiLogElement.h"

#include "Common/Utility/Utils.h"

#include <iostream>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include <thread>
#include <mutex>
#include <condition_variable>

#define MAX_LOGBUF_SIZE 128

thread             gThread;         // output logList logs
mutex              gLogMutex;       // protected logList
condition_variable gLogCond;        // for wait and signal list input

MiLog* MiLog::instance = NULL;

MiLog* MiLog::getInstance() {
    if (!instance) {
        puts("MiLog Instance not yet created.");
        exit(EXIT_FAILURE);
    }
    return instance;
}
void MiLog::createInstance(LogLevel DefinedLevel, bool Screen) {
    if (instance) {
        puts("MiLog Instance has already been create.");
    } else {
        instance = new MiLog(DefinedLevel, Screen);
    }
}

MiLog::MiLog(LogLevel DefinedLevel, bool Screen)
:logIndex(0), DefinedLogLevel(DefinedLevel), isShowOnScreen(Screen) {
	bool isOpenSucceed = openLogFile();
	if (isOpenSucceed) {
		isAbleToWrite = true;
	} else {
		//TODO 處理開檔失敗
	}

    startThread();
}

MiLog::~MiLog() {
    gThread.join(); // TODO wait for thread exit
    gThread.detach();

	close(logFile);
}

/** Start Thread to output logs **/
void MiLog::startThread() {
    /* Create output log thread */
    gThread = thread(&MiLog::outputLogs, this);
    usleep(25000);
}

/**
 *	@brief		Open log File
 *
 *	@retval	 0	Open log file success.
 *	@retval	-1	Open log file fail.
 *
 *	Open the log file, create new one if there is
 *	no existing log file.
 */
bool MiLog::openLogFile() {
	FileUtils::createDir(PathUtils::LOG_DIR);
	/*	Generate the Log File Name */
    FileUtils::createDir(PathUtils::PODRIOS_LOG_DIR);
	string FileName = PathUtils::PODRIOS_LOG_DIR + TimeUtils::getTimeStrAsFileName() + ".log";

    int file_open_check = access(FileName.c_str(), F_OK);
    if (file_open_check == -1) {
        //	Open New Log File
        logFile = open(FileName.c_str(), O_RDWR | O_CREAT, 0666);
        if (logFile < 0)    cout << "OPEN New Log File Fail"    << endl;
        else                cout << "OPEN New Log File Success" << endl;
    } else {
        // Open Exist Log File
        logFile = open(FileName.c_str(), O_RDWR | O_APPEND, 0666);
        if (logFile < 0)    cout << "OPEN Log File Fail"    << endl;
        else                cout << "OPEN Log File Success" << endl;
    }
    /* create EMM log link */
    unlink(PathUtils::PODRIOS_LOG_LINK);
    symlink(FileName.c_str(), PathUtils::PODRIOS_LOG_LINK);

    if(logFile >= 0)
    	return true;
    else
    	return false;
}

///	Re-open the log File, for creating the new file at new day.
int MiLog::reopenLogFile() {

	while(!logList.empty())
		sleep(2);

	isAbleToWrite = false;
	close(logFile);

    if (openLogFile()) {
	    log(DEBUG,  "MiLog", __FUNCTION__, "--------------- New Log Start!!! ---------------");
		logIndex = 0;	///< Reset the Log index.
		isAbleToWrite = true;
		return 0;
	}
    else
    	return -1;
}

//**************************************************
//	LogRecords : Records the Log
//
//	LogLevel level : Log Record Level.  ex. Fatal, Error, Warning, Debug, Info
//	string ClassName : The Class Name of the Log Owner
//	string MethodName : The Method Name of the Log Owner
//	string Msg : Log Message
//
//	Return value : According to the definition of error code, 0 is normal
//**************************************************
void MiLog::log(LogLevel level, string className, string methodName, string msg) {
    gLogMutex.lock();

    MiLogElement *log = new MiLogElement(level, className, methodName, msg);
    logList.push_back(log);
    gLogCond.notify_one();

    gLogMutex.unlock();
}

void MiLog::log(LogLevel level, string className, string methodName, char *msg, ...) {
    char buffer[MAX_LOGBUF_SIZE];

    va_list va_args;
    va_start(va_args, msg);
    vsnprintf(buffer, sizeof(buffer), msg, va_args);
    va_end(va_args);

    log(level, className, methodName, string(buffer));
}

void MiLog::logNoWait(LogLevel level, string className, string methodName, char *msg, ...) {
    if (isAbleToWrite) {
        char buffer[MAX_LOGBUF_SIZE];

        va_list va_args;
        va_start(va_args, msg);
        vsnprintf(buffer, sizeof(buffer), msg, va_args);
        va_end(va_args);

        MiLogElement log(level, className, methodName, buffer);
        writeLog(log.getLogNCStr());
    }
}

void MiLog::logHex(LogLevel level, string className, string methodName, char* header, unsigned char* pMsg, int iMsgLen) {
    string logText(header);
    logText.append((iMsgLen > 10) ?"\n" :" ");

    unsigned char ctemp[8];
    for (int i = 0; i < iMsgLen; i++) {
        if (i % 10 == 0 && i != 0) {
            logText.append("\n");
        }
        sprintf((char *)ctemp, "%02X ", (unsigned char *)*(pMsg +i));
        logText.append((char*)ctemp, 3);
    }
    log(level, className, methodName, logText);
}

//**************************************************
//	WirteLog : Write Log in buffer to File
//
//	string inputLog : The input Log
//
//	Return value : According to the definition of error code, 0 is normal
//**************************************************
bool MiLog::writeLog(string inputLog) {
    stringstream tmpSS;
    tmpSS << logIndex++;

    string tmpLog = "@[" + tmpSS.str() + "] " + inputLog + "\n";
    int wrs = write(logFile, tmpLog.c_str(), tmpLog.size());
	if (isShowOnScreen) cout << tmpLog;

    if (DefinedLogLevel >= WARNING) {
        if (wrs != tmpLog.size()) {
			wrs = write(logFile, "@[Warning] Write Log Error\n", sizeof("@[Warning] Write Log Error\n"));
			if(isShowOnScreen)
				cout << "[Warning] Write Log Error\n";

			return false;
		}
	}
	return true;
}

//**************************************************
//  OutputLog : Output Log to the file
//
//  Return value : According to the definition of error code, 0 is normal
//**************************************************
void MiLog::outputLogs() {
    std::unique_lock<std::mutex> lck(gLogMutex);
    int errCount = 0;
    while (true) {
        gLogCond.wait(lck); // wait for log input signal
        if (isAbleToWrite) {
            while (!logList.empty()) {
                MiLogElement* log = logList.front();
                if (writeLog(log->getLogNCStr())) {
                    logList.pop_front();
                    delete log;
                    errCount = 0;

                } else if(errCount == 3) {  // Error Occurs three times
                    writeLog("@[Error] 3 Times Write Log Fail\n");
                    logList.pop_front();
                    delete log;
                    errCount = 0;

                } else {                    // Error Occurs
                    errCount++;
                }
            }
        }
    }
}
