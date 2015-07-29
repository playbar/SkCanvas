/*
 * @author jkd2972
 *
 * SkiaTestView.java
 * обнГ5:10:25 2015-7-27
 */
package org.egret.egretskialib;

import android.content.Context;
import android.graphics.Canvas;
import android.view.View;

public class SkiaTestView extends View {
	public SkiaTestView(Context context) {
		super(context);
		// TODO Auto-generated constructor stub
	}


	public static final String TAG="SkiaTestView";
	
	
	protected void onDraw(Canvas canvas){
		super.onDraw(canvas);
		canvas.drawColor(0xff00ff00);
		EgretContext.logDebug(TAG, "onDraw:"+canvas);
		//canvas.drawARGB(255, 255, 0, 0);
		JniShell.drawPng(canvas);
	
	}

}
