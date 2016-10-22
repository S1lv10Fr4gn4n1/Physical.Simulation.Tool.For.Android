#include <jni.h>
#include <sys/time.h>

#include "Controller.h"

int sDemoStopped = 0;
long sTimeStopped = 0;
long sTimeOffset = 0;
long sTimeOffsetInit = 0;

long long frames = 0;

//#ifdef __cplusplus
extern "C" {

static long getTime(void) {
    struct timeval now;
    gettimeofday(&now, NULL);
    return (long) (now.tv_sec * 1000 + now.tv_usec / 1000);
}

void throwJavaException(JNIEnv *env, const char *msg)
{
    // You can put your own exception here
    jclass c = env->FindClass("java/lang/RuntimeException");

    if (NULL == c)
    {
        //B plan: null pointer ...
        c = env->FindClass("java/lang/NullPointerException");
    }

    env->ThrowNew(c, msg);
}

// call to initialize the graphics state
void Java_edu_physicalsimulationtool_SimulationGLSurfaceViewRendered_nativeInit(JNIEnv *env) {
    LOG_INFO("INIT");
    try {
        Controller::getInstance()->initializeContextOpenGLES();
    } catch (const std::exception& e) {
        throwJavaException (env, e.what());
    }
}

void Java_edu_physicalsimulationtool_SimulationGLSurfaceViewRendered_nativeResize(JNIEnv *env, jobject thiz, jint _width, jint _height) {
    LOG_INFO("RESIZE");
    try {
        Controller::getInstance()->resizeScreen(_width, _height);
    } catch (const std::exception& e) {
        throwJavaException (env, e.what());
    }
}

// call to finalize the graphics state
void Java_edu_physicalsimulationtool_SimulationGLSurfaceViewRendered_nativeDone(JNIEnv *env) {
    LOG_INFO("DESTROY");
    try {
        Controller::destroy();
    } catch (const std::exception& e) {
        throwJavaException (env, e.what());
    }
}

void Java_edu_physicalsimulationtool_SimulationGLSurfaceView_nativeTogglePauseResume(JNIEnv *env) {
    LOG_INFO("PAUSE_RESUME");
    try {
        sDemoStopped = !sDemoStopped;
        if (sDemoStopped) {
            sDemoStopped = 1;
            sTimeStopped = getTime();
            Controller::getInstance()->stopSimulation();
        } else {
            sDemoStopped = 0;
            sTimeOffset -= getTime() - sTimeStopped;
            Controller::getInstance()->startSimulation();
        }
    } catch (const std::exception& e) {
        throwJavaException (env, e.what());
    }
}

void Java_edu_physicalsimulationtool_SimulationGLSurfaceView_nativePause(JNIEnv *env) {
    LOG_INFO("PAUSE");
    try {
        sDemoStopped = 1;
        sTimeStopped = getTime();

        Controller::getInstance()->stopSimulation();
    } catch (const std::exception& e) {
        throwJavaException (env, e.what());
    }
}

void Java_edu_physicalsimulationtool_SimulationGLSurfaceView_nativeResume(JNIEnv *env) {
    LOG_INFO("RESUME");
    try {
        sDemoStopped = 0;
        sTimeOffset -= getTime() - sTimeStopped;

        Controller::getInstance()->startSimulation();
    } catch (const std::exception& e) {
        throwJavaException (env, e.what());
    }
}

// call to render the next GL frame
void Java_edu_physicalsimulationtool_SimulationGLSurfaceViewRendered_nativeRender(JNIEnv *env) {
//    LOG_INFO("RENDER");
    try {
        float _duration = 0.03f;
        Controller::getInstance()->updateInformation(_duration);
        Controller::getInstance()->draw();
    } catch (const std::exception& e) {
        throwJavaException (env, e.what());
    }
}

void Java_edu_physicalsimulationtool_SimulationActivity_generateRandonSimulation(JNIEnv *env, jobject obj, jint _numberObjects) {
    LOG_INFO("GENERATE_SIMULATION");
    try {
        Controller::getInstance()->generateRandonSimulation(_numberObjects);
        Controller::getInstance()->startSimulation();
    } catch (const std::exception& e) {
        throwJavaException (env, e.what());
    }
}

void Java_edu_physicalsimulationtool_SimulationActivity_cleanSimulation(JNIEnv *env) {
    try {
        LOG_INFO("CLEAN_SIMULATION01");
        Controller::getInstance()->stopSimulation();
        LOG_INFO("CLEAN_SIMULATION02");
        Controller::getInstance()->clearSimularion();
    } catch (const std::exception& e) {
        throwJavaException (env, e.what());
    }
}

}
//#endif
