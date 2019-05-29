//---------------------------------------------------------------------------

#ifndef GmSmapleProgramH
#define GmSmapleProgramH
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
	TButton *OpenBotton;
	TBitBtn *BitBtn1;
	TButton *Ch1Button;
	TButton *Ch2Button;
	TButton *Ch3Button;
	TButton *Ch4Button;
	TButton *Ch5Button;
	TComboBox *ComboBox1;
	TCheckBox *CheckBox1;
	TEdit *TemperatureEdit;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Ch1VoltpEdit;
	TEdit *Ch2VoltpEdit;
	TEdit *Ch3VoltpEdit;
	TEdit *Ch4VoltpEdit;
	TEdit *Ch5VoltpEdit;
	TEdit *Ch1VoltnEdit;
	TEdit *Ch2VoltnEdit;
	TEdit *Ch3VoltnEdit;
	TEdit *Ch4VoltnEdit;
	TEdit *Ch5VoltnEdit;
	TEdit *Ch1ResistanceEdit;
	TEdit *Ch2ResistanceEdit;
	TEdit *Ch3ResistanceEdit;
	TEdit *Ch4ResistanceEdit;
	TEdit *Ch5ResistanceEdit;
	TRadioGroup *SelectTemperatureChRadioGroup;
	TPanel *Panel1;
	TPanel *Panel2;
	TButton *CloseChButton;
	TButton *OpenAllButton;
	TGroupBox *GroupBox1;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	TRadioButton *RadioButton4;
	TRadioButton *RadioButton5;
	TCheckBox *ReverseCheckBox;
	TCheckBox *CurrentCheckBox;
	TButton *DisplayVoltButton;
	void __fastcall OpenBottonClick(TObject *Sender);
	void __fastcall CloseChButtonClick(TObject *Sender);
	void __fastcall OpenAllButtonClick(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ReverseCheckBoxClick(TObject *Sender);
	void __fastcall CurrentCheckBoxClick(TObject *Sender);
	void __fastcall DisplayVoltButtonClick(TObject *Sender);
	void __fastcall Ch1ButtonClick(TObject *Sender);
	void __fastcall Ch2ButtonClick(TObject *Sender);
	void __fastcall Ch3ButtonClick(TObject *Sender);
	void __fastcall Ch4ButtonClick(TObject *Sender);
	void __fastcall Ch5ButtonClick(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall SelectTemperatureChRadioGroupClick(TObject *Sender);
private:	// ユーザー宣言

public:		// ユーザー宣言
	__fastcall TForm1(TComponent* Owner);
	TEdit *ChEdit[5][3]; //[チャンネル][volt+,volt-,resistance]
	TRadioButton *ChannelRadioButton[5];
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 