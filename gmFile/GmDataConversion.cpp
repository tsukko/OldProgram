//---------------------------------------------------------------------------

#include <vcl.h>
//#pragma hdrstop
#include <stdio.h>
#include <math.hpp>
#include <fstream>
#include <Filectrl.hpp>  //ディレクトリ作成のためだけにつけた

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
    StatusBar1->Panels->Items[0]->Text="変換始めます";
    ifstream rrr;
    ofstream www;

//    AnsiString date=ExtractFileName(FileName.c_str()).SubString(1,ExtractFileName(FileName.c_str()).AnsiPos("_RAW_up.txt"));
//    AnsiString Path = ExtractFilePath(FileName.c_str());
    String date=ExtractFileName(FileName.c_str()).SubString(1,ExtractFileName(FileName.c_str()).Pos("_RAW_up.txt"));
    String Path = ExtractFilePath(FileName.c_str());
    rrr.open(FileName.c_str());
    char SampleName[512];
//    AnsiString TempSampleName;
//    AnsiString SaNe[10];    //サンプルの名前。要素の数は下のMaxSampleNumと同じ
    String TempSampleName;
    String SaNe[10];    //サンプルの名前。要素の数は下のMaxSampleNumと同じ
    int MaxSampleNum=10;    //最大4ch*2+5ch+温度の10つ
    int SampleNum;    //サンプルの数
    int PointNum=0; //測定点の数
    int PosNeg=2;    //正負二つのデータがあるので

    //一行目、サンプルネームの取り出し
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

    //データの取り出し
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
            if(t==(SampleNum+1)/2-1)    //短くできるがわかりやすくするため
                resis[PointNum][t]=data[PointNum][t][1];
            else //if(SaNe[t]="ch1-")
                resis[PointNum][t]=(data[PointNum][t][0]-data[PointNum][t][1])/2;
        }
        PointNum++;
    }
    rrr.close();

    //書き込む。サンプルの数分繰り返す
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
    StatusBar1->Panels->Items[0]->Text="変換終了";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ChangeFile_up(AnsiString FileName)
{
    StatusBar1->Panels->Items[0]->Text="変換始めます";
    ifstream rrr;
    ofstream www;

//    AnsiString date=ExtractFileName(FileName.c_str()).SubString(1,ExtractFileName(FileName.c_str()).AnsiPos("_up.txt"));
//    AnsiString Path = ExtractFilePath(FileName.c_str());
    String date=ExtractFileName(FileName.c_str()).SubString(1,ExtractFileName(FileName.c_str()).Pos("_up.txt"));
    String Path = ExtractFilePath(FileName.c_str());
    rrr.open(FileName.c_str());
    char SampleName[512];
//    AnsiString TempSampleName;
//    AnsiString SaNe[5];    //サンプルの名前。要素の数は下のMaxSampleNumと同じ
    String TempSampleName;
    String SaNe[5];    //サンプルの名前。要素の数は下のMaxSampleNumと同じ
    int MaxSampleNum=5;    //最大4ch+温度の5つ
    int SampleNum;    //サンプルの数
    int PointNum=0; //測定点の数

    //一行目、サンプルネームの取り出し
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
    StatusBar1->Panels->Items[0]->Text="変換終了";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ChangeFileSQUID_TM(AnsiString FileName)
{
    StatusBar1->Panels->Items[0]->Text="変換始めます";
    ifstream rrr;
    ofstream www;

//    AnsiString DectName = ExtractFileName(FileName.c_str()).SubString(1,ExtractFileName(FileName.c_str()).AnsiPos(".dc.dat"));
//    AnsiString Path = ExtractFilePath(FileName.c_str());
//    AnsiString NewDirectory=Path+DectName;
    String DectName = ExtractFileName(FileName.c_str()).SubString(1,ExtractFileName(FileName.c_str()).Pos(".dc.dat"));
    String Path = ExtractFilePath(FileName.c_str());
    String NewDirectory=Path+DectName;
    int PointNum=0; //測定点の数

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
//    for(int i=0;i<6;i++)    //6行13列目からサンプル名、7行15列目からサンプル名
    for(int i=0;i<8;i++)    //8行13列目からサンプル名、9行15列目から質量
        rrr.getline(SampleName,sizeof(SampleName));
    SampleNa=String(SampleName).SubString(13,StrLen(SampleName));
    rrr.getline(SampleWeight,sizeof(SampleWeight));
    SampleW=String(SampleWeight).SubString(15,StrLen(SampleWeight));
//    for(int i=0;i<17;i++)    //6行13列目からサンプル名
	for(int i=0;i<22;i++)    //9+22行目からデータ
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

    //新しいディレクトリを作る。そこに変換後のファイルを置く。
    if (!DirectoryExists(NewDirectory))
    {
        if (!CreateDir(NewDirectory))
            throw Exception("Cannot create "+NewDirectory);
    }

    //書き込む
	www.open((NewDirectory+"\\"+SampleNa+"(w="+SampleW+"mg,"+SQUIDData[0][0]+"Oe)"+".dat").c_str());
	if(!CheckBox1->Checked){    //ZFCとFCがある場合
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
	else{        //ZFC、もしくはFCのみの測定の場合
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

    StatusBar1->Panels->Items[0]->Text="変換終了 "+ExtractFileName(FileName.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ChangeFileSQUID_HM(AnsiString FileName)
{
    StatusBar1->Panels->Items[0]->Text="変換始めます";
    ifstream rrr;
    ofstream www;

//    AnsiString DectName = ExtractFileName(FileName.c_str()).SubString(1,ExtractFileName(FileName.c_str()).AnsiPos(".dc.dat"));
//    AnsiString Path = ExtractFilePath(FileName.c_str());
//    AnsiString NewDirectory=Path+DectName;
    String DectName = ExtractFileName(FileName.c_str()).SubString(1,ExtractFileName(FileName.c_str()).Pos(".dc.dat"));
    String Path = ExtractFilePath(FileName.c_str());
    String NewDirectory=Path+DectName;
    int PointNum=0; //測定点の数
    int x1[10]={0},x2[10]={0},uuuuu=0;    //磁場折り返し点とその間の点数、折り返しの回数

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
//    for(int i=0;i<6;i++)    //6行13列目からサンプル名、7行15列目からサンプル名
    for(int i=0;i<8;i++)    //8行13列目からサンプル名、9行15列目から質量
        rrr.getline(SampleName,sizeof(SampleName));
    SampleNa=String(SampleName).SubString(13,StrLen(SampleName));
    rrr.getline(SampleWeight,sizeof(SampleWeight));
    SampleW=String(SampleWeight).SubString(15,StrLen(SampleWeight));
//    for(int i=0;i<17;i++)    //6行13列目からサンプル名
    for(int i=0;i<22;i++)    //9+22行目からデータ
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

        //磁場の折り返し点を探す
        if(!CheckBox1->Checked && PointNum>1 && SQUIDData[0][PointNum]!=""){
            if(fmod(uuuuu,2)){
                if(StrToFloat(SQUIDData[0][PointNum])>StrToFloat(SQUIDData[0][PointNum-1])){
                    uuuuu++;
                    x1[uuuuu]=PointNum-1;    //磁場折り返し点
                    x2[uuuuu]=x1[uuuuu]-x1[uuuuu-1]; //その間の点数
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

    //新しいディレクトリを作る。そこに変換後のファイルを置く。
    if (!DirectoryExists(NewDirectory))
    {
        if (!CreateDir(NewDirectory))
            throw Exception("Cannot create "+NewDirectory);
    }

    //書き込む
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

    StatusBar1->Panels->Items[0]->Text="変換終了 "+ExtractFileName(FileName.c_str());
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

    TStringList *TempList = new TStringList; // リストを宣言する
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
        delete TempList; // リストオブジェクトを破棄する
    }
    ComboBox1->ItemIndex=3;
    ComboBox2->ItemIndex=3;
    ComboBox3->ItemIndex=3;
    ComboBox4->ItemIndex=3;
    ComboBox5->ItemIndex=2;
*/

    DragAcceptFiles(Handle, True); //ドラッグ&ドロップを有効にする
    StatusBar1->Panels->Items[0]->Text="ドラッグ＆ドロップできます。";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ReceiveDropFiles(TWMDropFiles Message)
{
//    HDROP &Drop = (HDROP)Message.Drop;                                        //Message.Drop へのエイリアス
//    int Files = DragQueryFile(Drop, 0xFFFFFFFF, NULL, 0); //ドロップされたファイル数の取得
////    StatusBar1->SimpleText = " ファイル数 "+ IntToStr(Files)+" 個";//ステータスバーにファイル数を表示
//
//    for (int n = 0; n < Files; n++){                        //ファイル数分繰り返す
//    const int NameMax = 1024;                                    //ファイル名用のバッファーサイズ (多少大きめにしている)
//    char FileName[NameMax + 10];                            //ファイル名用のバッファー (バグ/ミスの予防に、数バイトの余裕を持たせている)
//    DragQueryFile(Drop, n, FileName, NameMax); //ファイル名を取得
//        if(TabControl1->TabIndex==0)        ChangeFileSQUID_TM(FileName);
//    else if(TabControl1->TabIndex==1)ChangeFileSQUID_HM(FileName);
//    else if(TabControl1->TabIndex==2)ChangeFile_up(FileName);
//    else if(TabControl1->TabIndex==3)ChangeFile_RAW(FileName);
//    }
//    DragFinish(Drop); //ハンドルが使用しているメモリーを解放
    int fileCount;
    wchar_t fileName[MAX_PATH + 10]; // 10: 余分に取る

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
