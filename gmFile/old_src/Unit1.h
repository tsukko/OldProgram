//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE 管理のコンポーネント
        TStatusBar *StatusBar1;
        TTabControl *TabControl1;
        TCheckBox *CheckBox1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall TabControl1Change(TObject *Sender);
private:	// ユーザー宣言
/////////////////////////////////////////////////////////////////////////////
  //Windowsからのメッセージ WM_DROPFILES を ReceiveDropFiles で受け取るようにする
  void __fastcall ReceiveDropFiles(TWMDropFiles Message);
  BEGIN_MESSAGE_MAP
  MESSAGE_HANDLER(WM_DROPFILES, TWMDropFiles, ReceiveDropFiles)
  END_MESSAGE_MAP(TForm)
/////////////////////////////////////////////////////////////////////////////
public:		// ユーザー宣言
        __fastcall TForm1(TComponent* Owner);
     vector< vector < vector < float > > > data ;
     vector< vector < float > > resis ;
     vector< vector < AnsiString > > SQUIDData ;
     void __fastcall TForm1::ChangeFile_up(AnsiString FileName);
     void __fastcall TForm1::ChangeFile_RAW(AnsiString FileName);
 //    void __fastcall TForm1::functionGM(AnsiString File);
void __fastcall TForm1::ChangeFileSQUID_TM(AnsiString FileName);
void __fastcall TForm1::ChangeFileSQUID_HM(AnsiString FileName);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
