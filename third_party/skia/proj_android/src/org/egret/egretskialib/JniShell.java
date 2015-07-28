/*
 * @author jkd2972
 *
 * JniShell.java
 * ионГ11:14:17 2015-7-25
 */
package org.egret.egretskialib;

import android.graphics.Canvas;
public class JniShell {

	public static native void nativeInit(int width,int height);
	public static native void nativeMainLoop();
	public static native void nativePauseApp();
	public static native void nativeResumeApp();
	
	public static native void drawPng(Canvas canvas);
}
