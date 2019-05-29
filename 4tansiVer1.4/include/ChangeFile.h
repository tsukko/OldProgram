//完全に後付けだからややこしくなってる。

#include <fstream>
#include <vector>
//---------------------------------------------------------------------------
class Testest// : public TForm
{
private:	// ユーザー宣言
	 std::vector< std::vector < std::vector < float > > > data ;
	 std::vector< std::vector < float > > resis ;
public:		// ユーザー宣言
     __fastcall Testest(TComponent* Owner);
     void ChangeFile_up(AnsiString FileName);
//コンストラクタとか。。。
};
//---------------------------------------------------------------------------
__fastcall Testest::Testest(TComponent* Owner)
      //  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void Testest::ChangeFile_up(AnsiString FileName)
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
extern PACKAGE Testest *TestFunc;
//---------------------------------------------------------------------------
//#endif
