/*
 * MiLog.h
 *
 *  Created on: 2014/10/13
 *      Author: leo
 */

#ifndef MILOG_H_
#define MILOG_H_

#include <typeinfo>
#include <cxxabi.h>

#include "MiLog4CPP.h"

#define __CLASS_NAME__    abi::__cxa_demangle(typeid(*this).name(), 0, 0, NULL)
#define __NO_CLASS_NAME__ ""

#define Logger (MiLog::getInstance())

#if (__LOGLV >= _Alertlv)
    #define LOG_ALERT(...)      Logger->logNoWait(ALERT, __CLASS_NAME__,    __FUNCTION__, ##__VA_ARGS__);
    #define LOG_S_ALERT(...)    Logger->log(ALERT, __NO_CLASS_NAME__, __FUNCTION__, ##__VA_ARGS__);
#else
    #define LOG_ALERT(...)      ;
    #define LOG_S_ALERT(...)    ;
#endif

#if (__LOGLV >= _Criticallv)
    #define LOG_CRITICAL(...)       Logger->logNoWait(CRITICAL, __CLASS_NAME__,    __FUNCTION__, ##__VA_ARGS__);
    #define LOG_S_CRITICAL(...)     Logger->log(CRITICAL, __NO_CLASS_NAME__, __FUNCTION__, ##__VA_ARGS__);
#else
    #define LOG_CRITICAL(...)       ;
    #define LOG_S_CRITICAL(...)     ;
#endif

#if (__LOGLV >= _Errorlv)
    #define LOG_ERROR(...)      Logger->log(ERROR, __CLASS_NAME__,    __FUNCTION__, ##__VA_ARGS__);
    #define LOG_S_ERROR(...)    Logger->log(ERROR, __NO_CLASS_NAME__, __FUNCTION__, ##__VA_ARGS__);
#else
    #define LOG_ERROR(...)      ;
    #define LOG_S_ERROR(...)    ;
#endif

#if (__LOGLV >= Warning)
    #define LOG_WARNING(...)    Logger->log(WARNING, __CLASS_NAME__,    __FUNCTION__, ##__VA_ARGS__);
    #define LOG_S_WARNING(...)  Logger->log(WARNING, __NO_CLASS_NAME__, __FUNCTION__, ##__VA_ARGS__);
#else
    #define LOG_WARNING(...)    ;
    #define LOG_S_WARNING(...)  ;
#endif

#if (__LOGLV >= _Infolv)
    #define LOG_INFO(...)       Logger->log(INFO, __CLASS_NAME__,    __FUNCTION__, ##__VA_ARGS__);
    #define LOG_S_INFO(...)     Logger->log(INFO, __NO_CLASS_NAME__, __FUNCTION__, ##__VA_ARGS__);
#else
    #define LOG_INFO(...)       ;
    #define LOG_S_INFO(...)     ;
#endif

#if (__LOGLV >= _Debuglv)
    #define LOG_DEBUG(...)      Logger->log(DEBUG,  __CLASS_NAME__,    __FUNCTION__, ##__VA_ARGS__);
    #define LOG_S_DEBUG(...)    Logger->log(DEBUG,  __NO_CLASS_NAME__, __FUNCTION__, ##__VA_ARGS__);
#else
    #define LOG_DEBUG(...)      ;
    #define LOG_S_DEBUG(...)    ;
#endif

#if (__LOGLV >= _DetailDebuglv)
    #define LOG_HEX(...)        Logger->logHex(DETAIL,  __CLASS_NAME__, __FUNCTION__, ##__VA_ARGS__);

    #define LOG_DETAIL(...)     Logger->log(DETAIL,  __CLASS_NAME__,    __FUNCTION__, ##__VA_ARGS__);
    #define LOG_S_DETAIL(...)   Logger->log(DETAIL,  __NO_CLASS_NAME__, __FUNCTION__, ##__VA_ARGS__);
#else
    #define LOG_HEX(...)        ;

    #define LOG_DETAIL(...)     ;
    #define LOG_S_DETAIL(...)   ;
#endif

#if (__LOGLV >= _Tracelv)
    #define LOG_TRACE(...)      Logger->log(TRACE,  __CLASS_NAME__,     __FUNCTION__, ##__VA_ARGS__);
    #define LOG_S_TRACE(...)    Logger->log(TRACE,  __NO_CLASS_NAME__,  __FUNCTION__, ##__VA_ARGS__);
#else
    #define LOG_TRACE(...)      ;
    #define LOG_S_TRACE(...)    ;
#endif


#define LOG(LEVEL, MSG, ...)    LOG_##LEVEL(MSG, ##__VA_ARGS__)

#define LOGF(LEVEL, COND)              if (true == COND) { LOG_##LEVEL(#COND) }
#define LOG_IF(LEVEL, COND, MSG, ...)  if (true == COND) { LOG_##LEVEL(MSG, ##__VA_ARGS__) }

#define LOG_CHECK(COND, MSG1, MSG2) \
        if (true == COND) { LOG MSG1 } \
        else              { LOG MSG2 }

#endif /* MILOG_H_ */
