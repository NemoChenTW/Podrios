/*
 * UTCTime.cpp
 *
 *  Created on: 2014/4/22
 *      Author: nemo
 */

#include "TimeUtils.h"

#include <sys/time.h>
#include <stdio.h>

//string wday[7]={"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

void TimeUtils::getTimeStr(char *timeStr) {
    struct timeval timep;
	gettimeofday(&timep, NULL);
	struct tm *p = localtime(&timep.tv_sec);
	sprintf(timeStr, "(%04d.%02d.%02d, %02d:%02d:%02d.%03d) ",
			(1900 + p->tm_year), (1 + p->tm_mon), p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec, timep.tv_usec/1000);
}

string TimeUtils::getTimeStr() {
	char timeStr[256];
	getTimeStr(timeStr);

	return timeStr;
}

string TimeUtils::getDateStr() {
    time_t rawTime = time(NULL);
    struct tm *local = localtime(&rawTime);

    char timeStr[128];
    sprintf(timeStr, "%04d%02d%02d", 1900+local->tm_year, 1+local->tm_mon, local->tm_mday);
    return timeStr;
}

string TimeUtils::getTimeStrWithoutParentheses() {
	char timeStr[256];
	struct timeval timep;
	gettimeofday(&timep, NULL);
	struct tm *p = localtime(&timep.tv_sec);
	sprintf(timeStr, "%04d.%02d.%02d, %02d:%02d:%02d.%03d",
	        (1900 + p->tm_year), (1 + p->tm_mon), p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec, timep.tv_usec/1000);

	return timeStr;
}

string TimeUtils::getTimeStrAsFileName() {
	char timeStr[256];
    struct timeval timep;
	gettimeofday(&timep, NULL);
	struct tm *p = localtime(&timep.tv_sec);

    sprintf(timeStr, "Log%04d%02d%02d", (1900 +p->tm_year), (1 +p->tm_mon), p->tm_mday);
	return timeStr;
}
