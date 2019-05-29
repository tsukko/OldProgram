//---------------------------------------------------------------------------

#ifndef FourierSeriesH
#define FourierSeriesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE 管理のコンポーネント
    TEdit *Edit1;
    TEdit *Edit2;
    TButton *Button1;
    TButton *Button2;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TCheckBox *CheckBox1;
    TChart *Chart1;
    TFastLineSeries *Series1;
    TEdit *Edit3;
    TLabel *Label4;
    TEdit *Edit4;
    TEdit *Edit5;
    TCheckBox *CheckBox2;
    TEdit *Edit6;
    TEdit *Edit7;
    TEdit *Edit8;
    TCheckBox *CheckBox3;
    TEdit *Edit9;
    TEdit *Edit10;
    TEdit *Edit11;
    TCheckBox *CheckBox4;
    TEdit *Edit12;
    TEdit *Edit13;
    TEdit *Edit14;
    TCheckBox *CheckBox5;
    TEdit *Edit15;
    TEdit *Edit16;
    TEdit *Edit17;
    TCheckBox *CheckBox6;
    TEdit *Edit18;
    TEdit *Edit19;
    TEdit *Edit20;
    TCheckBox *CheckBox7;
    TEdit *Edit21;
    TEdit *Edit22;
    TEdit *Edit23;
    TCheckBox *CheckBox8;
    TEdit *Edit24;
    TButton *Button3;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *Label7;
    TLabel *Label8;
    TLabel *Label9;
    TLabel *Label10;
    TLabel *Label12;
    TLabel *Label11;
    TLabel *Label13;
    TLabel *Label14;
    TLabel *Label15;
    TLabel *Label16;
    TEdit *Edit25;
    TEdit *Edit26;
    TEdit *Edit27;
    TEdit *Edit28;
    TEdit *Edit29;
    TEdit *Edit30;
    TEdit *Edit31;
    TEdit *Edit32;
    TEdit *Edit33;
    TEdit *Edit34;
    TEdit *Edit35;
    TEdit *Edit36;
    TButton *Button4;
    TButton *Button5;
    TFastLineSeries *Series2;
    TCheckBox *CheckBox9;
    TCheckBox *CheckBox10;
    TCheckBox *CheckBox11;
    TCheckBox *CheckBox12;
    TCheckBox *CheckBox13;
    TFastLineSeries *Series3;
    TCheckBox *CheckBox14;
    TPanel *Panel1;
    TButton *Button6;
    TButton *Button7;
    TButton *Button8;
    TLabel *Label17;
    TEdit *Edit37;
    TButton *Button9;
    TEdit *Edit38;
	TLabel *Label18;
	TEdit *Edit39;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall CheckBox1Click(TObject *Sender);
    void __fastcall CheckBox2Click(TObject *Sender);
    void __fastcall CheckBox3Click(TObject *Sender);
    void __fastcall CheckBox4Click(TObject *Sender);
    void __fastcall CheckBox5Click(TObject *Sender);
    void __fastcall CheckBox6Click(TObject *Sender);
    void __fastcall CheckBox7Click(TObject *Sender);
    void __fastcall CheckBox8Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
    void __fastcall Button5Click(TObject *Sender);
    void __fastcall Button6Click(TObject *Sender);
    void __fastcall Button7Click(TObject *Sender);
    void __fastcall Button8Click(TObject *Sender);
    void __fastcall CheckBox9Click(TObject *Sender);
    void __fastcall CheckBox10Click(TObject *Sender);
    void __fastcall CheckBox11Click(TObject *Sender);
    void __fastcall CheckBox12Click(TObject *Sender);
	void __fastcall CheckBox13Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
