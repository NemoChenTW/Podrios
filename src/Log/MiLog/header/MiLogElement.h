/*
 * MiLogElement.h
 *
 *  Created on: 2014/11/13
 *      Author: leo
 */

#ifndef MILOGELEMENT_H_
#define MILOGELEMENT_H_

#include "Common/Utility/TimeUtils.h"

//  ********** Copy this definition to the Necessary Location **********
//
//  enum LogLevel{Fatal, Error, Warning, Debug, Info};
//
//  ********** Copy this definition to the Necessary Location **********
// enum LogLevel{Emergency, Alert, Critical, Error, Warning, Info, Debug, DetailDebug, Trace};

/*
 * Emergency : System is unusable. E.g. Hardware Error.
 * Alert : Action must be taken immediately. E.g. Network error, Low Battery.
 * Critical : Should be corrected immediately, but failure not stronger than Alert. E.g. Low Level Operation, Token Box Full.
 * Error : Software Error. E.g. Program crash.
 * Warning : Warning messages, not an error, but indication that an error will occur if action is not taken. E.g.Token Box 85% full
 *
 * Info : Operating Information
 * Debug : Debug message. Show Event Name, E.g. People in Security Area
 * DetailDebug : More Detail Debug message. The action of the happened event E.g. Play Sound, Flash light
 * Trace :  Detail Trace message. E.g Send 0x10 0x06 to PLC for ACK, Go into execution function.
 */
class MiLogElement {
private:
    /*  >> Variable Definition >>
     *
     *  LogNCStr : Final Log String for LogNC
     *  TimeStr : Time stamp String
     *  LabelStr : Label String
     *  ClassStr : Class String
     *  MethodStr : Method String
     *  MsgStr : Message String
     *
     *  << Variable Definition <<
     */
    string LogNCStr, TimeStr, LabelStr, ClassStr, MethodStr, MsgStr;

    LogLevel LogLv;

    // For Print Out the Enumerated Text
    const string LevelLable[9] =
        { "Emergency", "Alert", "Critical", "Error", "Warning", "Info ", "Debug", "DetailDebug", "Trace" };

public:
    MiLogElement(LogLevel level, string ClassName, string MethodName, string Msg)
        :LogLv(level), ClassStr(ClassName), MethodStr(MethodName), MsgStr(Msg)
    {
        TimeStr = TimeUtils::getTimeStr();
        LabelStr = LevelLable[LogLv];

        LogNCStr = TimeStr + "[" + LabelStr + "] " + ClassStr + "::" + MethodStr + "-> " + MsgStr;
    }
    virtual ~MiLogElement()
    {
    }

    string getLogNCStr()
    {
        return LogNCStr;
    }

    LogLevel getLogLevel()
    {
        return LogLv;
    }
};

#endif /* MILOGELEMENT_H_ */
