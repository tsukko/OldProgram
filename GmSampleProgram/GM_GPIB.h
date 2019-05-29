//GPIB:02･･･Model2182	チャンネルを変える装置
//GPIB:04･･･Model220 programmable ～～	電流を流す装置
//GPIB:07･･･Model7001	電圧(抵抗)を表示する装置
/*
//ボードのオープン:	BoardOpen();
//ボードのクローズ:	BoardClose();
//つないでいるボードを初期化:	resetboard();
//チャンネルの選択(クローズ)(GPIB:07):	 channel(int i);
//電流値の変更(GPIB:04):	ChangeCurrent(char * current);
//電流のoff(GPIB:04):	CurrentOff();
//正電流の電圧値を表示する。(GPIB:02):	 PVoltDisplay();
//負電流の電圧値を表示する。(GPIB:02):	 MVoltDisplay();
*/
//---------------------------------------------------------------------------

#include <gpc4304.h>
//---------------------------------------------------------------------------

   HANDLE    device; // デバイスハンドル
   const int ulBoardNo = 00 ;
   int nRet;   //関数の戻り値
   int nAdrsTbl[2];         // 機器アドレステーブル
   char szDataP[1024];  // グローバル変数 : 受信バッファ
   char szDataM[1024];
   int i[5];   //電流の選択番号(ch1～ch4)。Ch1ComboBoxとかのItemIndex
   char * Current[5][2];
   double CurrentValue[5];
   //nはチャンネル番号

//---------------------------------------------------------------------------
void CurrFunc(int n)
{
   /*char *curr={I-1e-3 F1 X,-----,I1e-3 F1 X};
     double *currVal={1e-3,-------};
     Current[n][0]= curr[i[n]];
     Current[n][1]= curr[i[n]+5];
     CurrentValue[n]=currVal[i[n]];
   */

   if(i[n]==0){
      Current[n][0]="I-1e-3 F1 X";
      Current[n][1]="I1e-3 F1 X";
      CurrentValue[n]=1e-3;
   }
   if(i[n]==1){
      Current[n][0]="I-1e-4 F1 X";
      Current[n][1]="I1e-4 F1 X";
      CurrentValue[n]=1e-4;
   }
   if(i[n]==2){
      Current[n][0]="I-1e-5 F1 X";
      Current[n][1]="I1e-5 F1 X";
      CurrentValue[n]=1e-5;
   }
   if(i[n]==3){
      Current[n][0]="I-1e-6 F1 X";
      Current[n][1]="I1e-6 F1 X";
      CurrentValue[n]=1e-6;
   }
   if(i[n]==4){
      Current[n][0]="I-1e-9 F1 X";
      Current[n][1]="I1e-9 F1 X";
      CurrentValue[n]=1e-9;
   }
   if(i[n]==5){
      Current[n][0]="I-1e-8 F1 X";
      Current[n][1]="I1e-8 F1 X";
      CurrentValue[n]=1e-8;
   }
}
//----------------------------------------------------------------------------

//ボードのオープン
void BoardOpen()
{
   nRet=PciGpibExInitBoard(ulBoardNo,0);
   if(nRet !=GPIB_SUCCESS){
      MessageBox(0,"エラー(Board)","",MB_OK);
      return;
   }

   //GP-IBインタフェースの初期化
   nRet=PciGpibExSetIfc(ulBoardNo, 1);
   if(nRet !=GPIB_SUCCESS){
      MessageBox(0,"エラー(Board)","",MB_OK);
      return;
   }
   nRet=PciGpibExSetRen(ulBoardNo);
   if(nRet !=GPIB_SUCCESS){
      MessageBox(0,"エラー(Board)","",MB_OK);
      return;
   }
}
//---------------------------------------------------------------------------

//ボードのクローズ
void BoardClose()
{
   //ボード閉じる
   nRet=PciGpibExFinishBoard(0);
   if(nRet !=GPIB_SUCCESS){
      MessageBox(0,"エラー(Board)","",MB_OK);
      return;
   }
}
//---------------------------------------------------------------------------

//つないでいるボードを初期化
void resetboard()
{
   nAdrsTbl[0] = 02;        // 制御する測定機器のアドレス
   nAdrsTbl[1] = -1;        // アドレステーブルの終端
   PciGpibExMastSendData(0, nAdrsTbl, strlen("*RST"), "*RST", 0);
   PciGpibExMastSendData(0, nAdrsTbl, strlen("*CLS"), "*CLS", 0);
   PciGpibExMastSendData(0, nAdrsTbl, strlen("SENSe:VOLT:DIGIts 8"), "SENSe:VOLT:DIGIts 8", 0);
   PciGpibExMastSendData(0, nAdrsTbl, strlen("SENSe:VOLT:LPASs:STAT ON"), "SENSe:VOLT:LPASs:STAT ON", 0);
   PciGpibExMastSendData(0, nAdrsTbl, strlen("SENSe:VOLT:DFILter:STAT OFF"), "SENSe:VOLT:DFILter:STAT OFF", 0);

   nAdrsTbl[0] = 04;        // 制御する測定機器のアドレス
   nAdrsTbl[1] = -1;        // アドレステーブルの終端
   PciGpibExMastSendData(0, nAdrsTbl, strlen("V3 X"), "V3 X", 0);  //V-LIMITの値
   
   nAdrsTbl[0] = 07;        // 制御する測定機器のアドレス
   nAdrsTbl[1] = -1;        // アドレステーブルの終端
   PciGpibExMastSendData(0, nAdrsTbl, strlen("*RST"), "*RST", 0);
   PciGpibExMastSendData(0, nAdrsTbl, strlen("*CLS"), "*CLS", 0);
}
//---------------------------------------------------------------------------

//チャンネルの選択(GPIB:07)
void channel(int n)
{
   nAdrsTbl[0] = 07;        // 制御する測定機器のアドレス
   nAdrsTbl[1] = -1;        // アドレステーブルの終端

   nRet=PciGpibExMastSendData(0, nAdrsTbl,strlen(":open all"),":open all", 0);
   if(nRet !=GPIB_SUCCESS){
         MessageBox(0,"エラー(GPIB:07-1)","",MB_OK);
         return;
   }
   char * chan;
   if(n==1)chan=":close (@1!1)";
   if(n==2)chan=":close (@1!2)";
   if(n==3)chan=":close (@1!3)";
   if(n==4)chan=":close (@1!4)";
   if(n==5)chan=":close (@1!5)";
   int SLch;
     SLch=strlen(chan);
   
   nRet=PciGpibExMastSendData(0, nAdrsTbl, SLch, chan, 0);
   if(nRet !=GPIB_SUCCESS){
         MessageBox(0,"エラー(GPIB:07-2)","",MB_OK);
         return;
   }
}
//---------------------------------------------------------------------------

//電流値かえる。(GPIB:04)
void ChangeCurrent(char * current)
{
   nAdrsTbl[0] = 04;        // 制御する測定機器のアドレス
   nAdrsTbl[1] = -1;        // アドレステーブルの終端
   int    SLcurr;
   SLcurr=strlen(current);
   nRet= PciGpibExMastSendData(0, nAdrsTbl, SLcurr, current, 0);    //電流値
   if(nRet !=GPIB_SUCCESS){
      MessageBox(0,"エラー(GPIB:04-1)","",MB_OK);
      return;
   }
}
//---------------------------------------------------------------------------

//電流のoff(GPIB:04)
void CurrentOff()
{
   nAdrsTbl[0] = 04;        // 制御する測定機器のアドレス
   nAdrsTbl[1] = -1;        // アドレステーブルの終端
   nRet= PciGpibExMastSendData(0, nAdrsTbl, strlen("F0 X"), "F0 X", 0);
   if(nRet !=GPIB_SUCCESS){
      MessageBox(0,"エラー(GPIB:04-2)","",MB_OK);
      return;
   }
}
//---------------------------------------------------------------------------

//電圧値を表示する。(GPIB:02)
void PVoltDisplay()
{
   nAdrsTbl[0] = 02;        // 制御する測定機器のアドレス
   nAdrsTbl[1] = -1;        // アドレステーブルの終端
   //送受信タイムアウト"/TMO=" (1～65535)、非同期入出力設定 "/ASYNC="
//   nRet=PciGpibExSetConfig(ulBoardNo,"/TMO=200 /ASYNC=ON");
   char * measurevolt="READ?";
   int    SLmeasvol=strlen(measurevolt);
   nRet=PciGpibExMastSendData(0, nAdrsTbl, SLmeasvol, measurevolt, 0);
   if(nRet !=GPIB_SUCCESS){
      MessageBox(0,"エラー(GPIB:02-1)","",MB_OK);
      return;
   }

   DWORD dwLen;         // 受信バッファ長を格納、API呼び出し後には実際の受信データ長が格納される
   dwLen = 1024;          // 受信バッファのサイズ
   //電圧値を読み取り表示
   nRet=PciGpibExMastRecvData(0, nAdrsTbl, &dwLen, szDataP, 0);
   if(nRet !=GPIB_SUCCESS){
      MessageBox(0,"エラー(GPIB:02-2)","",MB_OK);
      return;
   }
}
//---------------------------------------------------------------------------
void MVoltDisplay()
{
   nAdrsTbl[0] = 02;        // 制御する測定機器のアドレス
   nAdrsTbl[1] = -1;        // アドレステーブルの終端
   char * measurevolt="READ?";
   int    SLmeasvol=strlen(measurevolt);
   nRet=PciGpibExMastSendData(0, nAdrsTbl, SLmeasvol, measurevolt, 0);
   if(nRet !=GPIB_SUCCESS){
      MessageBox(0,"エラー(GPIB:02-4)","",MB_OK);
      return;
   }

   DWORD dwLen;         // 受信バッファ長を格納、API呼び出し後には実際の受信データ長が格納される
   dwLen = 1024;          // 受信バッファのサイズ
   //電圧値を読み取り表示
   nRet=PciGpibExMastRecvData(0, nAdrsTbl, &dwLen, szDataM, 0);
   if(nRet !=GPIB_SUCCESS){
      MessageBox(0,"エラー(GPIB:02-5)","",MB_OK);
      return;
   }
}
//---------------------------------------------------------------------------

