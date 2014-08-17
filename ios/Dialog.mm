//
//  Dialog.mm
//
//  Created by Kazuki Oda on 2014/08/17.
//
//

#include "Dialog.h"
#import "Dialog_objc.h"
using namespace MyExt;

void NativeLauncher::openMessageDialog(const MessageBox &msgBox, MessageBoxCallback *callback){
	
	NSString* title = [NSString stringWithUTF8String:msgBox.title];
	NSString* message = [NSString stringWithUTF8String:msgBox.message];
	NSString* okButton = [NSString stringWithUTF8String:msgBox.okButton];
	NSString* cancelButton = [NSString stringWithUTF8String:msgBox.cancelButton];
	NativeLauncher_objc *controller = [NativeLauncher_objc alloc];
	[controller showMessage : title
					message : message
					buttonOK: okButton
				buttonCancel: cancelButton
				 msgCallback: callback];
	
}