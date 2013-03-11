#include <jni.h>
#include <sys/time.h>
#include <time.h>

#include "Controller.h"
#include "log.h"

int sDemoStopped = 0;
long sTimeStopped = 0;
long sTimeOffset = 0;
long sTimeOffsetInit = 0;

long long frames = 0;

#ifdef __cplusplus
extern "C" {

static long getTime(void)
{
    struct timeval now;
    gettimeofday(&now, NULL);
    return (long)(now.tv_sec*1000 + now.tv_usec/1000);
}

// call to initialize the graphics state
void Java_edu_physicalSimulationTool_SimulationGLSurfaceViewRendered_nativeInit(JNIEnv* env)
{
	LOG_INFO("INIT");
	Controller::getInstance()->initializeContextOpenGLES();
}

void Java_edu_physicalSimulationTool_SimulationGLSurfaceViewRendered_nativeResize(JNIEnv* env, jobject  thiz, jint _width, jint _height)
{
	LOG_INFO("RESIZE");
    Controller::getInstance()->resizeScreen(_width, _height);
}

// call to finalize the graphics state
void Java_edu_physicalSimulationTool_SimulationGLSurfaceViewRendered_nativeDone(JNIEnv* env)
{
	LOG_INFO("DESTROY");
	Controller::destroy();
}

void Java_edu_physicalSimulationTool_SimulationGLSurfaceView_nativeTogglePauseResume(JNIEnv* env)
{
	LOG_INFO("PAUSE_RESUME");
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
}

void Java_edu_physicalSimulationTool_SimulationGLSurfaceView_nativePause(JNIEnv* env)
{
	LOG_INFO("PAUSE");
    sDemoStopped = 1;
    sTimeStopped = getTime();

    Controller::getInstance()->stopSimulation();
}

void Java_edu_physicalSimulationTool_SimulationGLSurfaceView_nativeResume(JNIEnv* env)
{
	LOG_INFO("RESUME");
	sDemoStopped = 0;
	sTimeOffset -= getTime() - sTimeStopped;

	Controller::getInstance()->startSimulation();
}

// call to render the next GL frame
void Java_edu_physicalSimulationTool_SimulationGLSurfaceViewRendered_nativeRender(JNIEnv* env)
{
//	LOG_INFO("RENDER");
	long _duraction = 0.03f;
	Controller::getInstance()->updateInformation(_duraction);
	Controller::getInstance()->draw();
}

void Java_edu_physicalSimulationTool_CallNativeController_generateRandonSimulation(JNIEnv* env, jobject obj, jint _numberObjects)
{
	LOG_INFO("GENERATE_SIMULATION");
	Controller::getInstance()->generateRandonSimulation(_numberObjects);
	Controller::getInstance()->startSimulation();
}

void Java_edu_physicalSimulationTool_CallNativeController_cleanSimulation(JNIEnv* env)
{
	LOG_INFO("CLEAN_SIMULATION01");
	Controller::getInstance()->stopSimulation();
	LOG_INFO("CLEAN_SIMULATION02");
	Controller::getInstance()->clearSimularion();
}

}
#endif
