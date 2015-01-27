/*
 * UTCTime.h
 *
 *  Created on: 2014/4/22
 *      Author: nemo
 */

#ifndef UTCTIME_H_
#define UTCTIME_H_

#include <string>

using namespace std;

namespace TimeUtils {

void   getTimeStr(char *timeStr);
string getTimeStr();
string getDateStr();

string getTimeStrWithoutParentheses();
string getTimeStrAsFileName();

};

#endif /* UTCTIME_H_ */
