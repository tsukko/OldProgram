//---------------------------------------------------------------------------
#include <math.hpp>
#include <Teestore.hpp>
#include <fstream>
#include <iostream>
#include <vcl.h>
#pragma hdrstop

#include "PlotTrigonometricFunction.h"
#include "PlotTrigonometricFunction2.h"
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
TMemoryStream *MeSt1= new TMemoryStream();
TMemoryStream *MeSt2= new TMemoryStream();

//グラフに書き出される式の計算を行う関数。
float y(float x,float a,float b){
    float y;
    switch(Form1->FunctionRadioGroup->ItemIndex){
        case 0:
            y=sin(x);
            break;
        case 1:
            y=cos(x);
            break;
        case 2:
            y=tan(x);
            break;
        case 3:
            y=a*x*sin(b*x);
            break;
        case 4:
            y=sinh(x);
            break;
        case 5:
            y=cosh(x);
            break;
        case 6:
            y=tanh(x);
            break;
    }
    return y;
}

//ChartのグラフとMemoryStreamを消す関数。
void ClearF()
{
    Form1->GraphChart->Series[0]->Clear();
    Form1->GraphChart->Series[1]->Clear();
    MeSt1->Clear();
}

//グラフのy軸の最大最小を、yの最大最小にあわせる関数。
//yの範囲のTextを変える。と、Chartの軸も勝手に変わる。
void  AutoSizeF()
{
    if(Form1->SizeCheckBox->Checked==true){
        Form1->GraphChart->BottomAxis->Automatic=true;
        Form1->GraphChart->LeftAxis->Automatic=true;
        Form1->GraphChart->RightAxis->Automatic=true;
        switch(Form1->RadioGroup1->ItemIndex){
            //前のグラフのyの最小値より今のグラフのｙの最大値が小さいとエラーがでる。出てしまう？
            case 0:
                Form1->XMaxEdit->Text=Form1->GraphChart->Series[0]->MaxXValue();
                Form1->XMinEdit->Text=Form1->GraphChart->Series[0]->MinXValue();
                Form1->YMaxEdit->Text=Form1->GraphChart->Series[0]->MaxYValue();
                Form1->YMinEdit->Text=Form1->GraphChart->Series[0]->MinYValue();
            break;
            case 1:     
                Form1->XMaxEdit->Text=Form1->GraphChart->Series[1]->MaxXValue();
                Form1->XMinEdit->Text=Form1->GraphChart->Series[1]->MinXValue();
                Form1->YMaxEdit->Text=Form1->GraphChart->Series[1]->MaxYValue();
                Form1->YMinEdit->Text=Form1->GraphChart->Series[1]->MinYValue();
            break;
            case 2:
                Form1->XMaxEdit->Text=Form1->GraphChart->Series[0]->MaxXValue();
                Form1->XMinEdit->Text=Form1->GraphChart->Series[0]->MinXValue();
                Form1->YMaxEdit->Text=Form1->GraphChart->Series[0]->MaxYValue();
                Form1->YMinEdit->Text=Form1->GraphChart->Series[0]->MinYValue();
            break;
        }
    }
    else{
        Form1->GraphChart->BottomAxis->Automatic=false;
        Form1->GraphChart->LeftAxis->Automatic=false;
        Form1->GraphChart->RightAxis->Automatic=false;
    }
}

//初期設定。
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    FunctionRadioGroup->ItemIndex=0;
    RadioGroup1->ItemIndex=0;
    PEdit->Text="200";
}
//---------------------------------------------------------------------------
//それぞれの初期範囲。グラフに描く関数変える。
void __fastcall TForm1::FunctionRadioGroupClick(TObject *Sender)
{
    ClearF();
    aEdit->Visible=false;
    bEdit->Visible=false;
    aLabel->Visible=false;
    bLabel->Visible=false;
    int i=FunctionRadioGroup->ItemIndex;
    if(i==0||i==1||i==6){
        XMinEdit->Text="-6.283";
        XMaxEdit->Text="6.283";
        YMinEdit->Text="-1.00";
        YMaxEdit->Text="1.00";
    }
    if(i==2){
        XMinEdit->Text="-6.283";
        XMaxEdit->Text="6.283";
        YMinEdit->Text="-10";
        YMaxEdit->Text="10";
    }
    if(i==3){
        XMinEdit->Text="-6.283";
        XMaxEdit->Text="6.283";
        YMinEdit->Text="-8";
        YMaxEdit->Text="8";
        aEdit->Visible=true;
        bEdit->Visible=true;
        aLabel->Visible=true;
        bLabel->Visible=true;
        aEdit->Text="2";
        bEdit->Text="0.5";
    }
    if(i==4||i==5){
        XMinEdit->Text="-6.283";
        XMaxEdit->Text="6.283";
        YMinEdit->Text="-300";
        YMaxEdit->Text="300";
    }
    GraphChart->BottomAxis->Minimum=StrToFloat(XMinEdit->Text);     //xの最小(グラフの）
    GraphChart->BottomAxis->Maximum=StrToFloat(XMaxEdit->Text);     //xの最大
    GraphChart->LeftAxis->Minimum=StrToFloat(YMinEdit->Text);       //yの最小
    GraphChart->LeftAxis->Maximum=StrToFloat(YMaxEdit->Text);       //yの最大
    GraphChart->RightAxis->Minimum=StrToFloat(YMinEdit->Text);      //dyの最小
    GraphChart->RightAxis->Maximum=StrToFloat(YMaxEdit->Text);      //dyの最大
    xIncrementEdit->Text=String(GraphChart->BottomAxis->Increment);
    yIncrementEdit->Text=String(GraphChart->LeftAxis->Increment);
    dyIncrementEdit->Text=String(GraphChart->RightAxis->Increment);
}
//---------------------------------------------------------------------------

//Chartにグラフを描く。
void __fastcall TForm1::GraphButtonClick(TObject *Sender)
{
    ClearF();
    float x=0,xmax,ymin,ymax,z,a,b,dy;

	try{
        x=StrToFloat(XMinEdit->Text);           //xの最小
        xmax=StrToFloat(XMaxEdit->Text);        //xの最大
        z=(xmax-x)/(StrToInt(PEdit->Text)-1);   //for文のx軸の増分
        if(FunctionRadioGroup->ItemIndex==3){   //ax*sin(bx)の式の時a,bの値いるので。
            a=StrToFloat(aEdit->Text);
            b=StrToFloat(bEdit->Text);
       }
    }
	catch(Exception &E){
       ShowMessage("値がおかしい");
       Abort();
    }

    if(x>=xmax){      //範囲おかしくないか調べる。必要ないのかも？
       ShowMessage("範囲がおかしい");
       return;
    }

    for(x;x<=xmax;x=x+z){             //最小→最大、ｚずつ、ｎ個の点
        GraphChart->Series[0]->AddXY(x,y(x,a,b),"",clBlue);
        dy=(y(x+z/2,a,b)-y(x-z/2,a,b))/z;
        GraphChart->Series[1]->AddXY(x,dy,"",clGreen);

        //メモリーストリームにデータを書き込む。
        AnsiString datax,datay,datat,datan,datady;
        datax=FormatFloat("0.0000",x);
        datay=FormatFloat("0.0000",y(x,a,b));
        datady=FormatFloat("0.0000",dy);
        datat="\t";
        datan="\n";
        MeSt1->Write(datax.c_str(),7);
        MeSt1->Write(datat.c_str(),1);
        MeSt1->Write(datay.c_str(),7);
        MeSt1->Write(datan.c_str(),1);
        MeSt2->Write(datax.c_str(),7);
        MeSt2->Write(datat.c_str(),1);
        MeSt2->Write(datady.c_str(),7);
        MeSt2->Write(datan.c_str(),1);
    }
    AutoSizeF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClearButtonClick(TObject *Sender)
{
    ClearF();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ExitClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

//点の数空白だとボタン押せない。
void __fastcall TForm1::PEditChange(TObject *Sender)
{
    if(PEdit->Text.Length()<1)
        GraphButton->Enabled=false;
    else GraphButton->Enabled=true;
}
//---------------------------------------------------------------------------

//クリックしないとHintで座標でない？
void __fastcall TForm1::GraphChartMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    float x,y,dy;
    AnsiString c;
    int i=RadioGroup1->ItemIndex;
    x=GraphChart->Series[0]->XScreenToValue(X);
    y=GraphChart->Series[0]->YScreenToValue(Y);
    dy=GraphChart->Series[1]->YScreenToValue(Y);
    if(i==0)
        c=" X "+FormatFloat("0.00",x)+", Y "+FormatFloat("0.00",y);
    if(i==1)
        c=" X "+FormatFloat("0.00",x)+", dY "+FormatFloat("0.00",dy);
    if(i==2)
        c=" X "+FormatFloat("0.00",x)+", Y "+FormatFloat("0.00",y)+", dY "+FormatFloat("0.00",dy);
    GraphChart->Hint=c;
    GraphChart->Title->Text->Text=c;
}
//---------------------------------------------------------------------------

//Editのx軸,y軸の最大値最小値を変えたとき。下の四つ。
void __fastcall TForm1::XMinEditChange(TObject *Sender)
{
	try{
		GraphChart->BottomAxis->Minimum=StrToFloat(XMinEdit->Text);
	}
	catch(Exception &E){
       XMinEdit->Text="0";
       Abort();
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::XMaxEditChange(TObject *Sender)
{
	try{
		GraphChart->BottomAxis->Maximum=StrToFloat(XMaxEdit->Text);
    }
    catch(Exception &E){
        XMaxEdit->Text="0";
        Abort();
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::YMinEditChange(TObject *Sender)
{
	try{
        if(RadioGroup1->ItemIndex==0)      //y
            GraphChart->LeftAxis->Minimum=StrToFloat(YMinEdit->Text);
        if(RadioGroup1->ItemIndex==1)      //dy
            GraphChart->RightAxis->Minimum=StrToFloat(YMinEdit->Text);
        if(RadioGroup1->ItemIndex==2){
            GraphChart->LeftAxis->Minimum=StrToFloat(YMinEdit->Text);
            GraphChart->RightAxis->Minimum=StrToFloat(YMinEdit->Text);
        }
    }
    catch(Exception &E){
        YMinEdit->Text="0";
        Abort();
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::YMaxEditChange(TObject *Sender)
{                                                             
	try{
        if(RadioGroup1->ItemIndex==0)      //y
            GraphChart->LeftAxis->Maximum=StrToFloat(YMaxEdit->Text);
        if(RadioGroup1->ItemIndex==1)      //dy
            GraphChart->RightAxis->Maximum=StrToFloat(YMaxEdit->Text);
        if(RadioGroup1->ItemIndex==2){
            GraphChart->LeftAxis->Maximum=StrToFloat(YMaxEdit->Text);
            GraphChart->RightAxis->Maximum=StrToFloat(YMaxEdit->Text);
        }
    }
    catch(Exception &E){
        YMaxEdit->Text="0";
        Abort();
    }
}
//---------------------------------------------------------------------------


//右クリックの'画像で保存'を押した時。
void __fastcall TForm1::GPopSaveIClick(TObject *Sender)
{
    SaveDialog1->FilterIndex=1;
    SaveDialog1->DefaultExt="*.wmf";
    if(SaveDialog1->Execute())
        GraphChart->SaveToMetafileEnh(SaveDialog1->FileName);
}
//---------------------------------------------------------------------------

//Saveボタンを押してx,yの座標(メモリストリームに書かれた物)をセーブする。
void __fastcall TForm1::SaveButtonClick(TObject *Sender)
{
    SaveDialog1->FilterIndex=2;
    SaveDialog1->DefaultExt="*.dat";
    if(SaveDialog1->Execute()){
        if(RadioGroup1->ItemIndex==0){
            MeSt1->SaveToFile(SaveDialog1->FileName);
        }
        if(RadioGroup1->ItemIndex==1){
            MeSt2->SaveToFile(SaveDialog1->FileName);
        }
        if(RadioGroup1->ItemIndex==2){
            MeSt1->SaveToFile(SaveDialog1->FileName);
            MeSt2->SaveToFile("dy.dat");
        }
    }
}
//---------------------------------------------------------------------------
//Chart上で右クリックして'データの保存'を押したとき。
void __fastcall TForm1::GPopSaveDClick(TObject *Sender)
{
    SaveButton->Click();
}
//---------------------------------------------------------------------------

//データ、x,y座標のロード
void __fastcall TForm1::OpenButtonClick(TObject *Sender)
{
    float x,y;
    int i=0;    //点の数を数えます。
    int p=RadioGroup1->ItemIndex;
    if(p==2)p=0;                 //Seriesが0と1しかないので・・・

    if(OpenDialog1->Execute()){
       ifstream in(OpenDialog1->FileName.c_str());
       if(!in){
          ShowMessage("Cannot open file.");
          Abort();
       }

       GraphChart->Series[p]->Clear();
       do{
          in >> y;
          in >> x;
          GraphChart->Series[p]->AddXY(x,y,"",clBlue);
          i++;
       }while(!in.eof());              //()の中がfalseになるまで？

       in.close();
       PEdit->Text=IntToStr(i-1);
       return;
    }



//    if(OpenDialog1->Execute()){
//        MeSt1->LoadFromFile(OpenDialog1->FileName);
//        MeSt1->Position=0;
//        for(;;){
//            char *strX= new char[0];
//            char *strY= new char[0];
//            AnsiString strT="\t";
//            AnsiString strN="\n";
//            MeSt1->Read(strX,7);
//            MeSt1->Read(strT.c_str(),1);
//            MeSt1->Read(strY,7);
//            MeSt1->Read(strN.c_str(),1);
//            x=StrToFloat(strX);
//            y=StrToFloat(strY);
//            GraphChart->Series[0]->AddXY(x,y,"",clBlue);
//            i++;
//            if(MeSt1->Position>=MeSt1->Size)
//               break;
//        }
//        PEdit->Text=IntToStr(i);
//     }
}
//---------------------------------------------------------------------------
//Chart上で右クリックして'データを開く'を押した時。
void __fastcall TForm1::GPopOpenClick(TObject *Sender)
{
    OpenButton->Click();
}
//---------------------------------------------------------------------------

//ぐらふの点の数を変えるための新しいFormを読み込む。
void __fastcall TForm1::ChangeButtonClick(TObject *Sender)
{
    int PETVal=StrToInt(PEdit->Text);
    if(Form2->PScrollBar->Max<PETVal){
       Form2->PScrollBar->Max=PETVal;
       Form2->PMaxLabel->Caption=PETVal;
    }
    Form2->PointEdit->Text=PEdit->Text;
    Form2->PScrollBar->Position=PETVal;

    Form2->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
    switch(RadioGroup1->ItemIndex){
        case 0:
             YLabel->Caption="yの範囲";
             GraphChart->Series[0]->Active=true;
             GraphChart->Series[1]->Active=false;
        break;
        case 1:
             YLabel->Caption="dyの範囲";
             GraphChart->Series[0]->Active=false;
             GraphChart->Series[1]->Active=true;
        break;
        case 2:
             YLabel->Caption="yの範囲";
             GraphChart->Series[0]->Active=true;
             GraphChart->Series[1]->Active=true;
        break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SizeCheckBoxClick(TObject *Sender)
{
    AutoSizeF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::YLabelClick(TObject *Sender)
{
    switch(Form1->RadioGroup1->ItemIndex){
        case 0:
            Form1->YMinEdit->Text=Form1->GraphChart->Series[0]->MinYValue();
            Form1->YMaxEdit->Text=Form1->GraphChart->Series[0]->MaxYValue();
        break;
        case 1:
            Form1->YMinEdit->Text=Form1->GraphChart->Series[1]->MinYValue();
            Form1->YMaxEdit->Text=Form1->GraphChart->Series[1]->MaxYValue();
        break;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	try{
	   GraphChart->BottomAxis->Increment=StrToFloat(xIncrementEdit->Text);
       GraphChart->LeftAxis->Increment=StrToFloat(yIncrementEdit->Text);
       GraphChart->RightAxis->Increment=StrToFloat(dyIncrementEdit->Text);
    }
    catch(Exception &E){
       xIncrementEdit->Text="0";
       yIncrementEdit->Text="0";
       dyIncrementEdit->Text="0";
       GraphChart->BottomAxis->Increment=0;
       GraphChart->LeftAxis->Increment=0;
       GraphChart->RightAxis->Increment=0;
       Abort();
    }
}
//---------------------------------------------------------------------------

