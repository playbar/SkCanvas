/*
 * Copyright (C) 2007 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.android.gl2jni;

import android.app.Activity;
import android.content.res.AssetManager;
import android.os.Bundle;
import android.util.Log;
import android.view.WindowManager;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;


public class GL2JNIActivity extends Activity {

    GL2JNIView mView;

    @Override protected void onCreate(Bundle icicle) {
        super.onCreate(icicle);
        movePng();
        JniShell.setFilesDir(getFilesDir().getAbsolutePath());
        mView = new GL2JNIView(getApplication());
	setContentView(mView);
    }

    @Override protected void onPause() {
        super.onPause();
        mView.onPause();
    }

    @Override protected void onResume() {
        super.onResume();
        mView.onResume();
    }
    String imgName = "egret_icon.png";
    boolean movePng(){
    	AssetManager asmanager = this.getAssets();
    	try {
			InputStream is = asmanager.open(imgName);
			FileOutputStream fout = openFileOutput(imgName, MODE_PRIVATE);
			byte buffer[] = new byte[1024*10];
			int size = 0;
			while(true){
				size = is.read(buffer,0,buffer.length);
				if(size < 1){
					break;
				}
				fout.write(buffer, 0, size);
			}
			fout.flush();
			fout.close();
			is.close();
			
			File file = new File(getFilesDir()+"/"+imgName);
			
			boolean isFileExists = file.exists();
			is = null;
			return isFileExists;
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    	return false;
    }
}
