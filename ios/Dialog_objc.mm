//
//  Dialog_objc.mm
//
//  Created by Kazuki Oda on 2014/08/17.
//
//

#import "Dialog_objc.h"
#import "cocos2d.h"

static MessageBoxCallback* sMessageCallback = NULL;

@implementation NativeLauncher_objc
- (void)showMessage:(NSString*)title
			message:(NSString*)message
		   buttonOK:(NSString*)buttonOK
	   buttonCancel:(NSString*)buttonCancel
msgCallback:(MessageBoxCallback *)msgCallback{
	
	if(msgCallback != sMessageCallback){
		if(sMessageCallback != NULL){
			delete sMessageCallback;
			sMessageCallback = NULL;
		}
		sMessageCallback = msgCallback;
	}
	
	UIAlertView* alert = [[UIAlertView alloc]
						  initWithTitle:title
						  message:message
						  delegate:self
						  cancelButtonTitle:buttonCancel
						  otherButtonTitles:buttonOK , nil];
	[alert show];
	[alert autorelease];
}


- (void)alertView:(UIAlertView*)alertView
clickedButtonAtIndex:(NSInteger)buttonIndex{
	int okCancel = ALERTBUTTON_CANCEL;
	switch (buttonIndex) {
		case 0:
			okCancel = ALERTBUTTON_CANCEL;
			break;
		case 1:
			okCancel = ALERTBUTTON_OK;
			break;
		default:
			break;
	}
	if(sMessageCallback != NULL){
		sMessageCallback->onResult(static_cast<messageBoxResultType>(okCancel));
		delete sMessageCallback;
		sMessageCallback = NULL;
	}
	[self release];
}

-(void)dealloc{
	[super dealloc];
}

@end
