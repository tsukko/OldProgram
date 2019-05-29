//---------------------------------------------------------------------------

#ifndef homework1H
#define homework1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE 管理のコンポーネント
        TButton *B1;
        TBitBtn *BitBtn1;
        TGroupBox *GroupBox1;
        TEdit *Edit1;
        TEdit *Edit2;
        TLabel *Label1;
        TEdit *Edit3;
        TLabel *Label2;
        TButton *Button1;
        TRadioGroup *RadioGroup1;
        TGroupBox *GroupBox2;
        TEdit *Edit4;
        TEdit *Edit5;
        TEdit *Edit6;
        TEdit *Edit7;
        TEdit *Edit8;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TRadioGroup *RadioGroup2;
        TButton *Button2;
        TGroupBox *GroupBox4;
        TButton *B2;
        TEdit *E2;
        TRadioGroup *RadioGroup3;
        TEdit *E1;
        void __fastcall B1Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall B2Click(TObject *Sender);
        void __fastcall E1Change(TObject *Sender);
        void __fastcall RadioGroup1Click(TObject *Sender);
        void __fastcall RadioGroup2Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
