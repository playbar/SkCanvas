/*
 * Log.cpp
 *
 *  Created on: 2015-6-12
 *      Author: jkd2972
 */

#include "EGTLog.h"
#include <cstring>
#include <cstdio>

#define MESSAGE_SIZE 512
static char message[MESSAGE_SIZE];
namespace egret_opensl{
static LogLevel loglevel = LogLevel_First;
void androidLog(LogLevel level, const char *tag, const char *format, ...) {
	if (loglevel > level) {
		return;
	}

	message[0] = '\0';
	va_list args;
	strcpy(message, tag);
	strcat(message, ":");
	va_start(args, format);
	vsnprintf(message + strlen(message), MESSAGE_SIZE - strlen(message), format,
			args);
	va_end(args);
	int prio;
	switch (level) {
	case LogLevel_Info:
		prio = ANDROID_LOG_INFO;
		break;
	case LogLevel_Warn:
		prio = ANDROID_LOG_WARN;
		break;
	case LogLevel_Error:
		prio = ANDROID_LOG_ERROR;
		break;
	default:
		prio = ANDROID_LOG_DEBUG;
		break;
	}
	__android_log_print(prio, "EgretSkiaTest", "%s", message);

}

}/* namespace egret_opensl */
