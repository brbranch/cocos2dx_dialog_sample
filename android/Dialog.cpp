//
//  Dialog.cpp
//
//  Created by Kazuki Oda on 2014/08/17.
//
//

#include "Dialog.h"
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include "cocos2d.h"

#define JNICLASSNAME "jp/brbranch/lib/MyActivity"
#define ANDROID_SHOW_ALERT_DIALOG "showAlertDialog"

using namespace MyExt;
using namespace cocos2d;
static MessageBoxCallback* sMessageBoxCallback = NULL;

void NativeLauncher::openMessageDialog(const MessageBox &msgBox , MessageBoxCallback* callback){
	if(sMessageBoxCallback != callback){
		if(sMessageBoxCallback != NULL){
			delete sMessageBoxCallback;
			sMessageBoxCallback = NULL;
		}
		sMessageBoxCallback = callback;
	}
	JniMethodInfo methodInfo;
	if(JniHelper::getStaticMethodInfo(methodInfo , JNICLASSNAME , ANDROID_SHOW_ALERT_DIALOG, "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V")){
		jstring title = methodInfo.env->NewStringUTF(msgBox.title);
		jstring message = methodInfo.env->NewStringUTF(msgBox.message);
		jstring okButton = methodInfo.env->NewStringUTF(msgBox.okButton);
		jstring cancelButton = methodInfo.env->NewStringUTF(msgBox.cancelButton);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID , methodInfo.methodID , title , message , okButton , cancelButton);
		methodInfo.env->DeleteLocalRef(title);
		methodInfo.env->DeleteLocalRef(message);
		methodInfo.env->DeleteLocalRef(okButton);
		methodInfo.env->DeleteLocalRef(cancelButton);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}
}

#ifdef __cplusplus
extern "C"{
#endif

JNIEXPORT void JNICALL Java_jp_brbranch_lib_Cocos2dxMyActivity_onMessageBoxResult(JNIEnv* env , jobject obj , jint jNum){
	int num = jNum;
	if(sMessageBoxCallback != NULL){
		sMessageBoxCallback->onResult(static_cast<messageBoxResultType>(num));
		delete sMessageBoxCallback;
		sMessageBoxCallback = NULL;
	}
	return;
}

#ifdef __cplusplus
}
#endif
