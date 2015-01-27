/*
 * MiLog4CPP.h
 *
 *  Created on: 2014/4/22
 *      Author: nemo
 */

#ifndef MILOG4CPP_H_
#define MILOG4CPP_H_

#include <string>
#include <list>

#include "LogDef.h"

using namespace std;

class MiLogElement;

class MiLog {
public:
    static MiLog* getInstance();
    static void createInstance(LogLevel DefinedLevel, bool Screen);
    // TODO delete instance

    ///	Re-open the log File, for creating the new file at new day.
    int reopenLogFile();

	//	Records the Log
	void log(LogLevel level, string className, string methodName, string msg);
	void log(LogLevel level, string className, string methodName, char *msg, ...);

	// Records log immediately
	void logNoWait(LogLevel level, string className, string methodName, char *msg, ...);
	//	Record hex data
	void logHex(LogLevel level, string className, string methodName, char *header, unsigned char *pMsg, int iMsgLen);

private:
    MiLog(LogLevel DefinedLevel, bool Screen);
    virtual ~MiLog();

    static MiLog* instance;

    int logFile;                    ///< Log file pointer.
	int logIndex;					///< Log message index
    list<MiLogElement*> logList;    ///< Storing the input log message.

	LogLevel DefinedLogLevel;		///< The definition of log level.
	bool isShowOnScreen = false;    ///< Control the log message shown on screen or not.
	bool isAbleToWrite  = false;    ///<  Control the WriteLog is able to work or not.

    /// Open log File
    bool openLogFile();
    /// Write input Log to File
    bool writeLog(string inputLog);

    // start thread to output log
    void startThread();
    // Output Log to the file
    void outputLogs();
};

#endif /* MILOG4CPP_H_ */
