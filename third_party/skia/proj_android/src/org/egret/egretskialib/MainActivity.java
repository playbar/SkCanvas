package org.egret.egretskialib;


import android.app.Activity;
import android.os.Bundle;
import android.widget.FrameLayout;

/**
 * An example full-screen activity that shows and hides the system UI (i.e.
 * status bar and navigation/system bar) with user interaction.
 * 
 * @see SystemUiHider
 */
public class MainActivity extends Activity {
	FrameLayout layout;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		layout = new FrameLayout(this);
		//layout.addView(new GL2JNIView(this));
	
		setContentView(new SkiaTestView(this));
	}
	
	static{
		System.loadLibrary("egretskialib");
	}
}
