//GPIB:02���Model2182	�`�����l����ς��鑕�u
//GPIB:04���Model220 programmable �`�`	�d���𗬂����u
//GPIB:07���Model7001	�d��(��R)��\�����鑕�u
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
   int n,t;//n:�`�����l���ԍ��At:1�͓d������Ă�A0�͗���ĂȂ�
   int TemperatureChannel;

//comboBox�őI�񂾓d���l�����B�ꉞ�AF0�œd�����Ƃ߂Ă���B
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

//������ԁA���x�v�̃`�����l����I�����ă{�[�h�I�[�v������܂Ŏg���Ȃ�
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

//���x�v�Ɏg���`�����l����I������B
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

//GPIB�̃{�[�h�̃I�[�v���A�N���[�Y
void __fastcall TForm1::OpenBottonClick(TObject *Sender)
{
   if(OpenBotton->Caption=="open"){
	  BoardOpen();

      BitBtn1->Enabled=false;
	  OpenBotton->Caption="close";    //�{�[�h����{�^���ɂ���B
      Panel1->Enabled=true;
      ComboBox1->ItemIndex=3;    //�����d���l1E-6
      current(3);
      resetboard();
   }
   else{
      CurrentOff();    //�I���A�܂��d���Ƃ߂�
      resetboard();    //����GPIB:02,GPIB:07�̏�����
      BoardClose();
      BitBtn1->Enabled=true;
      OpenBotton->Caption="open";
      Panel1->Enabled=false;
   }
}
//---------------------------------------------------------------------------

//�`�����l�����N���[�Y���܂��B(�q����)(GPIB:07)
void __fastcall TForm1::CloseChButtonClick(TObject *Sender)
{
   int n;
   for(int i=0;i<5;i++)if(ChannelRadioButton[i]->Checked)n=i+1;
   channel(n);
}
//---------------------------------------------------------------------------

//���ׂẴ`�����l������(�I�[�v���j(GPIB:07)
void __fastcall TForm1::OpenAllButtonClick(TObject *Sender)
{
   OpenAll();
   for(int i=0;i<5;i++)ChannelRadioButton[i]->Checked=false;
}
//---------------------------------------------------------------------------

//�d���l������B(�ς��邾���ł܂������Ȃ�)(GPIB:04)
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
   //�����d������Ă����U�A�d���Ƃ߂�A���Ƃŗ���
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

//�d����on,off�B(GPIB:04)
void __fastcall TForm1::CurrentCheckBoxClick(TObject *Sender)
{
   ChangeCurrent(current(ComboBox1->ItemIndex));
   if(CurrentCheckBox->State)CurrentOn();
   else CurrentOff();                          
}
//---------------------------------------------------------------------------

//���]�{�^����������\���������B(GPIB:04)
void __fastcall TForm1::ReverseCheckBoxClick(TObject *Sender)
{
   //�����d������Ă����U�A�d���Ƃ߂�A���Ƃŗ���
   if(CurrentCheckBox->State){
      CurrentOff();
      t=1;
   }
   ChangeCurrent(current(ComboBox1->ItemIndex));
   //�d������
   if(n){
      CurrentOn();
      t=0;
   }
}
//---------------------------------------------------------------------------

//�d���l��\������B(GPIB:02)
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
         MessageDlg("���x�ϊ��ł���",mtError,TMsgDlgButtons() << mbOK, 0);
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
         MessageDlg("���x�ϊ��ł���",mtError,TMsgDlgButtons() << mbOK, 0);
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
         MessageDlg("���x�ϊ��ł���",mtError,TMsgDlgButtons() << mbOK, 0);
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
         MessageDlg("���x�ϊ��ł���",mtError,TMsgDlgButtons() << mbOK, 0);
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
         MessageDlg("���x�ϊ��ł���",mtError,TMsgDlgButtons() << mbOK, 0);
         return;
      }
      TemperatureEdit->Text=String(temp(VolPlu));
   }
}
//---------------------------------------------------------------------------

//5ch�̓d��(��R)����A1E-5A�̓d���ŉ��x��������Ƒ����B
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
         MessageDlg("���x�ϊ��ł���",mtError,TMsgDlgButtons() << mbOK, 0);
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


