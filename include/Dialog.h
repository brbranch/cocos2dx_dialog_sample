//
//  Dialog.h
//
//  Created by Kazuki Oda on 2014/08/17.
//
//

#ifndef Dialog_h
#define Dialog_h
#define ALERTBUTTON_OK 1
#define ALERTBUTTON_CANCEL 2

namespace MyExt{
	typedef struct _msgBox{
		const char* title;
		const char* message;
		const char* okButton;
		const char* cancelButton;
	}MessageBox;

	typedef enum _msgBoxResultType{
		kMessageBoxResultOk = ALERTBUTTON_OK,
		kMessageBoxResultCancel = ALERTBUTTON_CANCEL,
	}messageBoxResultType;

	class MessageBoxCallback{
	public:
		virtual void onResult(messageBoxResultType type) = 0;
		virtual ~MessageBoxCallback(){};
	};

	class Dialog{
	public:
		static void openMessageDialog(const MessageBox &msgBox , MessageBoxCallback* callback);
	};
}


#endif
