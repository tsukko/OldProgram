//---------------------------------------------------------------------------

#ifndef GmDataConversionH
#define GmDataConversionH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <vector>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:    // IDE 管理のコンポーネント
    TStatusBar *StatusBar1;
    TTabControl *TabControl1;
    TCheckBox *CheckBox1;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall TabControl1Change(TObject *Sender);
private:    // ユーザー宣言
    void __fastcall ReceiveDropFiles(TWMDropFiles Message);
    BEGIN_MESSAGE_MAP
    MESSAGE_HANDLER(WM_DROPFILES, TWMDropFiles, ReceiveDropFiles)
    END_MESSAGE_MAP(TForm)
public:        // ユーザー宣言
    __fastcall TForm1(TComponent* Owner);
     std::vector< std::vector < std::vector < float > > > data;
	 std::vector< std::vector < float > > resis;
	 std::vector< std::vector < AnsiString > > SQUIDData;
     void __fastcall ChangeFile_up(AnsiString FileName);
     void __fastcall ChangeFile_RAW(AnsiString FileName);
//    void __fastcall TForm1::functionGM(AnsiString File);
    void __fastcall ChangeFileSQUID_TM(AnsiString FileName);
    void __fastcall ChangeFileSQUID_HM(AnsiString FileName);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
