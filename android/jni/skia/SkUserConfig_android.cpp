#include "SkTypes.h"
#include "SkUserConfig.h"

#include <android/log.h>
#include <stdio.h>
#define  LOG_TAG    "SkDebugf_FileLine"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

#define MESSAGE_SIZE (1024*10)
static char message[MESSAGE_SIZE];
void SkDebugf_FileLine(const char* file, int line, bool fatal,
                       const char* format, ...) {
  message[0] = '\0';

  sprintf(message,"%s;%d;%d : ",file,line,fatal);

  va_list args;
  va_start(args, format);
  vsnprintf(message + strlen(message), MESSAGE_SIZE - strlen(message),
          format, args);
  va_end(args);

  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "%s", message);
}
