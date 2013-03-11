package edu.physicalSimulationTool;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLSurfaceView;

public class SimulationGLSurfaceViewRendered implements GLSurfaceView.Renderer {
	
	public void onSurfaceCreated(GL10 gl, EGLConfig config) {
		this.nativeInit();
	}

	public void onSurfaceChanged(GL10 gl, int w, int h) {
		this.nativeResize(w, h);
	}

	public void onDrawFrame(GL10 gl) {
		this.nativeRender();
	}
	
	public native void nativeInit();

	public native void nativeResize(int w, int h);

	public native void nativeRender();

	public native void nativeDone();

}
