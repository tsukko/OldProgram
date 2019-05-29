//GPIB:02���Model2182	�`�����l����ς��鑕�u
//GPIB:04���Model220 programmable �`�`	�d���𗬂����u
//GPIB:07���Model7001	�d��(��R)��\�����鑕�u
/*
//�{�[�h�̃I�[�v��:	BoardOpen();
//�{�[�h�̃N���[�Y:	BoardClose();
//�Ȃ��ł���{�[�h��������:	resetboard();
//�`�����l���̑I��(�N���[�Y)(GPIB:07):	 channel(int i);
//�d���l�̕ύX(GPIB:04):	ChangeCurrent(char * current);
//�d����off(GPIB:04):	CurrentOff();
//���d���̓d���l��\������B(GPIB:02):	 PVoltDisplay();
//���d���̓d���l��\������B(GPIB:02):	 MVoltDisplay();
*/
//---------------------------------------------------------------------------

//#include <gpc4304.h>
#include "dll\Include\FBISeries\Gpc4304.h"
//---------------------------------------------------------------------------

   HANDLE    device; // �f�o�C�X�n���h��
   const int ulBoardNo = 00 ;
   int nRet;   //�֐��̖߂�l
   int nAdrsTbl[2];         // �@��A�h���X�e�[�u��
   char szData[2][1024];  // �O���[�o���ϐ� : ��M�o�b�t�@
   //n�̓`�����l���ԍ���\�킷�悤�ɂ��Ă��܂��B
//---------------------------------------------------------------------------
//�{�[�h�̃I�[�v��
void BoardOpen()
{
   nRet=PciGpibExInitBoard(ulBoardNo,0);
   if(nRet !=GPIB_SUCCESS){
//   winuser.h(8941): candidate function not viable: no known conversion from 'const char [22]' to 'LPCWSTR' (aka 'const wchar_t *') for 2nd argument
//	  MessageBox(0,"�G���[(Board Open-01)"),"",MB_OK);
	  MessageBox(0,L"�G���[(Board Open-01)",L"",MB_OK);
	  return;
   }

   //GP-IB�C���^�t�F�[�X�̏�����
   nRet=PciGpibExSetIfc(ulBoardNo, 1);
   if(nRet !=GPIB_SUCCESS){
	  MessageBox(0,L"�G���[(Board Open-02)",L"",MB_OK);
      return;
   }
   nRet=PciGpibExSetRen(ulBoardNo);
   if(nRet !=GPIB_SUCCESS){
	  MessageBox(0,L"�G���[(Board Open-03)",L"",MB_OK);
      return;
   }
}
//---------------------------------------------------------------------------

//�{�[�h�̃N���[�Y
void BoardClose()
{
   //�{�[�h����
   nRet=PciGpibExFinishBoard(0);
   if(nRet !=GPIB_SUCCESS){
	  MessageBox(0,L"�G���[(Board Close)",L"",MB_OK);
      return;
   }
}
//---------------------------------------------------------------------------

//�Ȃ��ł���{�[�h��������
void resetboard()
{
   nAdrsTbl[0] = 02;        // ���䂷�鑪��@��̃A�h���X
   nAdrsTbl[1] = -1;        // �A�h���X�e�[�u���̏I�[
   PciGpibExMastSendData(0, nAdrsTbl, strlen("*RST"), "*RST", 0);
   PciGpibExMastSendData(0, nAdrsTbl, strlen("*CLS"), "*CLS", 0);
   PciGpibExMastSendData(0, nAdrsTbl, strlen("SENSe:VOLT:DIGIts 8"), "SENSe:VOLT:DIGIts 8", 0);
   PciGpibExMastSendData(0, nAdrsTbl, strlen("SENSe:VOLT:LPASs:STAT ON"), "SENSe:VOLT:LPASs:STAT ON", 0);
   PciGpibExMastSendData(0, nAdrsTbl, strlen("SENSe:VOLT:DFILter:STAT OFF"), "SENSe:VOLT:DFILter:STAT OFF", 0);

   nAdrsTbl[0] = 04;        // ���䂷�鑪��@��̃A�h���X
   nAdrsTbl[1] = -1;        // �A�h���X�e�[�u���̏I�[
   nRet=PciGpibExMastSendData(0, nAdrsTbl, strlen("V3 X"), "V3 X", 0);  //V-LIMIT�̒l
   if(nRet !=GPIB_SUCCESS){
		 MessageBox(0,L"�G���[(GPIB:04-reset)",L"",MB_OK);
         return;
   }
   
   nAdrsTbl[0] = 07;        // ���䂷�鑪��@��̃A�h���X
   nAdrsTbl[1] = -1;        // �A�h���X�e�[�u���̏I�[
   nRet=PciGpibExMastSendData(0, nAdrsTbl, strlen("*RST"), "*RST", 0);
   if(nRet !=GPIB_SUCCESS){
		 MessageBox(0,L"�G���[(GPIB:07-reset2)",L"",MB_OK);
         return;
   }
   nRet=PciGpibExMastSendData(0, nAdrsTbl, strlen("*CLS"), "*CLS", 0);
   if(nRet !=GPIB_SUCCESS){
		 MessageBox(0,L"�G���[(GPIB:07-reset2)",L"",MB_OK);
         return;
   }
}
//---------------------------------------------------------------------------

//�`�����l���̑I��(GPIB:07)
void channel(int n)
{
   nAdrsTbl[0] = 07;        // ���䂷�鑪��@��̃A�h���X
   nAdrsTbl[1] = -1;        // �A�h���X�e�[�u���̏I�[

   nRet=PciGpibExMastSendData(0, nAdrsTbl,strlen(":open all"),":open all", 0);
   if(nRet !=GPIB_SUCCESS){
		 MessageBox(0,L"�G���[(GPIB:07-1)",L"",MB_OK);
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
		 MessageBox(0,L"�G���[(GPIB:07-2)",L"",MB_OK);
         return;
   }
}
//---------------------------------------------------------------------------

//�d���l������B(GPIB:04)
void ChangeCurrent(char * current)
{
   nAdrsTbl[0] = 04;        // ���䂷�鑪��@��̃A�h���X
   nAdrsTbl[1] = -1;        // �A�h���X�e�[�u���̏I�[
   int    SLcurr;
   SLcurr=strlen(current);
   nRet= PciGpibExMastSendData(0, nAdrsTbl, SLcurr, current, 0);    //�d���l
   if(nRet !=GPIB_SUCCESS){
	  MessageBox(0,L"�G���[(GPIB:04-1)",L"",MB_OK);
      return;
   }
}
//---------------------------------------------------------------------------

//�d����off(GPIB:04)
void CurrentOff()
{
   nAdrsTbl[0] = 04;        // ���䂷�鑪��@��̃A�h���X
   nAdrsTbl[1] = -1;        // �A�h���X�e�[�u���̏I�[
   nRet= PciGpibExMastSendData(0, nAdrsTbl, strlen("F0 X"), "F0 X", 0);
   if(nRet !=GPIB_SUCCESS){
	  MessageBox(0,L"�G���[(GPIB:04-2)",L"",MB_OK);
      return;
   }
}
//---------------------------------------------------------------------------

//�d���l��\������B(GPIB:02)
void VoltDisplay(int i)
{
   nAdrsTbl[0] = 02;        // ���䂷�鑪��@��̃A�h���X
   nAdrsTbl[1] = -1;        // �A�h���X�e�[�u���̏I�[
   //����M�^�C���A�E�g"/TMO=" (1�`65535)�A�񓯊����o�͐ݒ� "/ASYNC="
//   nRet=PciGpibExSetConfig(ulBoardNo,"/TMO=200 /ASYNC=ON");
   char * measurevolt="READ?";
   int    SLmeasvol=strlen(measurevolt);
   nRet=PciGpibExMastSendData(0, nAdrsTbl, SLmeasvol, measurevolt, 0);
   if(nRet !=GPIB_SUCCESS){
	  MessageBox(0,L"�G���[(GPIB:02-1)",L"",MB_OK);
      return;
   }

   DWORD dwLen;         // ��M�o�b�t�@�����i�[�AAPI�Ăяo����ɂ͎��ۂ̎�M�f�[�^�����i�[�����
   dwLen = 1024;          // ��M�o�b�t�@�̃T�C�Y
   //�d���l��ǂݎ��\��
   nRet=PciGpibExMastRecvData(0, nAdrsTbl, &dwLen, szData[i], 0);
   if(nRet !=GPIB_SUCCESS){
	  MessageBox(0,L"�G���[(GPIB:02-2)",L"",MB_OK);
      return;
   }
}
//---------------------------------------------------------------------------

