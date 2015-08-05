/*
 * Log.h
 *
 *  Created on: 2015-6-12
 *      Author: jkd2972
 */
#ifndef LOG_H_
#define LOG_H_
#include <android/log.h>



namespace egret_opensl{

typedef enum LogLevel{
    LogLevel_First = 0,
    LogLevel_All = 0,
    LogLevel_Debug,
    LogLevel_Info,
    LogLevel_Warn,
    LogLevel_Error,
    LogLevel_Off,
    LogLevel_Last
}LogLevel;

#define LOGTD(TAG, ...) egret_opensl::androidLog(egret_opensl::LogLevel_Debug, TAG, __VA_ARGS__)
#define LOGTI(TAG, ...) egret_opensl::androidLog(egret_opensl::LogLevel_Info, TAG, __VA_ARGS__)
#define LOGTW(TAG, ...) egret_opensl::androidLog(egret_opensl::LogLevel_Warn, TAG, __VA_ARGS__)
#define LOGTE(TAG, ...) egret_opensl::androidLog(egret_opensl::LogLevel_Error, TAG, __VA_ARGS__)
#define LOGD(...) egret_opensl::androidLog(egret_opensl::LogLevel_Debug, LOG_TAG, __VA_ARGS__)
#define LOGI(...) egret_opensl::androidLog(egret_opensl::LogLevel_Debug, LOG_TAG, __VA_ARGS__)
#define LOGW(...) egret_opensl::androidLog(egret_opensl::LogLevel_Warn, LOG_TAG, __VA_ARGS__)
#define LOGE(...) egret_opensl::androidLog(egret_opensl::LogLevel_Error, LOG_TAG, __VA_ARGS__)
void androidLog(LogLevel level, const char *tag, const char *format, ...);

} /* namespace egret_opensl */
#endif /* LOG_H_ */
