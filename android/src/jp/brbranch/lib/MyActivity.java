package jp.brbranch.lib;


import org.cocos2dx.lib.Cocos2dxActivity;

import android.app.AlertDialog;
import android.app.Dialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup.LayoutParams;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;

abstract public class MyActivity extends Cocos2dxActivity {
	static Cocos2dxMyActivity my;

	private static native void onMessageBoxResult(final int num);
	
    protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);	
		my = this;
	}

    public static void showAlertDialog(final String title , final String message , final String okButton , final String cancelButton){
    	my.runOnUiThread(new Runnable(){
    		@Override
    		public void run(){
    			 new AlertDialog.Builder(Cocos2dxActivity.getContext())
    		        .setTitle(title)
    		        .setMessage(message)
    		        .setPositiveButton(okButton,
    		            new DialogInterface.OnClickListener() {
    		                public void onClick(DialogInterface dialog,
    		                    int whichButton) {
    		                	Cocos2dxMyActivity.onMessageBoxResult(1);
    		                }
    		            })
    		        .setNegativeButton(cancelButton, 
    		        	new DialogInterface.OnClickListener() {
    						@Override
    						public void onClick(DialogInterface dialog, int which) {
    							Cocos2dxMyActivity.onMessageBoxResult(2);
    						}
    					})
    		        .show();
    		}
    	});
    }
}
