//
//  Dialog_objc.h
//
//  Created by Kazuki Oda on 2014/08/17.
//
//

#import <Foundation/Foundation.h>
#include "Dialog.h"
using namespace MyExt;
@interface Dialog_objc : NSObject{
	
}
-(void)showMessage:(NSString*)title
		   message:(NSString*)message
		  buttonOK:(NSString*)buttonOK
	  buttonCancel:(NSString*)buttonCancel
		msgCallback:(MessageBoxCallback*)msgCallback;

- (void)alertView:(UIAlertView*)alertView
clickedButtonAtIndex:(NSInteger)buttonIndex;
@end
