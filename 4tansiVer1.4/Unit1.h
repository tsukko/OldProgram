//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include <VclTee.TeeGDIPlus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE 管理のコンポーネント
        TBitBtn *BitBtn1;
        TTimer *Timer1;
        TSaveDialog *SaveDialog1;
        TPanel *Panel1;
        TChart *MeasureChart;
        TLabel *TemLabel;
        TLabel *PLabel;
        TLabel *TemperatureLabel;
        TLabel *PointLabel;
        TGroupBox *ConfigGroupBox;
        TGroupBox *ChChoiceGroupBox;
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        TCheckBox *CheckBox4;
        TCheckBox *CheckBox3;
        TCheckBox *CheckBox5;
        TGroupBox *Ch1GroupBox;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *Ch1SampleNameEdit;
        TGroupBox *Ch2GroupBox;
        TLabel *Label4;
        TLabel *Label5;
        TEdit *Ch2SampleNameEdit;
        TGroupBox *Ch3GroupBox;
        TLabel *Label7;
        TLabel *Label8;
        TEdit *Ch3SampleNameEdit;
        TGroupBox *Ch4GroupBox;
        TLabel *Label10;
        TLabel *Label11;
        TEdit *Ch4SampleNameEdit;
        TGroupBox *Ch5GroupBox;
        TLabel *Label13;
        TLabel *Label14;
        TEdit *Ch5SampleNameEdit;
        TGroupBox *FileNameGroupBox;
        TEdit *FileNameEdit;
        TButton *FNChangeButton;
        TButton *MeasureButton;
        TButton *StopButton;
        TButton *UpButton;
        TButton *BoardOpenButton;
        TLabel *Label16;
        TLabel *Label17;
        TComboBox *CurrentExponentComboBox1;
        TComboBox *CurrentExponentComboBox2;
        TComboBox *CurrentExponentComboBox3;
        TComboBox *CurrentExponentComboBox4;
        TComboBox *CurrentExponentComboBox5;
        TPointSeries *Series1;
        TPointSeries *Series2;
        TPointSeries *Series3;
        TPointSeries *Series4;
        TPointSeries *Series5;
        TStatusBar *StatusBar1;
        TGroupBox *ConditionGroupBox;
        TEdit *TempRate1Edit;
        TEdit *SecondRateEdit;
        TButton *ConditionButton;
        TLabel *Label3;
        TLabel *Label6;
        TEdit *FirstTempEdit;
        TLabel *Label9;
        TEdit *TempEdit;
        TLabel *Label12;
        TLabel *Label15;
        TEdit *TempRate2Edit;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TRadioButton *RadioButton4;
        TRadioButton *RadioButton5;
        TRadioButton *RadioButton3;
        TLabel *Label19;
        TLabel *Label20;
        TLabel *Label21;
        TLabel *Label22;
        TLabel *Label23;
        TEdit *CurrentMantissaEdit5;
        TLabel *Label24;
        TEdit *CurrentMantissaEdit1;
        TEdit *CurrentMantissaEdit2;
        TEdit *CurrentMantissaEdit3;
        TEdit *CurrentMantissaEdit4;
        TLabel *Label18;
        TComboBox *ResistanceMantissaComboBox;
        TComboBox *ResistanceExponenComboBox;
        TComboBox *TemperatureComboBox;
        TLabel *Label25;
        TLabel *Label26;
        TLabel *Label27;
        TLabel *Label28;
        void __fastcall MeasureButtonClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall FNChangeButtonClick(TObject *Sender);
        void __fastcall TemperatureComboBoxChange(TObject *Sender);
        void __fastcall ResistanceExponenComboBoxChange(TObject *Sender);
        void __fastcall StopButtonClick(TObject *Sender);
        void __fastcall UpButtonClick(TObject *Sender);
        void __fastcall BoardOpenButtonClick(TObject *Sender);
        void __fastcall MeasureChartMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ConditionButtonClick(TObject *Sender);
        void __fastcall RadioButton1Click(TObject *Sender);
        void __fastcall RadioButton2Click(TObject *Sender);
        void __fastcall RadioButton3Click(TObject *Sender);
        void __fastcall RadioButton4Click(TObject *Sender);
        void __fastcall RadioButton5Click(TObject *Sender);
        void __fastcall ResistanceMantissaComboBoxChange(TObject *Sender);
private:	// ユーザー宣言
        TEdit *SampleNameEdit[5];
        TCheckBox *MeasureChCheckBox[5];
        TRadioButton *MeasureTempRadioButton[5];
        TComboBox *CurrentExponentComboBox[5];
        TEdit *CurrentMantissaEdit[5];
        TGroupBox *ChGroupBox[5];
public:		// ユーザー宣言
        __fastcall TForm1(TComponent* Owner);
        void __fastcall FileName();
        int __fastcall DTemperatureChannel();
        void __fastcall sokuteimae();
		void __fastcall sokutei();
		void ChangeFile_up(AnsiString FileName);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
