/*
 * LogDef.h
 *
 *  Created on: 2014/7/11
 *      Author: leo
 */

#ifndef LOGDEF_H_
#define LOGDEF_H_

#define __LOGLV     8

//#define _Emergencylv      0
//#define _Alertlv          1
//#define _Criticallv       2
//#define _Errorlv          3
//#define _Warninglv        4
//#define _Infolv           5
//#define _Debuglv          6
//#define _DetailDebuglv    7
//#define _Tracelv          8

//enum LogLevel {EMERGENCY, ALERT, CRITICAL, ERROR, WARNING, INFO, DEBUG, DETAILDEBUG, TRACE};
enum LogLevel {EMERGENCY, ALERT, CRITICAL, ERROR, WARNING, INFO, DEBUG, DETAIL, TRACE};

#define _Emergencylv    0
#define _Alertlv        1
#define _Criticallv     2
#define _Errorlv        3
#define _Warninglv      4
#define _Infolv         5
#define _Debuglv        6
#define _DetailDebuglv  7
#define _Tracelv        8

#endif /* LOGDEF_H_ */
