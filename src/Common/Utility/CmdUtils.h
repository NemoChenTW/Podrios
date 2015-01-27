/*
 * CmdUtils.h
 *
 *  Created on: 2014/11/12
 *      Author: leo
 */

#ifndef CMDUTILS_H_
#define CMDUTILS_H_

#include "Log/MiLog/header/MiLog.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define MAX_PIPEBUF_SIZE    128

namespace CmdUtils {

/**
 * execute shell command and check result valid
 */
static bool shellExecute(const char* cmdString) {
    if (NULL == cmdString) return false;

    int status = system(cmdString);
    if (status < 0) {
        LOG_S_ERROR("Cmd: %s\t error: %s", cmdString, strerror(errno))
        return false;
    }

    if (WIFEXITED(status)) {            // 取得command執行結果
        LOG_S_INFO("normal termination, exit status = %d", WEXITSTATUS(status))

    } else if (WIFSIGNALED(status)) {   // 如果command被信號中斷,取得信號值
        LOG_S_WARNING("abnormal termination,signal number =%d", WTERMSIG(status))
    } else if (WIFSTOPPED(status)) {    // 如果command被信號暫停執行,取得信號值
        LOG_S_WARNING("process stopped, signal number =%d", WSTOPSIG(status))
    }
    return true;
}

/**
 * Execute shell command and get output result
 */
static std::string getCmdOutput(const char* cmdString) {
    FILE* pipe = popen(cmdString, "r");
    if (!pipe) return "ERROR";

    char buffer[MAX_PIPEBUF_SIZE];
    std::string result("");
    while(!feof(pipe)) {
        if(fgets(buffer, MAX_PIPEBUF_SIZE, pipe) != NULL)
            result += buffer;
    }
    pclose(pipe);
    return result.substr(0, result.length()-1);
}

}

#endif /* CMDUTILS_H_ */
