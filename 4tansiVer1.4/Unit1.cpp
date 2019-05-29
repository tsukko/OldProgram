/*
//GM_GPIB3.h�Œ�`���Ă���֐��B
void BoardOpen();        //�{�[�h�̃I�[�v��
void BoardClose();       //�{�[�h�̓d�N���[�Y
void resetboard();       //�Ȃ��ł���{�[�h��������
void channel(int i);     //�`�����l���̑I��(�N���[�Y)(GPIB:07)
void OpenAll();          //���ׂẴ`�����l������(�I�[�v���j(GPIB:07)
void ChangeCurrent(char * current);//�d���l������B(�ς��邾���ł܂������Ȃ�)(GPIB:04)
void CurrentOn();        //�d����on(GPIB:04)
void CurrentOff();       //����off(GPIB:04)
void VoltDisplay();      //�d���l��\������B(GPIB:02)

//GM_GPIB3.h�Œ�`���Ă���ϐ��B
char szDataP[1024];      //GPIB:02�Ő��d���𗬂������̓d���l�𑪒肵�Ċi�[����B
char szDataM[1024];      //�������͕��d���������Ƃ��B
char *Current[5][2];     //1�`5�̃`�����l���ɗ����d���A[2]�̕��͐��ƕ��B�v���l�ɓn���̂ŁuI-1e-9 F1 X�v���ėl�ȏ������B

//temp.h�Œ�`���Ă���֐��B
double temp(double�^);   //���ʓ��ɒl������Ɖ��x�Ɋ��Z���Ԃ��Ă����B
*/
   //���x�v�ɂ���
   //125�s�ڂ�5ch��C�ӂɂł���悤�ɁE�E�E188�s��
   //CheckBox�̃`�F�b�N�͑���݂̂ɍ�p����悤�ɂ���B//����
   //���ɂǂ̃`�����l�������x�v�ɂ��邩�̃{�b�N�X������B//����
   //�����̃`�F�b�N�̂��Ă���`�����l����CheckBox��false�ɂ���B//����
   //   channel(5);�Ƃ���RadioButton�̔ԍ������΂���
   //   80�s�ڂ�return�����̖Y�ꂸ�ɁB

//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>       //�t�@�C���֏������ނƂ��g��
#include <Filectrl.hpp>  //�f�B���N�g���쐬�̂��߂����ɂ���
#include <GM_GPIB4.h>    //����w�b�_�FGPIB���g���R�}���h���܂Ƃ߂�
#include <temp.h>        //����w�b�_�F���x���߂�
//#include <ChangeFile.h>     //�t�@�C����ϊ����邽�߂̊֐��������Ă�B
#include <fstream>
#include <vector>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//Testest *TestFunc;        //ChangeFile.h�ŏ����Ă���B
//---------------------------------------------------------------------------

//�ۑ��t�@�C���̏ꏊ�A���O�́uFileNameEdit->Text�v�ɏ�����Ă���B
//�ۑ��f�B���N�g����(C:\GM_date)
   FILE *fp, *fpRAW;
   AnsiString FN[4];           //�Z�[�u����t�@�C�����Bdown,up�Ɛ��f�[�^�t�@�C�����ǂ�����4��ނ���B
   AnsiString SampleName[5];   //�T���v����
   AnsiString TemperVol;       //383�s�ڂŉ��x�v�̓d�����擾���đ�����Ă���B156�s�ڂŎg�p�B
   double TemperatureX;        //���x(x��)
   double ResistanceY[6];      //��R(y��)4�Achannel��5����BResistanceY[0]�͎g���ĂȂ��ł��c����܂�낵���Ȃ������B
   float Tem;                  //������������鉷�x
   float TemR1;                //���x�ɂ��Ă̑���Ԋu1
   float TemR2;                //���x�ɂ��Ă̑���Ԋu2
   float Lasttemperature;      //�O��̉��x
   int qqq=0;                  //����̏�� 0:stop,1:down,2:up
   static int num;             //�_�̐��AChart�̉E��̕\���Ɏg���Ă���B
   int TemperaChan;            //���x�v�̃`�����l���B
   char * Current[5][2];       //�e�`�����l���̓d���l
   double CurrentValue[5];  //1�`5�̃`�����l���ɗ����d���l�B
   AnsiString Ch[]={"ch1","ch2","ch3","ch4","ch5"};

 /*
   //�d���̎�ނ𑝂₷���Ƃ��ł���B
   //���̎��ACh1ComboBox�Ƃ���Items��������悤�ɂ��Ƃ����B
   AnsiString curr[16][2];         //����currStr[]��GPIB:04���ǂ߂�`�ɒ�������B0:���A1:��

   AnsiString CurrStr[]={"1e-3",
                         "1e-4",
                         "1e-5",
                         "1e-6",
                         "1e-9"};
 */
   //060307�V�����ǉ�
   AnsiString curr[5][2];
   AnsiString CurrStr[5];

   std::vector< std::vector < std::vector < float > > > data ;
   std::vector< std::vector < float > > resis ;
   //n�̓`�����l���ԍ�
//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
   SampleNameEdit[0]=Ch1SampleNameEdit;
   SampleNameEdit[1]=Ch2SampleNameEdit;
   SampleNameEdit[2]=Ch3SampleNameEdit;
   SampleNameEdit[3]=Ch4SampleNameEdit;
   SampleNameEdit[4]=Ch5SampleNameEdit;
   MeasureChCheckBox[0]=CheckBox1;
   MeasureChCheckBox[1]=CheckBox2;
   MeasureChCheckBox[2]=CheckBox3;
   MeasureChCheckBox[3]=CheckBox4;
   MeasureChCheckBox[4]=CheckBox5;
   MeasureTempRadioButton[0]=RadioButton1;
   MeasureTempRadioButton[1]=RadioButton2;
   MeasureTempRadioButton[2]=RadioButton3;
   MeasureTempRadioButton[3]=RadioButton4;
   MeasureTempRadioButton[4]=RadioButton5;
   CurrentExponentComboBox[0]=CurrentExponentComboBox1;
   CurrentExponentComboBox[1]=CurrentExponentComboBox2;
   CurrentExponentComboBox[2]=CurrentExponentComboBox3;
   CurrentExponentComboBox[3]=CurrentExponentComboBox4;
   CurrentExponentComboBox[4]=CurrentExponentComboBox5;
   CurrentMantissaEdit[0]=CurrentMantissaEdit1;
   CurrentMantissaEdit[1]=CurrentMantissaEdit2;
   CurrentMantissaEdit[2]=CurrentMantissaEdit3;
   CurrentMantissaEdit[3]=CurrentMantissaEdit4;
   CurrentMantissaEdit[4]=CurrentMantissaEdit5;
   ChGroupBox[5];

 /*
   //�n�߂�CurrentExponentComboBox�ɑI���ł���d���l���ڂ���
   TStringList *TempList = new TStringList; // ���X�g��錾����
   try{
      for(int y=0;y<sizeof(CurrStr)/sizeof(CurrStr[0]);y++)
         TempList->Add(CurrStr[y]);
      for(int i=0;i<5;i++)
         CurrentExponentComboBox[i]->Items->AddStrings(TempList);
   }
   __finally{
     delete TempList; // ���X�g�I�u�W�F�N�g��j������
   }

   //GPIB�œd���𗬂��Ƃ��ɑ���R�}���h���̍쐬
   for(int i=0;i<sizeof(CurrStr)/sizeof(CurrStr[0]);i++){
      curr[i][0]="I-"+CurrStr[i]+" F1 X";
      curr[i][1]="I"+CurrStr[i]+" F1 X";
   }
 */
 //060306�ύX
   for(int i=0;i<5;i++){
      for(int q=0;q>-10;q--)
         CurrentExponentComboBox[i]->Items->Add(IntToStr(q));
      CurrentMantissaEdit[i]->Text="1.0";
   }
}
//---------------------------------------------------------------------------

void TForm1::ChangeFile_up(AnsiString FileName)
{
 //  StatusBar1->Panels->Items[0]->Text="�ϊ��n�߂܂�";
  ifstream rrr;
  ofstream www;

//   AnsiString date=ExtractFileName(FileName.c_str()).SubString(1,ExtractFileName(FileName.c_str()).AnsiPos("_up.txt"));
//   AnsiString Path = ExtractFilePath(FileName.c_str());
   String date=ExtractFileName(FileName.c_str()).SubString(1,ExtractFileName(FileName.c_str()).Pos("_up.txt"));
   String Path = ExtractFilePath(FileName.c_str());
   rrr.open(FileName.c_str());
   char SampleName[512];
//   AnsiString TempSampleName;
//   AnsiString SaNe[5];  //�T���v���̖��O�B�v�f�̐��͉���MaxSampleNum�Ɠ���
   String TempSampleName;
   String SaNe[5];  //�T���v���̖��O�B�v�f�̐��͉���MaxSampleNum�Ɠ���
   int MaxSampleNum=5;  //�ő�4ch+���x��5��
   int SampleNum;  //�T���v���̐�
   int PointNum=0; //����_�̐�

   //��s�ځA�T���v���l�[���̎��o��
   rrr.getline(SampleName,sizeof(SampleName));
//   TempSampleName=AnsiString(SampleName)+"\t";
   TempSampleName=String(SampleName)+"\t";
   int y=0;
   for(int i=0;i<MaxSampleNum;i++){
//	 y=TempSampleName.AnsiPos("\t");
	 y=TempSampleName.Pos("\t");
	 SaNe[i]=TempSampleName.SubString(1,y-1);
     TempSampleName.Delete(1,y);
     if(TempSampleName==""){
        SampleNum=i;
        break;
     }
   }

   //�f�[�^�̎��o��
   resis.clear();
   resis.resize(1024);
   while(!rrr.eof()){
     resis[PointNum].resize(SampleNum+1);
     for(int t=0;t<SampleNum+1;t++){
       rrr >> resis[PointNum][t];
     }
   PointNum++;
   }
   rrr.close();

   //��������
   for(int i=0;i<SampleNum;i++){
     www.open((Path+date+SaNe[i]+".dat").c_str());
//     www << (SaNe[i]+"\t"+SaNe[SampleNum]+"\n").c_str();
     www << "Resistance [\\fW]";
     www << "\t";
     www << "Temperature [K]";
     www << "\n";
       for(int q=0;q<PointNum-1;q++){
         www << resis[q][i];
         www << "\t";
         www << resis[q][SampleNum];
         www << "\n";
     }
     www.close();
   }
 //  StatusBar1->Panels->Items[0]->Text="�ϊ��I��";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FileName()
{
   //�ۑ��t�@�C����(�N����_down.txt)�Ƃ���B���̖��O�����֐�
   TDateTime dt=Now();    //���݂̓��t�E���Ԃ��擾
   WORD year,mon,day;
   dt.DecodeDate(&year,&mon,&day);
   //�N���������ꂼ��2���ŁB
   AnsiString date=AnsiString(year).Delete(1,2)+FormatFloat("00",mon)+FormatFloat("00",day);
   FN[0]=SaveDialog1->InitialDir+"\\"+date+"\\"+date+"_RAW_down.txt";
   FN[1]=SaveDialog1->InitialDir+"\\"+date+"\\"+date+"_down.txt";
   FN[2]=SaveDialog1->InitialDir+"\\"+date+"\\"+date+"_RAW_up.txt";
   FN[3]=SaveDialog1->InitialDir+"\\"+date+"\\"+date+"_up.txt";
   if (!DirectoryExists(SaveDialog1->InitialDir+"\\"+date))
   {
      if (!CreateDir(SaveDialog1->InitialDir+"\\"+date))
         throw Exception("Cannot create"+SaveDialog1->InitialDir+"\\"+date);
   }
}
//----------------------------------------------------------------------------

double ResiFunc(int n)
{
   CurrentOff();
   channel(n);
   ChangeCurrent(Current[n][1]);
   VoltDisplay(1);
   ChangeCurrent(Current[n][0]);
   VoltDisplay(0);
      fprintf(fpRAW,"%s \t %s \t",szData[1],szData[0]);
   ResistanceY[n]=(atof(szData[1])-atof(szData[0]))/2/CurrentValue[n];

   return ResistanceY[n];
}
//----------------------------------------------------------------------------

void __fastcall TForm1::sokuteimae()
{
   ConditionButton->Click();
   for(int n=0;n<5;n++){
      MeasureChart->Series[n]->Clear();
      SampleName[n]=SampleNameEdit[n]->Text;
   }

   //���t�@�C���ɓ��t���L��
   fprintf(fpRAW,"%s\n",FormatDateTime("c",Now()));
   //���t�@�C���ɑ��肷��T���v�������L��
   for(int n=0;n<5;n++){
      if(MeasureChCheckBox[n]->State)
         fprintf(fpRAW,"%s\t%s\t",Ch[n],SampleName[n]);
   }
   fprintf(fpRAW,"\n");
   //���t�@�C���ɓd���l���L��
   for(int n=0;n<5;n++){
      if(MeasureChCheckBox[n]->State)
         fprintf(fpRAW,"%s\t%s\t",Ch[n],Current[n][0]);
   }
   fprintf(fpRAW,"\n");

   for(int n=0;n<5;n++){
      if(MeasureChCheckBox[n]->State){
        fprintf(fp,"%s\t",SampleName[n]);
        fprintf(fpRAW,"%s\t%s\t",Ch[n]+"+",Ch[n]+"-");
      }
   }
   fprintf(fp,"%s\n","Temperature [K]");
   fprintf(fpRAW,"%s\t%s\n",Ch[TemperaChan]+"(Temp)","Temperature [K]");

   //����J�n����̉��x(�����炭�ő�l)������
   CurrentOff();
   channel(TemperaChan);
   ChangeCurrent(Current[TemperaChan][1]);

   VoltDisplay(1);
   if(atof(szData[1])<0 || atof(szData[1])>1.704){
      MessageDlg("���x�ϊ��ł���",mtError,TMsgDlgButtons() << mbOK, 0);
      return;
   }

   TemperatureX=temp(atof(szData[1]));
   MeasureButton->Enabled=false;
   ConfigGroupBox->Enabled=false;
   BoardOpenButton->Enabled=false;
   num=0;
   Timer1->Enabled=true;          //����J�n
}
//----------------------------------------------------------------------------

void __fastcall TForm1::sokutei()
{
   num++;
   for(int n=0;n<5;n++){
      if(MeasureChCheckBox[n]->State){
         ResistanceY[n]=ResiFunc(n);
         MeasureChart->Series[n]->AddXY(TemperatureX,ResistanceY[n],"",clTeeColor);
         fprintf(fp,"%f\t",ResistanceY[n]);
      }
   }
      Lasttemperature=TemperatureX;

      fprintf(fp,"%f\n",TemperatureX);
      fprintf(fpRAW,"%s\t%f\n",TemperVol,TemperatureX);

      if(ferror(fp)){
         ShowMessage("�������݃G���[���������܂���");
         return;
      }
      //�_�̐�;
      PointLabel->Caption=num;
  
      CurrentOff();
      channel(TemperaChan);
      ChangeCurrent(Current[TemperaChan][1]);
}
//---------------------------------------------------------------------------
//�����܂ŏオ�֐�

void __fastcall TForm1::FormCreate(TObject *Sender)
{
   Timer1->Enabled=false;          //�n�߂͑��肵�ĂȂ�
   MeasureChart->LeftAxis->Minimum=0;
   FileName();
   FileNameEdit->Text=FN[0];
   Panel1->Enabled=false;
   ConditionGroupBox->Enabled=false;
   for(int n=0;n<5;n++){
      MeasureChCheckBox[n]->Checked=false;
      CurrentExponentComboBox[n]->ItemIndex=5;
   }
   RadioButton5->Checked=true;
   ResistanceMantissaComboBox->ItemIndex=4;
   ResistanceExponenComboBox->ItemIndex=6;
   TemperatureComboBox->ItemIndex=15;        
   MeasureChart->LeftAxis->Minimum=0;
   MeasureChart->LeftAxis->Maximum=0.5;       //�X�}�[�g����Ȃ��B
   MeasureChart->BottomAxis->Minimum=0;
   MeasureChart->BottomAxis->Maximum=300;     //�X�}�[�g����Ȃ��B
   ConditionButton->Click();
}
//---------------------------------------------------------------------------

//���̃{�^����down�̑�����J�n����B
void __fastcall TForm1::MeasureButtonClick(TObject *Sender)
{
   if(!qqq){
      if (FileExists(FileNameEdit->Text)){
         if(MessageDlg("���̃t�@�C���͑��݂��܂��A�㏑�����܂����H",mtWarning,
         TMsgDlgButtons() << mbYes << mbNo, 0)==mrYes){
         }
         else return;
      }

      for(int n=0;n<5;n++){
		 try{
            float test1;            //float�ɂł��邩�ǂ����̃`�F�b�N
            test1=StrToFloat(CurrentMantissaEdit[n]->Text);
         }
		 catch(...){
            MessageDlg(IntToStr(n+1)+"ch�̓d���ς���Ȃ����H",mtError,TMsgDlgButtons() << mbOK, 0);
         return;
         }
         //���x�v�ɂ���`�����l�������߂�B�d���l��1E-5
         if(MeasureTempRadioButton[n]->Checked){
            TemperaChan=n;
            CurrentMantissaEdit[n]->Text="1.0";
            CurrentExponentComboBox[n]->ItemIndex=5;
         }
         CurrStr[n]=(CurrentMantissaEdit[n]->Text+"e"+CurrentExponentComboBox[n]->Items->Strings[CurrentExponentComboBox[n]->ItemIndex]).c_str();
         curr[n][0]="I-"+CurrStr[n]+" F1 X";      //Current[n][0]=("I-"+CurrStr[n]+" F1 X").c_str();���Ⴞ�߂������B�B�B
         Current[n][0]=curr[n][0].c_str();
         curr[n][1]="I"+CurrStr[n]+" F1 X";
         Current[n][1]=curr[n][1].c_str();
         CurrentValue[n]=atof(CurrStr[n].c_str());
      }

   }

   fp=fopen(FN[1].c_str(),"w");
   if(!fp){
      ShowMessage("�t�@�C�����I�[�v���ł��܂���");
      return;
   }
   fpRAW=fopen(FN[0].c_str(),"w");
   if(!fpRAW){
      ShowMessage("�t�@�C�����I�[�v���ł��܂���");
      return;
   }

   qqq=1;  //down�̑�����

   //���肷��O�Ƀt�@�C���Ɏ��������������ފ֐����������B���������̂�
   sokuteimae();     //������
   UpButton->Enabled=true;

   StatusBar1->Panels->Items[1]->Text="down���蒆";
   StatusBar1->Panels->Items[2]->Text=FormatDateTime("c",Now());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UpButtonClick(TObject *Sender)
{
   Timer1->Enabled=false;
   FileNameEdit->Text=FN[2];

   //down���肵�Ă��Ȃ��ꍇ(qqq=0)�A������ʂ�B
   if(!qqq){
      if (FileExists(FileNameEdit->Text)){
         if(MessageDlg("���̃t�@�C���͑��݂��܂��A�㏑�����܂����H",mtWarning,
         TMsgDlgButtons() << mbYes << mbNo, 0)==mrYes){
         }
         else return;
      }

      //
      for(int n=0;n<5;n++){
		 try{
            float test1;       //float�ɂł��邩�ǂ����̃`�F�b�N
            test1=StrToFloat(CurrentMantissaEdit[n]->Text);
         }
		 catch(...){
            MessageDlg(IntToStr(n+1)+"ch�̓d���ς���Ȃ����H",mtError,TMsgDlgButtons() << mbOK, 0);
         return;
         }
         //���x�v�ɂ���`�����l�������߂�B�d���l��1E-5
         if(MeasureTempRadioButton[n]->Checked){
            TemperaChan=n;
            CurrentMantissaEdit[n]->Text="1.0";
            CurrentExponentComboBox[n]->ItemIndex=5;
         }
         CurrStr[n]=(CurrentMantissaEdit[n]->Text+"e"+CurrentExponentComboBox[n]->Items->Strings[CurrentExponentComboBox[n]->ItemIndex]).c_str();
         curr[n][0]="I-"+CurrStr[n]+" F1 X";      //Current[n][0]=("I-"+CurrStr[n]+" F1 X").c_str();���Ⴞ�߂������B�B�B
         Current[n][0]=curr[n][0].c_str();
         curr[n][1]="I"+CurrStr[n]+" F1 X";
         Current[n][1]=curr[n][1].c_str();
         CurrentValue[n]=atof(CurrStr[n].c_str());
      }
   }
   //down���肵�Ă���ꍇ(qqq=1)�͂������B
   else if(qqq==1){
      fclose(fp);
      if(!(fclose(fp))){
         ShowMessage("�t�@�C�����N���[�Y�ł��܂���");
         return;
      }
      fclose(fpRAW);
      if(!(fclose(fpRAW))){
         ShowMessage("�t�@�C�����N���[�Y�ł��܂���");
         return;
      }
   }

   fp=fopen(FN[3].c_str(),"w");
   if(!fp){
      ShowMessage("�t�@�C�����I�[�v���ł��܂���");
      return;
   }
   fpRAW=fopen(FN[2].c_str(),"w");
   if(!fpRAW){
      ShowMessage("�t�@�C�����I�[�v���ł��܂���");
      return;
   }

   //���肷��O�Ƀt�@�C���Ɏ��������������ފ֐����������B���������̂�
   sokuteimae();

   qqq=2;                   //up�̑�����
   Lasttemperature=2;       //up��2K���瑪�肷��悤�ɂ��Ă���

   UpButton->Enabled=false;
   StatusBar1->Panels->Items[1]->Text="up���蒆";
   StatusBar1->Panels->Items[2]->Text=FormatDateTime("c",Now());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StopButtonClick(TObject *Sender)
{
   fclose(fp);
   if(!(fclose(fp))){
      ShowMessage("�t�@�C�����N���[�Y�ł��܂���");
      return;
   }
   fclose(fpRAW);
   if(!(fclose(fpRAW))){
      ShowMessage("�t�@�C�����N���[�Y�ł��܂���");
      return;
   }
   Timer1->Enabled=false;
   MeasureButton->Enabled=true;
   ConfigGroupBox->Enabled=true;
   UpButton->Enabled=true;
   BoardOpenButton->Enabled=true;

   StatusBar1->Panels->Items[1]->Text="����I����";

   if(qqq==1) ChangeFile_up(FN[1]);
   else if(qqq==2) ChangeFile_up(FN[3]);
   qqq=0;
   StatusBar1->Panels->Items[1]->Text="����I���";
   StatusBar1->Panels->Items[2]->Text=FormatDateTime("c",Now());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
   VoltDisplay(1);
   if(atof(szData[1])<0 || atof(szData[1])>1.704){
      MessageDlg("���x�ϊ��ł���",mtError,TMsgDlgButtons() << mbOK, 0);
      return;
   }
   TemperatureX=temp(atof(szData[1]));
   TemperVol=String(szData[1]);       //���ƂŃt�@�C���ɏ����o����悤��

   if(qqq==1){
   //�n�߂̉��x�w�肵���ꍇ
      if(TemperatureX>=Tem){
         if(Lasttemperature-TemperatureX>=TemR1)sokutei();
      }
      else{
         if(Lasttemperature-TemperatureX>=TemR2)sokutei();
      }
   }
   //up�̂Ƃ�
   else if(qqq==2){
      if(TemperatureX>=Tem){
         if(TemperatureX-Lasttemperature>=TemR1)sokutei();
      }
      else{
         if(TemperatureX-Lasttemperature>=TemR2)sokutei();
      }
      if(TemperatureX>StrToInt(FirstTempEdit->Text))StopButton->Click();
   }
   TemperatureLabel->Caption=FormatFloat("#.000",TemperatureX);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BoardOpenButtonClick(TObject *Sender)
{
   if(BoardOpenButton->Caption=="&Open"){
      Panel1->Enabled=true;
      ConditionGroupBox->Enabled=true;
      BitBtn1->Enabled=false;
      BoardOpen();
      resetboard();   //GPIB:02,GPIB:07�̏�����
      BoardOpenButton->Caption="&Close";
   }
   else{
      BoardOpenButton->Caption="&Open";
      Panel1->Enabled=false;
      ConditionGroupBox->Enabled=false;
      BitBtn1->Enabled=true;
      CurrentOff();    //�I���A�܂��d���Ƃ߂�
      resetboard();    //����GPIB:02,GPIB:07�̏�����
      BoardClose();
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FNChangeButtonClick(TObject *Sender)
{
   SaveDialog1->FileName=FN[0];
   if(SaveDialog1->Execute()){
      FileNameEdit->Text=SaveDialog1->FileName;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ConditionButtonClick(TObject *Sender)
{
   Lasttemperature=StrToFloat(FirstTempEdit->Text);
    Tem=StrToFloat(TempEdit->Text);
   TemR1=StrToFloat(TempRate1Edit->Text);
   TemR2=StrToFloat(TempRate2Edit->Text);
   Timer1->Interval=StrToFloat(SecondRateEdit->Text)*1000;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MeasureChartMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
   float x,y;
   x=MeasureChart->Series[0]->XScreenToValue(X);
   y=MeasureChart->Series[0]->YScreenToValue(Y);
   StatusBar1->Panels->Items[0]->Text=" X "+FormatFloat("0.000",x)+", Y "+FormatFloat("0.000",y);
}
//---------------------------------------------------------------------------

//�����A�c���̍ő�l�̕ύX
void __fastcall TForm1::TemperatureComboBoxChange(TObject *Sender)
{
   try{
      MeasureChart->BottomAxis->Maximum=StrToInt(TemperatureComboBox->Items->Strings[TemperatureComboBox->ItemIndex]);
   }
   catch(...){
      MessageDlg("�����̃X�P�[���ϊ����s",mtError,TMsgDlgButtons() << mbOK, 0);
      return;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ResistanceMantissaComboBoxChange(TObject *Sender)
{
   float a,b;
   try{
      a=StrToFloat(ResistanceMantissaComboBox->Items->Strings[ResistanceMantissaComboBox->ItemIndex]);
      b=StrToFloat(ResistanceExponenComboBox->Items->Strings[ResistanceExponenComboBox->ItemIndex]);
      MeasureChart->LeftAxis->Maximum=a*pow(10,b);
   }
   catch(...){
      MessageDlg("�c���̃X�P�[���ϊ����s",mtError,TMsgDlgButtons() << mbOK, 0);
      return;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ResistanceExponenComboBoxChange(TObject *Sender)
{
   float a,b;
   try{
      a=StrToFloat(ResistanceMantissaComboBox->Items->Strings[ResistanceMantissaComboBox->ItemIndex]);
      b=StrToFloat(ResistanceExponenComboBox->Items->Strings[ResistanceExponenComboBox->ItemIndex]);
      MeasureChart->LeftAxis->Maximum=a*pow(10,b);
   }
   catch(...){
      MessageDlg("�c���̃X�P�[���ϊ����s",mtError,TMsgDlgButtons() << mbOK, 0);
      return;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
  if(MeasureTempRadioButton[0]->Checked){
     MeasureChCheckBox[0]->Checked=false;
     MeasureChCheckBox[0]->Enabled=false;
     MeasureChCheckBox[1]->Enabled=true;
     MeasureChCheckBox[2]->Enabled=true;
     MeasureChCheckBox[3]->Enabled=true;
     MeasureChCheckBox[4]->Enabled=true;
     CurrentExponentComboBox[0]->ItemIndex=5;
     CurrentExponentComboBox[0]->Enabled=false;
     CurrentExponentComboBox[1]->Enabled=true;
     CurrentExponentComboBox[2]->Enabled=true;
     CurrentExponentComboBox[3]->Enabled=true;
     CurrentExponentComboBox[4]->Enabled=true;
     Ch1SampleNameEdit->Text="Temperture";
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
  if(MeasureTempRadioButton[1]->Checked){
     MeasureChCheckBox[1]->Checked=false;
     MeasureChCheckBox[1]->Enabled=false;
     MeasureChCheckBox[0]->Enabled=true;
     MeasureChCheckBox[2]->Enabled=true;
     MeasureChCheckBox[3]->Enabled=true;
     MeasureChCheckBox[4]->Enabled=true;
     CurrentExponentComboBox[1]->ItemIndex=5;
     CurrentExponentComboBox[1]->Enabled=false;
     CurrentExponentComboBox[0]->Enabled=true;
     CurrentExponentComboBox[2]->Enabled=true;
     CurrentExponentComboBox[3]->Enabled=true;
     CurrentExponentComboBox[4]->Enabled=true;
     Ch2SampleNameEdit->Text="Temperture";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{
  if(MeasureTempRadioButton[2]->Checked){
     MeasureChCheckBox[2]->Checked=false;
     MeasureChCheckBox[2]->Enabled=false;
     MeasureChCheckBox[0]->Enabled=true;
     MeasureChCheckBox[1]->Enabled=true;
     MeasureChCheckBox[3]->Enabled=true;
     MeasureChCheckBox[4]->Enabled=true;
     CurrentExponentComboBox[2]->ItemIndex=5;
     CurrentExponentComboBox[2]->Enabled=false;
     CurrentExponentComboBox[0]->Enabled=true;
     CurrentExponentComboBox[1]->Enabled=true;
     CurrentExponentComboBox[3]->Enabled=true;
     CurrentExponentComboBox[4]->Enabled=true;
     Ch3SampleNameEdit->Text="Temperture";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton4Click(TObject *Sender)
{
  if(MeasureTempRadioButton[3]->Checked){
     MeasureChCheckBox[3]->Checked=false;
     MeasureChCheckBox[3]->Enabled=false;
     MeasureChCheckBox[0]->Enabled=true;
     MeasureChCheckBox[1]->Enabled=true;
     MeasureChCheckBox[2]->Enabled=true;
     MeasureChCheckBox[4]->Enabled=true;
     CurrentExponentComboBox[3]->ItemIndex=5;
     CurrentExponentComboBox[3]->Enabled=false;
     CurrentExponentComboBox[0]->Enabled=true;
     CurrentExponentComboBox[1]->Enabled=true;
     CurrentExponentComboBox[2]->Enabled=true;
     CurrentExponentComboBox[4]->Enabled=true;
     Ch4SampleNameEdit->Text="Temperture";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton5Click(TObject *Sender)
{
  if(MeasureTempRadioButton[4]->Checked){
     MeasureChCheckBox[4]->Checked=false;
     MeasureChCheckBox[4]->Enabled=false;
     MeasureChCheckBox[0]->Enabled=true;
     MeasureChCheckBox[1]->Enabled=true;
     MeasureChCheckBox[2]->Enabled=true;
     MeasureChCheckBox[3]->Enabled=true;
     CurrentExponentComboBox[4]->ItemIndex=5;
     CurrentExponentComboBox[4]->Enabled=false;
     CurrentExponentComboBox[0]->Enabled=true;
     CurrentExponentComboBox[1]->Enabled=true;
     CurrentExponentComboBox[2]->Enabled=true;
     CurrentExponentComboBox[3]->Enabled=true;
     Ch5SampleNameEdit->Text="Temperture";
  }
}
//---------------------------------------------------------------------------

