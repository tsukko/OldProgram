/*
//GM_GPIB3.hで定義している関数。
void BoardOpen();        //ボードのオープン
void BoardClose();       //ボードの電クローズ
void resetboard();       //つないでいるボードを初期化
void channel(int i);     //チャンネルの選択(クローズ)(GPIB:07)
void OpenAll();          //すべてのチャンネル閉じる(オープン）(GPIB:07)
void ChangeCurrent(char * current);//電流値かえる。(変えるだけでまだ流さない)(GPIB:04)
void CurrentOn();        //電流のon(GPIB:04)
void CurrentOff();       //流のoff(GPIB:04)
void VoltDisplay();      //電圧値を表示する。(GPIB:02)

//GM_GPIB3.hで定義している変数。
char szDataP[1024];      //GPIB:02で正電流を流した時の電圧値を測定して格納する。
char szDataM[1024];      //こっちは負電流流したとき。
char *Current[5][2];     //1～5のチャンネルに流す電流、[2]の方は正と負。計測値に渡すので「I-1e-9 F1 X」って様な書き方。

//temp.hで定義している関数。
double temp(double型);   //括弧内に値が入ると温度に換算し返してくれる。
*/
   //温度計について
   //125行目の5chを任意にできるように・・・188行目
   //CheckBoxのチェックは測定のみに作用するようにする。//した
   //他にどのチャンネルを温度計にするかのボックスがいる。//した
   //そこのチェックのついているチャンネルのCheckBoxはfalseにする。//した
   //   channel(5);とかはRadioButtonの番号を取ればいい
   //   80行目のreturn直すの忘れずに。

//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>       //ファイルへ書き込むとき使う
#include <Filectrl.hpp>  //ディレクトリ作成のためだけにつけた
#include <GM_GPIB4.h>    //自作ヘッダ：GPIBを使うコマンドをまとめた
#include <temp.h>        //自作ヘッダ：温度求める
//#include <ChangeFile.h>     //ファイルを変換するための関数を書いてる。
#include <fstream>
#include <vector>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//Testest *TestFunc;        //ChangeFile.hで書いている。
//---------------------------------------------------------------------------

//保存ファイルの場所、名前は「FileNameEdit->Text」に書かれている。
//保存ディレクトリは(C:\GM_date)
   FILE *fp, *fpRAW;
   AnsiString FN[4];           //セーブするファイル名。down,upと生データファイルかどうかの4種類ある。
   AnsiString SampleName[5];   //サンプル名
   AnsiString TemperVol;       //383行目で温度計の電圧を取得して代入している。156行目で使用。
   double TemperatureX;        //温度(x軸)
   double ResistanceY[6];      //抵抗(y軸)4つ、channelは5つある。ResistanceY[0]は使ってないです…あんまよろしくないっす。
   float Tem;                  //測定条件かえる温度
   float TemR1;                //温度についての測定間隔1
   float TemR2;                //温度についての測定間隔2
   float Lasttemperature;      //前回の温度
   int qqq=0;                  //測定の状態 0:stop,1:down,2:up
   static int num;             //点の数、Chartの右上の表示に使っている。
   int TemperaChan;            //温度計のチャンネル。
   char * Current[5][2];       //各チャンネルの電流値
   double CurrentValue[5];  //1～5のチャンネルに流す電流値。
   AnsiString Ch[]={"ch1","ch2","ch3","ch4","ch5"};

 /*
   //電流の種類を増やすこともできる。
   //その時、Ch1ComboBoxとかのItemsも増えるようにしといた。
   AnsiString curr[16][2];         //下のcurrStr[]のGPIB:04が読める形に直したやつ。0:負、1:正

   AnsiString CurrStr[]={"1e-3",
                         "1e-4",
                         "1e-5",
                         "1e-6",
                         "1e-9"};
 */
   //060307新しく追加
   AnsiString curr[5][2];
   AnsiString CurrStr[5];

   std::vector< std::vector < std::vector < float > > > data ;
   std::vector< std::vector < float > > resis ;
   //nはチャンネル番号
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
   //始めにCurrentExponentComboBoxに選択できる電流値を載せる
   TStringList *TempList = new TStringList; // リストを宣言する
   try{
      for(int y=0;y<sizeof(CurrStr)/sizeof(CurrStr[0]);y++)
         TempList->Add(CurrStr[y]);
      for(int i=0;i<5;i++)
         CurrentExponentComboBox[i]->Items->AddStrings(TempList);
   }
   __finally{
     delete TempList; // リストオブジェクトを破棄する
   }

   //GPIBで電流を流すときに送るコマンド文の作成
   for(int i=0;i<sizeof(CurrStr)/sizeof(CurrStr[0]);i++){
      curr[i][0]="I-"+CurrStr[i]+" F1 X";
      curr[i][1]="I"+CurrStr[i]+" F1 X";
   }
 */
 //060306変更
   for(int i=0;i<5;i++){
      for(int q=0;q>-10;q--)
         CurrentExponentComboBox[i]->Items->Add(IntToStr(q));
      CurrentMantissaEdit[i]->Text="1.0";
   }
}
//---------------------------------------------------------------------------

void TForm1::ChangeFile_up(AnsiString FileName)
{
 //  StatusBar1->Panels->Items[0]->Text="変換始めます";
  ifstream rrr;
  ofstream www;

//   AnsiString date=ExtractFileName(FileName.c_str()).SubString(1,ExtractFileName(FileName.c_str()).AnsiPos("_up.txt"));
//   AnsiString Path = ExtractFilePath(FileName.c_str());
   String date=ExtractFileName(FileName.c_str()).SubString(1,ExtractFileName(FileName.c_str()).Pos("_up.txt"));
   String Path = ExtractFilePath(FileName.c_str());
   rrr.open(FileName.c_str());
   char SampleName[512];
//   AnsiString TempSampleName;
//   AnsiString SaNe[5];  //サンプルの名前。要素の数は下のMaxSampleNumと同じ
   String TempSampleName;
   String SaNe[5];  //サンプルの名前。要素の数は下のMaxSampleNumと同じ
   int MaxSampleNum=5;  //最大4ch+温度の5つ
   int SampleNum;  //サンプルの数
   int PointNum=0; //測定点の数

   //一行目、サンプルネームの取り出し
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

   //データの取り出し
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

   //書き込む
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
 //  StatusBar1->Panels->Items[0]->Text="変換終了";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FileName()
{
   //保存ファイル名(年月日_down.txt)とする。その名前を作る関数
   TDateTime dt=Now();    //現在の日付・時間を取得
   WORD year,mon,day;
   dt.DecodeDate(&year,&mon,&day);
   //年月日をそれぞれ2桁で。
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

   //生ファイルに日付を記入
   fprintf(fpRAW,"%s\n",FormatDateTime("c",Now()));
   //生ファイルに測定するサンプル名を記入
   for(int n=0;n<5;n++){
      if(MeasureChCheckBox[n]->State)
         fprintf(fpRAW,"%s\t%s\t",Ch[n],SampleName[n]);
   }
   fprintf(fpRAW,"\n");
   //生ファイルに電流値を記入
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

   //測定開始直後の温度(おそらく最大値)が入る
   CurrentOff();
   channel(TemperaChan);
   ChangeCurrent(Current[TemperaChan][1]);

   VoltDisplay(1);
   if(atof(szData[1])<0 || atof(szData[1])>1.704){
      MessageDlg("温度変換できん",mtError,TMsgDlgButtons() << mbOK, 0);
      return;
   }

   TemperatureX=temp(atof(szData[1]));
   MeasureButton->Enabled=false;
   ConfigGroupBox->Enabled=false;
   BoardOpenButton->Enabled=false;
   num=0;
   Timer1->Enabled=true;          //測定開始
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
         ShowMessage("書き込みエラーが発生しました");
         return;
      }
      //点の数;
      PointLabel->Caption=num;
  
      CurrentOff();
      channel(TemperaChan);
      ChangeCurrent(Current[TemperaChan][1]);
}
//---------------------------------------------------------------------------
//ここまで上が関数

void __fastcall TForm1::FormCreate(TObject *Sender)
{
   Timer1->Enabled=false;          //始めは測定してない
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
   MeasureChart->LeftAxis->Maximum=0.5;       //スマートじゃない。
   MeasureChart->BottomAxis->Minimum=0;
   MeasureChart->BottomAxis->Maximum=300;     //スマートじゃない。
   ConditionButton->Click();
}
//---------------------------------------------------------------------------

//このボタンでdownの測定を開始する。
void __fastcall TForm1::MeasureButtonClick(TObject *Sender)
{
   if(!qqq){
      if (FileExists(FileNameEdit->Text)){
         if(MessageDlg("そのファイルは存在します、上書きしますか？",mtWarning,
         TMsgDlgButtons() << mbYes << mbNo, 0)==mrYes){
         }
         else return;
      }

      for(int n=0;n<5;n++){
		 try{
            float test1;            //floatにできるかどうかのチェック
            test1=StrToFloat(CurrentMantissaEdit[n]->Text);
         }
		 catch(...){
            MessageDlg(IntToStr(n+1)+"chの電流変じゃないけ？",mtError,TMsgDlgButtons() << mbOK, 0);
         return;
         }
         //温度計にするチャンネルも決める。電流値は1E-5
         if(MeasureTempRadioButton[n]->Checked){
            TemperaChan=n;
            CurrentMantissaEdit[n]->Text="1.0";
            CurrentExponentComboBox[n]->ItemIndex=5;
         }
         CurrStr[n]=(CurrentMantissaEdit[n]->Text+"e"+CurrentExponentComboBox[n]->Items->Strings[CurrentExponentComboBox[n]->ItemIndex]).c_str();
         curr[n][0]="I-"+CurrStr[n]+" F1 X";      //Current[n][0]=("I-"+CurrStr[n]+" F1 X").c_str();じゃだめだった。。。
         Current[n][0]=curr[n][0].c_str();
         curr[n][1]="I"+CurrStr[n]+" F1 X";
         Current[n][1]=curr[n][1].c_str();
         CurrentValue[n]=atof(CurrStr[n].c_str());
      }

   }

   fp=fopen(FN[1].c_str(),"w");
   if(!fp){
      ShowMessage("ファイルをオープンできません");
      return;
   }
   fpRAW=fopen(FN[0].c_str(),"w");
   if(!fpRAW){
      ShowMessage("ファイルをオープンできません");
      return;
   }

   qqq=1;  //downの測定状態

   //測定する前にファイルに試料名を書き込む関数をつくった。長かったので
   sokuteimae();     //ここで
   UpButton->Enabled=true;

   StatusBar1->Panels->Items[1]->Text="down測定中";
   StatusBar1->Panels->Items[2]->Text=FormatDateTime("c",Now());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UpButtonClick(TObject *Sender)
{
   Timer1->Enabled=false;
   FileNameEdit->Text=FN[2];

   //down測定していない場合(qqq=0)、ここを通る。
   if(!qqq){
      if (FileExists(FileNameEdit->Text)){
         if(MessageDlg("そのファイルは存在します、上書きしますか？",mtWarning,
         TMsgDlgButtons() << mbYes << mbNo, 0)==mrYes){
         }
         else return;
      }

      //
      for(int n=0;n<5;n++){
		 try{
            float test1;       //floatにできるかどうかのチェック
            test1=StrToFloat(CurrentMantissaEdit[n]->Text);
         }
		 catch(...){
            MessageDlg(IntToStr(n+1)+"chの電流変じゃないけ？",mtError,TMsgDlgButtons() << mbOK, 0);
         return;
         }
         //温度計にするチャンネルも決める。電流値は1E-5
         if(MeasureTempRadioButton[n]->Checked){
            TemperaChan=n;
            CurrentMantissaEdit[n]->Text="1.0";
            CurrentExponentComboBox[n]->ItemIndex=5;
         }
         CurrStr[n]=(CurrentMantissaEdit[n]->Text+"e"+CurrentExponentComboBox[n]->Items->Strings[CurrentExponentComboBox[n]->ItemIndex]).c_str();
         curr[n][0]="I-"+CurrStr[n]+" F1 X";      //Current[n][0]=("I-"+CurrStr[n]+" F1 X").c_str();じゃだめだった。。。
         Current[n][0]=curr[n][0].c_str();
         curr[n][1]="I"+CurrStr[n]+" F1 X";
         Current[n][1]=curr[n][1].c_str();
         CurrentValue[n]=atof(CurrStr[n].c_str());
      }
   }
   //down測定している場合(qqq=1)はこっち。
   else if(qqq==1){
      fclose(fp);
      if(!(fclose(fp))){
         ShowMessage("ファイルをクローズできません");
         return;
      }
      fclose(fpRAW);
      if(!(fclose(fpRAW))){
         ShowMessage("ファイルをクローズできません");
         return;
      }
   }

   fp=fopen(FN[3].c_str(),"w");
   if(!fp){
      ShowMessage("ファイルをオープンできません");
      return;
   }
   fpRAW=fopen(FN[2].c_str(),"w");
   if(!fpRAW){
      ShowMessage("ファイルをオープンできません");
      return;
   }

   //測定する前にファイルに試料名を書き込む関数をつくった。長かったので
   sokuteimae();

   qqq=2;                   //upの測定状態
   Lasttemperature=2;       //upは2Kから測定するようにしてある

   UpButton->Enabled=false;
   StatusBar1->Panels->Items[1]->Text="up測定中";
   StatusBar1->Panels->Items[2]->Text=FormatDateTime("c",Now());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StopButtonClick(TObject *Sender)
{
   fclose(fp);
   if(!(fclose(fp))){
      ShowMessage("ファイルをクローズできません");
      return;
   }
   fclose(fpRAW);
   if(!(fclose(fpRAW))){
      ShowMessage("ファイルをクローズできません");
      return;
   }
   Timer1->Enabled=false;
   MeasureButton->Enabled=true;
   ConfigGroupBox->Enabled=true;
   UpButton->Enabled=true;
   BoardOpenButton->Enabled=true;

   StatusBar1->Panels->Items[1]->Text="測定終了中";

   if(qqq==1) ChangeFile_up(FN[1]);
   else if(qqq==2) ChangeFile_up(FN[3]);
   qqq=0;
   StatusBar1->Panels->Items[1]->Text="測定終わり";
   StatusBar1->Panels->Items[2]->Text=FormatDateTime("c",Now());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
   VoltDisplay(1);
   if(atof(szData[1])<0 || atof(szData[1])>1.704){
      MessageDlg("温度変換できん",mtError,TMsgDlgButtons() << mbOK, 0);
      return;
   }
   TemperatureX=temp(atof(szData[1]));
   TemperVol=String(szData[1]);       //あとでファイルに書き出せるように

   if(qqq==1){
   //始めの温度指定した場合
      if(TemperatureX>=Tem){
         if(Lasttemperature-TemperatureX>=TemR1)sokutei();
      }
      else{
         if(Lasttemperature-TemperatureX>=TemR2)sokutei();
      }
   }
   //upのとき
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
      resetboard();   //GPIB:02,GPIB:07の初期化
      BoardOpenButton->Caption="&Close";
   }
   else{
      BoardOpenButton->Caption="&Open";
      Panel1->Enabled=false;
      ConditionGroupBox->Enabled=false;
      BitBtn1->Enabled=true;
      CurrentOff();    //終了、まず電流とめる
      resetboard();    //次にGPIB:02,GPIB:07の初期化
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

//横軸、縦軸の最大値の変更
void __fastcall TForm1::TemperatureComboBoxChange(TObject *Sender)
{
   try{
      MeasureChart->BottomAxis->Maximum=StrToInt(TemperatureComboBox->Items->Strings[TemperatureComboBox->ItemIndex]);
   }
   catch(...){
      MessageDlg("横軸のスケール変換失敗",mtError,TMsgDlgButtons() << mbOK, 0);
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
      MessageDlg("縦軸のスケール変換失敗",mtError,TMsgDlgButtons() << mbOK, 0);
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
      MessageDlg("縦軸のスケール変換失敗",mtError,TMsgDlgButtons() << mbOK, 0);
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

