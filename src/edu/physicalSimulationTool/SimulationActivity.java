package edu.physicalSimulationTool;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.text.InputFilter;
import android.text.method.DigitsKeyListener;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.EditText;

public class SimulationActivity extends Activity {
	private GLSurfaceView mGLView;

	private CallNativeController callNativeController;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		this.mGLView = new SimulationGLSurfaceView(this);
		setContentView(this.mGLView);
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		switch (item.getItemId()) {
		case R.id.generate_randon_simulation:
			this.dialogTellNumberObjectGenerateSimulation();
			return true;

		case R.id.clean_simulation:
			this.getCallNativeController().cleanSimulation();
			return true;

		default:
			return super.onOptionsItemSelected(item);
		}
	}

	public void dialogTellNumberObjectGenerateSimulation() {
		AlertDialog.Builder alert = new AlertDialog.Builder(this);

		// Set an EditText view to get user input
		final EditText input = new EditText(this);
		input.setFilters(new InputFilter[] {
				// Maximum 2 characters.
				new InputFilter.LengthFilter(2),
				// Digits only.
				DigitsKeyListener.getInstance(), // Not strictly needed, IMHO.
		});

		// Digits only & use numeric soft-keyboard.
		input.setKeyListener(DigitsKeyListener.getInstance());

		alert.setView(input);
		alert.setTitle(R.string.msg_tell_number_objects);

		alert.setPositiveButton(R.string.btn_ok,
				new DialogInterface.OnClickListener() {
					public void onClick(DialogInterface dialog, int whichButton) {
						String number = input.getText().toString();
						if (number == null || number.trim().isEmpty()) {
							number = "0";
						}
						final int numberObjects = Integer.parseInt(number);
						SimulationActivity.this.getCallNativeController().generateRandonSimulation(numberObjects);
					}
				});
		alert.show();
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.simulation_menu, menu);
		return true;
	}

	@Override
	protected void onPause() {
		super.onPause();
		this.mGLView.onPause();
	}

	@Override
	protected void onResume() {
		super.onResume();
		this.mGLView.onResume();
	}

	static {
		System.loadLibrary("physicalSimulationTool");
	}

	private CallNativeController getCallNativeController() {
		if (this.callNativeController == null) {
			this.callNativeController = new CallNativeController();
		}
		return this.callNativeController;
	}

}
