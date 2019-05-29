//---------------------------------------------------------------------------

#ifndef homework2H
#define homework2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Menus.hpp>
#include <ActnList.hpp>
#include <Dialogs.hpp>
#include <StdActns.hpp>
#include <System.Actions.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE 管理のコンポーネント
        TMemo *Memo1;
        TButton *ForButton;
        TButton *WhileButton;
        TButton *ClearButton;
        TButton *SaveButton;
        TButton *LoadButton;
        TBitBtn *BitBtn;
        TPopupMenu *PopupMenu1;
        TMenuItem *Save1;
        TMenuItem *Load1;
        TMenuItem *N1;
        TMenuItem *Del1;
        TActionList *ActionList1;
        TAction *save;
        TAction *load;
        TAction *clear;
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
        TEditCopy *EditCopy1;
        TEditCut *EditCut1;
        TMenuItem *Copy1;
        TMenuItem *Cut1;
        TEditPaste *EditPaste1;
        TMenuItem *Paste1;
        TEditDelete *EditDelete1;
        TMenuItem *Del2;
        TMenuItem *N3;
        TMenuItem *End;
        void __fastcall ForButtonClick(TObject *Sender);
        void __fastcall WhileButtonClick(TObject *Sender);
        void __fastcall saveExecute(TObject *Sender);
        void __fastcall loadExecute(TObject *Sender);
        void __fastcall clearExecute(TObject *Sender);
        void __fastcall EndClick(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
