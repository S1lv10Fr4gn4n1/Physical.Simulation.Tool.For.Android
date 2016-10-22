#ifndef LOG_H_
#define LOG_H_

#include <android/log.h>

#define LOG_TAG "Physical.Tool"

#define LOG_INFO(...) \
	LOG(ANDROID_LOG_INFO,__VA_ARGS__)
#define  LOG_DEBUG(...) \
	LOG(ANDROID_LOG_DEBUG, __VA_ARGS__)
#define LOG_ERROR(...) \
	LOG(ANDROID_LOG_ERROR, __VA_ARGS__)

#ifdef _LOG_
	#define LOG(type, ...) \
		__android_log_print(type,LOG_TAG,__VA_ARGS__)
#else
	#define LOG(type, ...)
#endif

#endif
