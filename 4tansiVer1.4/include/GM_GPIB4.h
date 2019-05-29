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

//#include <gpc4304.h>
#include "dll\Include\FBISeries\Gpc4304.h"
//---------------------------------------------------------------------------

   HANDLE    device; // デバイスハンドル
   const int ulBoardNo = 00 ;
   int nRet;   //関数の戻り値
   int nAdrsTbl[2];         // 機器アドレステーブル
   char szData[2][1024];  // グローバル変数 : 受信バッファ
   //nはチャンネル番号を表わすようにしています。
//---------------------------------------------------------------------------
//ボードのオープン
void BoardOpen()
{
   nRet=PciGpibExInitBoard(ulBoardNo,0);
   if(nRet !=GPIB_SUCCESS){
//   winuser.h(8941): candidate function not viable: no known conversion from 'const char [22]' to 'LPCWSTR' (aka 'const wchar_t *') for 2nd argument
//	  MessageBox(0,"エラー(Board Open-01)"),"",MB_OK);
	  MessageBox(0,L"エラー(Board Open-01)",L"",MB_OK);
	  return;
   }

   //GP-IBインタフェースの初期化
   nRet=PciGpibExSetIfc(ulBoardNo, 1);
   if(nRet !=GPIB_SUCCESS){
	  MessageBox(0,L"エラー(Board Open-02)",L"",MB_OK);
      return;
   }
   nRet=PciGpibExSetRen(ulBoardNo);
   if(nRet !=GPIB_SUCCESS){
	  MessageBox(0,L"エラー(Board Open-03)",L"",MB_OK);
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
	  MessageBox(0,L"エラー(Board Close)",L"",MB_OK);
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
   nRet=PciGpibExMastSendData(0, nAdrsTbl, strlen("V3 X"), "V3 X", 0);  //V-LIMITの値
   if(nRet !=GPIB_SUCCESS){
		 MessageBox(0,L"エラー(GPIB:04-reset)",L"",MB_OK);
         return;
   }
   
   nAdrsTbl[0] = 07;        // 制御する測定機器のアドレス
   nAdrsTbl[1] = -1;        // アドレステーブルの終端
   nRet=PciGpibExMastSendData(0, nAdrsTbl, strlen("*RST"), "*RST", 0);
   if(nRet !=GPIB_SUCCESS){
		 MessageBox(0,L"エラー(GPIB:07-reset2)",L"",MB_OK);
         return;
   }
   nRet=PciGpibExMastSendData(0, nAdrsTbl, strlen("*CLS"), "*CLS", 0);
   if(nRet !=GPIB_SUCCESS){
		 MessageBox(0,L"エラー(GPIB:07-reset2)",L"",MB_OK);
         return;
   }
}
//---------------------------------------------------------------------------

//チャンネルの選択(GPIB:07)
void channel(int n)
{
   nAdrsTbl[0] = 07;        // 制御する測定機器のアドレス
   nAdrsTbl[1] = -1;        // アドレステーブルの終端

   nRet=PciGpibExMastSendData(0, nAdrsTbl,strlen(":open all"),":open all", 0);
   if(nRet !=GPIB_SUCCESS){
		 MessageBox(0,L"エラー(GPIB:07-1)",L"",MB_OK);
         return;
   }
   char * chan;
   if(n==0)chan=":close (@1!1)";
   if(n==1)chan=":close (@1!2)";
   if(n==2)chan=":close (@1!3)";
   if(n==3)chan=":close (@1!4)";
   if(n==4)chan=":close (@1!5)";
   int SLch;
     SLch=strlen(chan);
   
   nRet=PciGpibExMastSendData(0, nAdrsTbl, SLch, chan, 0);
   if(nRet !=GPIB_SUCCESS){
		 MessageBox(0,L"エラー(GPIB:07-2)",L"",MB_OK);
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
	  MessageBox(0,L"エラー(GPIB:04-1)",L"",MB_OK);
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
	  MessageBox(0,L"エラー(GPIB:04-2)",L"",MB_OK);
      return;
   }
}
//---------------------------------------------------------------------------

//電圧値を表示する。(GPIB:02)
void VoltDisplay(int i)
{
   nAdrsTbl[0] = 02;        // 制御する測定機器のアドレス
   nAdrsTbl[1] = -1;        // アドレステーブルの終端
   //送受信タイムアウト"/TMO=" (1～65535)、非同期入出力設定 "/ASYNC="
//   nRet=PciGpibExSetConfig(ulBoardNo,"/TMO=200 /ASYNC=ON");
   char * measurevolt="READ?";
   int    SLmeasvol=strlen(measurevolt);
   nRet=PciGpibExMastSendData(0, nAdrsTbl, SLmeasvol, measurevolt, 0);
   if(nRet !=GPIB_SUCCESS){
	  MessageBox(0,L"エラー(GPIB:02-1)",L"",MB_OK);
      return;
   }

   DWORD dwLen;         // 受信バッファ長を格納、API呼び出し後には実際の受信データ長が格納される
   dwLen = 1024;          // 受信バッファのサイズ
   //電圧値を読み取り表示
   nRet=PciGpibExMastRecvData(0, nAdrsTbl, &dwLen, szData[i], 0);
   if(nRet !=GPIB_SUCCESS){
	  MessageBox(0,L"エラー(GPIB:02-2)",L"",MB_OK);
      return;
   }
}
//---------------------------------------------------------------------------

