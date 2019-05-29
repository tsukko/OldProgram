//---------------------------------------------------------------------------

#include <vcl.h>
//#pragma hdrstop
#include <stdio.h>
#include <math.hpp>
#include <fstream>
#include <Filectrl.hpp>  //�f�B���N�g���쐬�̂��߂����ɂ���

#include "GmDataConversion.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ChangeFile_RAW(AnsiString FileName)
{
    StatusBar1->Panels->Items[0]->Text="�ϊ��n�߂܂�";
    ifstream rrr;
    ofstream www;

//    AnsiString date=ExtractFileName(FileName.c_str()).SubString(1,ExtractFileName(FileName.c_str()).AnsiPos("_RAW_up.txt"));
//    AnsiString Path = ExtractFilePath(FileName.c_str());
    String date=ExtractFileName(FileName.c_str()).SubString(1,ExtractFileName(FileName.c_str()).Pos("_RAW_up.txt"));
    String Path = ExtractFilePath(FileName.c_str());
    rrr.open(FileName.c_str());
    char SampleName[512];
//    AnsiString TempSampleName;
//    AnsiString SaNe[10];    //�T���v���̖��O�B�v�f�̐��͉���MaxSampleNum�Ɠ���
    String TempSampleName;
    String SaNe[10];    //�T���v���̖��O�B�v�f�̐��͉���MaxSampleNum�Ɠ���
    int MaxSampleNum=10;    //�ő�4ch*2+5ch+���x��10��
    int SampleNum;    //�T���v���̐�
    int PointNum=0; //����_�̐�
    int PosNeg=2;    //������̃f�[�^������̂�

    //��s�ځA�T���v���l�[���̎��o��
    rrr.getline(SampleName,sizeof(SampleName));
//    TempSampleName=AnsiString(SampleName)+"\t";
    TempSampleName=String(SampleName)+"\t";
    int y=0;
    for(int i=0;i<MaxSampleNum;i++){
//        y=TempSampleName.AnsiPos("\t");
        y=TempSampleName.Pos("\t");
        SaNe[i]=TempSampleName.SubString(1,y-1);
        TempSampleName.Delete(1,y);
        if(TempSampleName==""){
            SampleNum=i;
            break;
        }
    }

    //�f�[�^�̎��o��
    data.clear();
    data.resize(1024);
    resis.clear();
    resis.resize(1024);
    while(!rrr.eof()){
        data[PointNum].resize(SampleNum+1);
        resis[PointNum].resize(SampleNum+1);
        for(int t=0;t<(SampleNum+1)/2;t++){
            data[PointNum][t].resize(PosNeg);
            rrr >> data[PointNum][t][0];
            rrr >> data[PointNum][t][1];
            if(t==(SampleNum+1)/2-1)    //�Z���ł��邪�킩��₷�����邽��
                resis[PointNum][t]=data[PointNum][t][1];
            else //if(SaNe[t]="ch1-")
                resis[PointNum][t]=(data[PointNum][t][0]-data[PointNum][t][1])/2;
        }
        PointNum++;
    }
    rrr.close();

    //�������ށB�T���v���̐����J��Ԃ�
    for(int i=0;i<SampleNum/2;i++){
        www.open((Path+date+SaNe[2*i]+".dat").c_str());
//        www << (SaNe[2*i]+"\t"+SaNe[SampleNum]+"\n").c_str();
        www << "Resistance [\\fW]";
        www << "\t";
        www << "Temperature [K]";
        www << "\n";
        for(int q=0;q<PointNum-1;q++){
            www << resis[q][i];
            www << "\t";
            www << resis[q][(SampleNum-1)/2];
            www << "\n";
        }
        www.close();
    }
    StatusBar1->Panels->Items[0]->Text="�ϊ��I��";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ChangeFile_up(AnsiString FileName)
{
    StatusBar1->Panels->Items[0]->Text="�ϊ��n�߂܂�";
    ifstream rrr;
    ofstream www;

//    AnsiString date=ExtractFileName(FileName.c_str()).SubString(1,ExtractFileName(FileName.c_str()).AnsiPos("_up.txt"));
//    AnsiString Path = ExtractFilePath(FileName.c_str());
    String date=ExtractFileName(FileName.c_str()).SubString(1,ExtractFileName(FileName.c_str()).Pos("_up.txt"));
    String Path = ExtractFilePath(FileName.c_str());
    rrr.open(FileName.c_str());
    char SampleName[512];
//    AnsiString TempSampleName;
//    AnsiString SaNe[5];    //�T���v���̖��O�B�v�f�̐��͉���MaxSampleNum�Ɠ���
    String TempSampleName;
    String SaNe[5];    //�T���v���̖��O�B�v�f�̐��͉���MaxSampleNum�Ɠ���
    int MaxSampleNum=5;    //�ő�4ch+���x��5��
    int SampleNum;    //�T���v���̐�
    int PointNum=0; //����_�̐�

    //��s�ځA�T���v���l�[���̎��o��
    rrr.getline(SampleName,sizeof(SampleName));
//    TempSampleName=AnsiString(SampleName)+"\t";
    TempSampleName=String(SampleName)+"\t";
    int y=0;
    for(int i=0;i<MaxSampleNum;i++){
//        y=TempSampleName.AnsiPos("\t");
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
//        www << (SaNe[i]+"\t"+SaNe[SampleNum]+"\n").c_str();
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
    StatusBar1->Panels->Items[0]->Text="�ϊ��I��";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ChangeFileSQUID_TM(AnsiString FileName)
{
    StatusBar1->Panels->Items[0]->Text="�ϊ��n�߂܂�";
    ifstream rrr;
    ofstream www;

//    AnsiString DectName = ExtractFileName(FileName.c_str()).SubString(1,ExtractFileName(FileName.c_str()).AnsiPos(".dc.dat"));
//    AnsiString Path = ExtractFilePath(FileName.c_str());
//    AnsiString NewDirectory=Path+DectName;
    String DectName = ExtractFileName(FileName.c_str()).SubString(1,ExtractFileName(FileName.c_str()).Pos(".dc.dat"));
    String Path = ExtractFilePath(FileName.c_str());
    String NewDirectory=Path+DectName;
    int PointNum=0; //����_�̐�

    char SampleName[512];
//    AnsiString SampleNa;
    String SampleNa;
    char SampleWeight[32];
//    AnsiString SampleW;
    String SampleW;
    char SampleData[1024];
//    AnsiString SampleD;
    String SampleD;
    rrr.open(FileName.c_str());
//    for(int i=0;i<6;i++)    //6�s13��ڂ���T���v�����A7�s15��ڂ���T���v����
    for(int i=0;i<8;i++)    //8�s13��ڂ���T���v�����A9�s15��ڂ��玿��
        rrr.getline(SampleName,sizeof(SampleName));
    SampleNa=String(SampleName).SubString(13,StrLen(SampleName));
    rrr.getline(SampleWeight,sizeof(SampleWeight));
    SampleW=String(SampleWeight).SubString(15,StrLen(SampleWeight));
//    for(int i=0;i<17;i++)    //6�s13��ڂ���T���v����
	for(int i=0;i<22;i++)    //9+22�s�ڂ���f�[�^
        rrr.getline(SampleData,sizeof(SampleData));

    SQUIDData.clear();
    SQUIDData.resize(3);
    SQUIDData[0].resize(1024);
    SQUIDData[1].resize(1024);
	SQUIDData[2].resize(1024);
    while(!rrr.eof()){
		rrr.getline(SampleData,sizeof(SampleData));
		SampleD=String(SampleData);
        int y=0;
        for(int q=0;q<7;q++){
//            y=SampleD.AnsiPos(",");
			y=SampleD.Pos(",");
            if(q==2)            //Field (Oe)
                SQUIDData[0][PointNum]=SampleD.SubString(1,y-1);
            if(q==3)            //Temperature (K)
				SQUIDData[1][PointNum]=SampleD.SubString(1,y-1);
            if(q==4)            //Long Moment (EMU)
                SQUIDData[2][PointNum]=SampleD.SubString(1,y-1);
            SampleD.Delete(1,y);
        }
        PointNum++;
    }

    //�V�����f�B���N�g�������B�����ɕϊ���̃t�@�C����u���B
    if (!DirectoryExists(NewDirectory))
    {
        if (!CreateDir(NewDirectory))
            throw Exception("Cannot create "+NewDirectory);
    }

    //��������
	www.open((NewDirectory+"\\"+SampleNa+"(w="+SampleW+"mg,"+SQUIDData[0][0]+"Oe)"+".dat").c_str());
	if(!CheckBox1->Checked){    //ZFC��FC������ꍇ
		www << "Temperature [K]";
		www << "\t";
		www << "Long Moment [EMU/g]";
		www << "\t";
		www << "Temperature [K]";
		www << "\t";
		www << "Long Moment [EMU/g]";
		www << "\n";
		for(int i=0;i<(PointNum-1)/2;i++){
			www << SQUIDData[1][i].c_str();
			www << "\t";
			float temp = StrToFloat(SQUIDData[2][i])/StrToFloat(SampleW)*1000;
			www << AnsiString().sprintf("%le", temp);
//            www << FloatToStr(StrToFloat(SQUIDData[2][i])/StrToFloat(SampleW)*1000).c_str();
			www << "\t";
			www << SQUIDData[1][i+(PointNum-1)/2].c_str();
			www << "\t";
			float temp2 = StrToFloat(SQUIDData[2][i+(PointNum-1)/2])/StrToFloat(SampleW)*1000;
			www << AnsiString().sprintf("%le", temp2);
//            www <<    FloatToStr(StrToFloat(SQUIDData[2][i+(PointNum-1)/2])/StrToFloat(SampleW)*1000).c_str();
			www << "\n";
		}
	}
	else{        //ZFC�A��������FC�݂̂̑���̏ꍇ
		www << "Temperature [K]";
		www << "\t";
		www << "Long Moment [EMU/g]";
		www << "\n";
		for(int i=0;i<PointNum-1;i++){
			www << SQUIDData[1][i].c_str();
			www << "\t";
			float temp3 = StrToFloat(SQUIDData[2][i])/StrToFloat(SampleW)*1000;
			www << AnsiString().sprintf("%le", temp3);
//			www << FloatToStr(StrToFloat(SQUIDData[2][i])/StrToFloat(SampleW)*1000).c_str();
			www << "\n";
		}
	}
    www.close();

    StatusBar1->Panels->Items[0]->Text="�ϊ��I�� "+ExtractFileName(FileName.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ChangeFileSQUID_HM(AnsiString FileName)
{
    StatusBar1->Panels->Items[0]->Text="�ϊ��n�߂܂�";
    ifstream rrr;
    ofstream www;

//    AnsiString DectName = ExtractFileName(FileName.c_str()).SubString(1,ExtractFileName(FileName.c_str()).AnsiPos(".dc.dat"));
//    AnsiString Path = ExtractFilePath(FileName.c_str());
//    AnsiString NewDirectory=Path+DectName;
    String DectName = ExtractFileName(FileName.c_str()).SubString(1,ExtractFileName(FileName.c_str()).Pos(".dc.dat"));
    String Path = ExtractFilePath(FileName.c_str());
    String NewDirectory=Path+DectName;
    int PointNum=0; //����_�̐�
    int x1[10]={0},x2[10]={0},uuuuu=0;    //����܂�Ԃ��_�Ƃ��̊Ԃ̓_���A�܂�Ԃ��̉�

    char SampleName[512];
//    AnsiString SampleNa;
    String SampleNa;
    char SampleWeight[32];
//    AnsiString SampleW;
    String SampleW;
    char SampleData[1024];
//    AnsiString SampleD;
    String SampleD;
    rrr.open(FileName.c_str());
//    for(int i=0;i<6;i++)    //6�s13��ڂ���T���v�����A7�s15��ڂ���T���v����
    for(int i=0;i<8;i++)    //8�s13��ڂ���T���v�����A9�s15��ڂ��玿��
        rrr.getline(SampleName,sizeof(SampleName));
    SampleNa=String(SampleName).SubString(13,StrLen(SampleName));
    rrr.getline(SampleWeight,sizeof(SampleWeight));
    SampleW=String(SampleWeight).SubString(15,StrLen(SampleWeight));
//    for(int i=0;i<17;i++)    //6�s13��ڂ���T���v����
    for(int i=0;i<22;i++)    //9+22�s�ڂ���f�[�^
        rrr.getline(SampleData,sizeof(SampleData));

    SQUIDData.clear();
    SQUIDData.resize(3);
    SQUIDData[0].resize(1024);
    SQUIDData[1].resize(1024);
    SQUIDData[2].resize(1024);
    while(!rrr.eof()){
        rrr.getline(SampleData,sizeof(SampleData));
        SampleD=String(SampleData);
        int y=0;
        for(int q=0;q<7;q++){
//            y=SampleD.AnsiPos(",");
            y=SampleD.Pos(",");
            if(q==2)            //Field (Oe)
                SQUIDData[0][PointNum]=SampleD.SubString(1,y-1);
            if(q==3)            //Temperature (K)
                SQUIDData[1][PointNum]=SampleD.SubString(1,y-1);
            if(q==4)            //Long Moment (EMU)
                SQUIDData[2][PointNum]=SampleD.SubString(1,y-1);
            SampleD.Delete(1,y);
        }

        //����̐܂�Ԃ��_��T��
        if(!CheckBox1->Checked && PointNum>1 && SQUIDData[0][PointNum]!=""){
            if(fmod(uuuuu,2)){
                if(StrToFloat(SQUIDData[0][PointNum])>StrToFloat(SQUIDData[0][PointNum-1])){
                    uuuuu++;
                    x1[uuuuu]=PointNum-1;    //����܂�Ԃ��_
                    x2[uuuuu]=x1[uuuuu]-x1[uuuuu-1]; //���̊Ԃ̓_��
                }
            }
            if(!fmod(uuuuu,2)){
                if(StrToFloat(SQUIDData[0][PointNum])<StrToFloat(SQUIDData[0][PointNum-1])){
                    uuuuu++;
                    x1[uuuuu]=PointNum-1;
                    x2[uuuuu]=x1[uuuuu]-x1[uuuuu-1];
                }
            }
        }
        PointNum++;
    }
    uuuuu++;
    x1[uuuuu]=PointNum-1;
    x2[uuuuu]=x1[uuuuu]-x1[uuuuu-1];

    //�V�����f�B���N�g�������B�����ɕϊ���̃t�@�C����u���B
    if (!DirectoryExists(NewDirectory))
    {
        if (!CreateDir(NewDirectory))
            throw Exception("Cannot create "+NewDirectory);
    }

    //��������
    www.open((NewDirectory+"\\"+SampleNa+"(w="+SampleW+"mg,"+SQUIDData[1][0]+"K)"+".dat").c_str());
    if(!CheckBox1->Checked){    //
        for(int ttt=0;ttt<uuuuu-1;ttt++){
            www << "Field [Oe]";
            www << "\t";
            www << "Long Moment [EMU/g]";
            www << "\t";
        }
        www << "Field [Oe]";
        www << "\t";
        www << "Long Moment [EMU/g]";
        www << "\n";

        int rrr=0;
        for(int r=0;r<10;r++){
            rrr=std::max(rrr,x2[r]);
        }

        for(int i=0;i<rrr;i++){
            for(int ttt=0;ttt<uuuuu-1;ttt++){
                if(i<x2[ttt+1]){
                    www << SQUIDData[0][x2[ttt]+i].c_str();
					www << "\t";
					float temp = StrToFloat(SQUIDData[2][x2[ttt]+i])/StrToFloat(SampleW)*1000;
					www << AnsiString().sprintf("%le", temp);
//					www << FloatToStr(StrToFloat(SQUIDData[2][x2[ttt]+i])/StrToFloat(SampleW)*1000).c_str();
					www << "\t";
                }
                else if(x2[ttt+1]){
                    www << "\t\t";
                }
            }
            if(i<x2[uuuuu]){
                www << SQUIDData[0][x1[uuuuu-1]+i].c_str();
                www << "\t";
				float temp = StrToFloat(SQUIDData[2][x1[uuuuu-1]+i])/StrToFloat(SampleW)*1000;
				www << AnsiString().sprintf("%le", temp);
//				www << FloatToStr(StrToFloat(SQUIDData[2][x1[uuuuu-1]+i])/StrToFloat(SampleW)*1000).c_str();
				www << "\n";
			}
            else if(x2[uuuuu]){
                www << "\t\n";
            }
        }
    }
    else{
        www << "Field [Oe]";
        www << "\t";
        www << "Long Moment [EMU/g]";
        www << "\n";
        for(int i=0;i<PointNum-1;i++){
			www << SQUIDData[0][i].c_str();
			www << "\t";
			float temp = StrToFloat(SQUIDData[2][i])/StrToFloat(SampleW)*1000;
			www << AnsiString().sprintf("%le", temp);
//			www << FloatToStr(StrToFloat(SQUIDData[2][i])/StrToFloat(SampleW)*1000).c_str();
			www << "\n";
        }
    }
    www.close();

    StatusBar1->Panels->Items[0]->Text="�ϊ��I�� "+ExtractFileName(FileName.c_str());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
/*
    AnsiString currStr[]={"1e-3",
                        "1e-4",
                        "1e-5",
                        "1e-6",
                        "1e-9"};

    TStringList *TempList = new TStringList; // ���X�g��錾����
    try{
        for(int y=0;y<sizeof(currStr)/4;y++)
            TempList->Add(currStr[y]);
        ComboBox1->Items->AddStrings(TempList);
        ComboBox2->Items->AddStrings(TempList);
        ComboBox3->Items->AddStrings(TempList);
        ComboBox4->Items->AddStrings(TempList);
        ComboBox5->Items->AddStrings(TempList);
    }
    finally{
        delete TempList; // ���X�g�I�u�W�F�N�g��j������
    }
    ComboBox1->ItemIndex=3;
    ComboBox2->ItemIndex=3;
    ComboBox3->ItemIndex=3;
    ComboBox4->ItemIndex=3;
    ComboBox5->ItemIndex=2;
*/

    DragAcceptFiles(Handle, True); //�h���b�O&�h���b�v��L���ɂ���
    StatusBar1->Panels->Items[0]->Text="�h���b�O���h���b�v�ł��܂��B";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ReceiveDropFiles(TWMDropFiles Message)
{
//    HDROP &Drop = (HDROP)Message.Drop;                                        //Message.Drop �ւ̃G�C���A�X
//    int Files = DragQueryFile(Drop, 0xFFFFFFFF, NULL, 0); //�h���b�v���ꂽ�t�@�C�����̎擾
////    StatusBar1->SimpleText = " �t�@�C���� "+ IntToStr(Files)+" ��";//�X�e�[�^�X�o�[�Ƀt�@�C������\��
//
//    for (int n = 0; n < Files; n++){                        //�t�@�C�������J��Ԃ�
//    const int NameMax = 1024;                                    //�t�@�C�����p�̃o�b�t�@�[�T�C�Y (�����傫�߂ɂ��Ă���)
//    char FileName[NameMax + 10];                            //�t�@�C�����p�̃o�b�t�@�[ (�o�O/�~�X�̗\�h�ɁA���o�C�g�̗]�T���������Ă���)
//    DragQueryFile(Drop, n, FileName, NameMax); //�t�@�C�������擾
//        if(TabControl1->TabIndex==0)        ChangeFileSQUID_TM(FileName);
//    else if(TabControl1->TabIndex==1)ChangeFileSQUID_HM(FileName);
//    else if(TabControl1->TabIndex==2)ChangeFile_up(FileName);
//    else if(TabControl1->TabIndex==3)ChangeFile_RAW(FileName);
//    }
//    DragFinish(Drop); //�n���h�����g�p���Ă��郁�����[�����
    int fileCount;
    wchar_t fileName[MAX_PATH + 10]; // 10: �]���Ɏ��

    Application->BringToFront();
    memset(fileName, 0, sizeof(fileName));

    fileCount=(int)DragQueryFile((HDROP)Message.Drop,    0xffffffff, NULL, MAX_PATH);

    for(int i=0; i < fileCount; i++){
        DragQueryFile((HDROP)Message.Drop, i, fileName, MAX_PATH);
        if(TabControl1->TabIndex==0) ChangeFileSQUID_TM(fileName);
        else if(TabControl1->TabIndex==1) ChangeFileSQUID_HM(fileName);
        else if(TabControl1->TabIndex==2) ChangeFile_up(fileName);
        else if(TabControl1->TabIndex==3) ChangeFile_RAW(fileName);
    }

    DragFinish((HDROP)Message.Drop);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TabControl1Change(TObject *Sender)
{
    if(TabControl1->TabIndex==0 || TabControl1->TabIndex==1)CheckBox1->Visible=true;
    else CheckBox1->Visible=false;

}
//---------------------------------------------------------------------------
