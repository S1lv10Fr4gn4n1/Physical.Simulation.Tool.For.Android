package edu.physicalsimulationtool;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.view.MotionEvent;

public class SimulationGLSurfaceView extends GLSurfaceView {
	private SimulationGLSurfaceViewRendered mRenderer;
	
	public SimulationGLSurfaceView(Context context) {
		super(context);
		setEGLContextClientVersion(2);
		this.mRenderer = new SimulationGLSurfaceViewRendered();
		setRenderer(this.mRenderer);
	}

	public boolean onTouchEvent(final MotionEvent event) {
		if (event.getAction() == MotionEvent.ACTION_DOWN) {
			this.nativeTogglePauseResume();
		}
		return true;
	}

	@Override
	public void onPause() {
		super.onPause();
		this.nativePause();
	}

	@Override
	public void onResume() {
		super.onResume();
		this.nativeResume();
	}

	public native void nativePause();

	public native void nativeResume();

	public native void nativeTogglePauseResume();
}