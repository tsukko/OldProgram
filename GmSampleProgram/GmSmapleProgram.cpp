//GPIB:02･･･Model2182	チャンネルを変える装置
//GPIB:04･･･Model220 programmable ～～	電流を流す装置
//GPIB:07･･･Model7001	電圧(抵抗)を表示する装置
//---------------------------------------------------------------------------

#include <vcl.h>
#include "temp.h"
//#include "GM_GPIB.h"
#include <math.hpp>
#include "GmSmapleProgram.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

   double VolPlu,VolMinu,CurrentValue,Resistance;
   int n,t;//n:チャンネル番号、t:1は電流流れてる、0は流れてない
   int TemperatureChannel;

//comboBoxで選んだ電流値を取る。一応、F0で電流をとめている。
char * current(int i){
   char * crnt;
   i=Form1->ComboBox1->ItemIndex;
   if(i==0){
      if(Form1->ReverseCheckBox->Checked)crnt="F0 I-1e-3 X";
      else crnt="F0 I1e-3 X";
      CurrentValue=1e-3;
   }
   if(i==1){
      if(Form1->ReverseCheckBox->Checked)crnt="F0 I-1e-4 X";
      else crnt="F0 I1e-4 X";
      CurrentValue=1e-4;
   }
   if(i==2){
      if(Form1->ReverseCheckBox->Checked)crnt="F0 I-1e-5 X";
      else crnt="F0 I1e-5 X";
      CurrentValue=1e-5;
   }
   if(i==3){
      if(Form1->ReverseCheckBox->Checked)crnt="F0 I-1e-6 X";
      else crnt="F0 I1e-6 X";
      CurrentValue=1e-6;
   }
   return crnt;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

//初期状態、温度計のチャンネルを選択してボードオープンするまで使えない
void __fastcall TForm1::FormCreate(TObject *Sender)
{
   ChEdit[0][0]=Ch1VoltpEdit;
   ChEdit[1][0]=Ch2VoltpEdit;
   ChEdit[2][0]=Ch3VoltpEdit;
   ChEdit[3][0]=Ch4VoltpEdit;
   ChEdit[4][0]=Ch5VoltpEdit;
   ChEdit[0][1]=Ch1VoltnEdit;
   ChEdit[1][1]=Ch2VoltnEdit;
   ChEdit[2][1]=Ch3VoltnEdit;
   ChEdit[3][1]=Ch4VoltnEdit;
   ChEdit[4][1]=Ch5VoltnEdit;
   ChEdit[0][2]=Ch1ResistanceEdit;
   ChEdit[1][2]=Ch2ResistanceEdit;
   ChEdit[2][2]=Ch3ResistanceEdit;
   ChEdit[3][2]=Ch4ResistanceEdit;
   ChEdit[4][2]=Ch5ResistanceEdit;
   ChannelRadioButton[0]=RadioButton1;
   ChannelRadioButton[1]=RadioButton2;
   ChannelRadioButton[2]=RadioButton3;
   ChannelRadioButton[3]=RadioButton4;
   ChannelRadioButton[4]=RadioButton5;


   OpenBotton->Enabled=false;
   Panel1->Enabled=false;
}
//---------------------------------------------------------------------------

//温度計に使うチャンネルを選択する。
void __fastcall TForm1::SelectTemperatureChRadioGroupClick(TObject *Sender)
{
   if(SelectTemperatureChRadioGroup->ItemIndex==-1){
      OpenBotton->Enabled=false;
   }
   else{
      OpenBotton->Enabled=true;
      TemperatureChannel=SelectTemperatureChRadioGroup->ItemIndex;
   }
}
//---------------------------------------------------------------------------

//GPIBのボードのオープン、クローズ
void __fastcall TForm1::OpenBottonClick(TObject *Sender)
{
   if(OpenBotton->Caption=="open"){
	  BoardOpen();

      BitBtn1->Enabled=false;
	  OpenBotton->Caption="close";    //ボード閉じるボタンにする。
      Panel1->Enabled=true;
      ComboBox1->ItemIndex=3;    //初期電流値1E-6
      current(3);
      resetboard();
   }
   else{
      CurrentOff();    //終了、まず電流とめる
      resetboard();    //次にGPIB:02,GPIB:07の初期化
      BoardClose();
      BitBtn1->Enabled=true;
      OpenBotton->Caption="open";
      Panel1->Enabled=false;
   }
}
//---------------------------------------------------------------------------

//チャンネルをクローズします。(繋げる)(GPIB:07)
void __fastcall TForm1::CloseChButtonClick(TObject *Sender)
{
   int n;
   for(int i=0;i<5;i++)if(ChannelRadioButton[i]->Checked)n=i+1;
   channel(n);
}
//---------------------------------------------------------------------------

//すべてのチャンネル閉じる(オープン）(GPIB:07)
void __fastcall TForm1::OpenAllButtonClick(TObject *Sender)
{
   OpenAll();
   for(int i=0;i<5;i++)ChannelRadioButton[i]->Checked=false;
}
//---------------------------------------------------------------------------

//電流値かえる。(変えるだけでまだ流さない)(GPIB:04)
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
   //もし電流流れてたら一旦、電流とめる、あとで流す
   if(CurrentCheckBox->State){
      CurrentOff();
   	t=1;
   }
   ChangeCurrent(current(ComboBox1->ItemIndex));
   if(n){
      CurrentOn();
      t=0;
   }
}
//---------------------------------------------------------------------------

//電流のon,off。(GPIB:04)
void __fastcall TForm1::CurrentCheckBoxClick(TObject *Sender)
{
   ChangeCurrent(current(ComboBox1->ItemIndex));
   if(CurrentCheckBox->State)CurrentOn();
   else CurrentOff();                          
}
//---------------------------------------------------------------------------

//反転ボタン押したら表示がかわる。(GPIB:04)
void __fastcall TForm1::ReverseCheckBoxClick(TObject *Sender)
{
   //もし電流流れてたら一旦、電流とめる、あとで流す
   if(CurrentCheckBox->State){
      CurrentOff();
      t=1;
   }
   ChangeCurrent(current(ComboBox1->ItemIndex));
   //電流流す
   if(n){
      CurrentOn();
      t=0;
   }
}
//---------------------------------------------------------------------------

//電圧値を表示する。(GPIB:02)
void __fastcall TForm1::DisplayVoltButtonClick(TObject *Sender)
{
   VoltDisplay();
   for(int i=0;i<5;i++){
      if(ChannelRadioButton[i]->Checked){
         if(ReverseCheckBox->Checked)ChEdit[i][1]->Text=szData;
         else ChEdit[i][0]->Text=szData;
      }
   }
/*
   if(RadioButton1->Checked){
      if(ReverseCheckBox->Checked)Ch1Edit2->Text=szData;
      else Ch1Edit->Text=szData;
   }
   if(RadioButton2->Checked){
      if(ReverseCheckBox->Checked)Ch2Edit2->Text=szData;
      else Ch2Edit->Text=szData;
   }
   if(RadioButton3->Checked){
      if(ReverseCheckBox->Checked)Ch3Edit2->Text=szData;
      else Ch3Edit->Text=szData;
   }
   if(RadioButton4->Checked){
      if(ReverseCheckBox->Checked)Ch4Edit2->Text=szData;
      else Ch4Edit->Text=szData;
   }
   if(RadioButton5->Checked){
      if(ReverseCheckBox->Checked)Ch5Edit2->Text=szData;
      else Ch5Edit->Text=szData;
   }
*/
}
//---------------------------------------------------------------------------

void getResistance(int SelectChannel)
{
   if(TemperatureChannel==0)ComboBox1->ItemIndex=2;

   ChannelRadioButton[SelectChannel]->Checked=true;
   CurrentOff();
   CloseChButton->Click();
   ReverseCheckBox->Checked=false;
   ChangeCurrent(current(ComboBox1->ItemIndex));
   CurrentOn();
   DisplayVoltButton->Click();
   VolPlu=atof(szData);
   CurrentOff();
   if(TemperatureChannel!=0){
      ReverseCheckBox->Checked=true;
      CurrentOn();
      DisplayVoltButton->Click();
      CurrentOff();
      VolMinu=atof(szData);
      Resistance=(VolPlu-VolMinu)/2/CurrentValue;
      ChEdit[SelectChannel][2]->Text=String(Resistance);
   }
   else if(TemperatureChannel==0){
      if(VolPlu<0 || VolPlu>1.704){
         MessageDlg("温度変換できん",mtError,TMsgDlgButtons() << mbOK, 0);
         return;
      }
      ChEdit[SelectChannel][1]->Text="Temperature";
      ChEdit[SelectChannel][2]->Text=String(temp(VolPlu));
   }

}
void __fastcall TForm1::Ch1ButtonClick(TObject *Sender)
{
   getResistance(0);
/*
   RadioButton1->Checked=true;
   CurrentOff();
   CloseChButton->Click();
   ReverseCheckBox->Checked=false;
   ChangeCurrent(current(ComboBox1->ItemIndex));
   CurrentOn();
   DisplayVoltButton->Click();
   VolPlu=atof(szData);
   CurrentOff();
   if(!CheckBox1->Checked){
      ReverseCheckBox->Checked=true;
      CurrentOn();
      DisplayVoltButton->Click();
      CurrentOff();
      VolMinu=atof(szData);
      Resistance=(VolPlu-VolMinu)/2/CurrentValue;
      Ch1Edit3->Text=String(Resistance);
   }
   else{
      if(VolPlu<0 || VolPlu>1.704){
         MessageDlg("温度変換できん",mtError,TMsgDlgButtons() << mbOK, 0);
         return;
      }
      TemperatureEdit->Text=String(temp(VolPlu));
   }
   */
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Ch2ButtonClick(TObject *Sender)
{
   RadioButton2->Checked=true;
   CurrentOff();
   CloseChButton->Click();
   ReverseCheckBox->Checked=false;
   ChangeCurrent(current(ComboBox1->ItemIndex));
   CurrentOn();
   DisplayVoltButton->Click();
   VolPlu=atof(szData);
   CurrentOff();
   if(!CheckBox1->Checked){
      ReverseCheckBox->Checked=true;
      CurrentOn();
      DisplayVoltButton->Click();
      CurrentOff();
      VolMinu=atof(szData);
      Resistance=(VolPlu-VolMinu)/2/CurrentValue;
      Ch2Edit3->Text=String(Resistance);
   }
   else{
      if(VolPlu<0 || VolPlu>1.704){
         MessageDlg("温度変換できん",mtError,TMsgDlgButtons() << mbOK, 0);
         return;
      }
      TemperatureEdit->Text=String(temp(VolPlu));
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Ch3ButtonClick(TObject *Sender)
{
   RadioButton3->Checked=true;
   CurrentOff();
   CloseChButton->Click();
   ReverseCheckBox->Checked=false;
   ChangeCurrent(current(ComboBox1->ItemIndex));
   CurrentOn();
   DisplayVoltButton->Click();
   VolPlu=atof(szData);
   CurrentOff();
   if(!CheckBox1->Checked){
      ReverseCheckBox->Checked=true;
      CurrentOn();
      DisplayVoltButton->Click();
      CurrentOff();
      VolMinu=atof(szData);
      Resistance=(VolPlu-VolMinu)/2/CurrentValue;
      Ch3Edit3->Text=String(Resistance);
   }
   else{
      if(VolPlu<0 || VolPlu>1.704){
         MessageDlg("温度変換できん",mtError,TMsgDlgButtons() << mbOK, 0);
         return;
      }
      TemperatureEdit->Text=String(temp(VolPlu));
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Ch4ButtonClick(TObject *Sender)
{
   RadioButton4->Checked=true;
   CurrentOff();
   CloseChButton->Click();
   ReverseCheckBox->Checked=false;
   ChangeCurrent(current(ComboBox1->ItemIndex));
   CurrentOn();
   DisplayVoltButton->Click();
   VolPlu=atof(szData);
   CurrentOff();
   if(!CheckBox1->Checked){
      ReverseCheckBox->Checked=true;
      CurrentOn();
      DisplayVoltButton->Click();
      CurrentOff();
      VolMinu=atof(szData);
      Resistance=(VolPlu-VolMinu)/2/CurrentValue;
      Ch4Edit3->Text=String(Resistance);
   }
   else{
      if(VolPlu<0 || VolPlu>1.704){
         MessageDlg("温度変換できん",mtError,TMsgDlgButtons() << mbOK, 0);
         return;
      }
      TemperatureEdit->Text=String(temp(VolPlu));
   }
}
//---------------------------------------------------------------------------

//5chの電圧(抵抗)測定、1E-5Aの電流で温度がきちんと測れる。
void __fastcall TForm1::Ch5ButtonClick(TObject *Sender)
{
   RadioButton5->Checked=true;
   CurrentOff();
   CloseChButton->Click();
   ReverseCheckBox->Checked=false;
   ChangeCurrent(current(ComboBox1->ItemIndex));
   CurrentOn();
   DisplayVoltButton->Click();
   VolPlu=atof(szData);
   CurrentOff();
   if(!CheckBox1->Checked){
      ReverseCheckBox->Checked=true;
      CurrentOn();
      DisplayVoltButton->Click();
      CurrentOff();
      VolMinu=atof(szData);
      Resistance=(VolPlu-VolMinu)/2/CurrentValue;
      Ch5Edit3->Text=String(Resistance);
   }
   else{
      if(VolPlu<0 || VolPlu>1.704){
         MessageDlg("温度変換できん",mtError,TMsgDlgButtons() << mbOK, 0);
         return;
      }
      TemperatureEdit->Text=String(temp(VolPlu));
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
  if(CheckBox1->Checked){
    ComboBox1->ItemIndex=2;
  }
}
//---------------------------------------------------------------------------


