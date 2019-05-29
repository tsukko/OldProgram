//---------------------------------------------------------------------------
#include <math.hpp>
#include <vcl.h>
#pragma hdrstop

#include "homework2.h"
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

void __fastcall TForm1::ForButtonClick(TObject *Sender)
{
     static int y=0;

    //九九
    if(y%2!=1){
        Memo1->Lines->Text="for文";
        Memo1->Lines->Add("");
        for(int j=1;j<=9;j++){
            for(int i=0;i<9;i++){
                Memo1->Lines->Text=Memo1->Lines->Text+String((i+1)*j)+"\t";
            }
            Memo1->Lines->Add("");
        }
    }

    //forボタンを偶数回押すと平方根。
    else{
        Memo1->Lines->Text="平方根";
        Memo1->Lines->Add("");
        AnsiString x;
        for(int j=1;j<=9;j++){
            for(int i=0;i<9;i++){
                x=FormatFloat("0.0000",StrToFloat(sqrt((i+1)*j)));
                Memo1->Lines->Text=Memo1->Lines->Text+x+"\t";
            }
            Memo1->Lines->Add("");
        }
    }
    y++;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::WhileButtonClick(TObject *Sender)
{
    Memo1->Lines->Text="while文";
    Memo1->Lines->Add("");

    int j=1;
    while(j<=9){
         int i=1;
        while(i<=9){
            Memo1->Lines->Text=Memo1->Lines->Text+String(i*j)+"\t";
            i++;
        }
        Memo1->Lines->Add("");
        j++;
    }
}
//---------------------------------------------------------------------------

//SaveButtonを押したときか、右クリックで保存を選んだとき。
void __fastcall TForm1::saveExecute(TObject *Sender)
{
    if(SaveDialog1->Execute())
    Memo1->Lines->SaveToFile(SaveDialog1->FileName);
}
//---------------------------------------------------------------------------

//LoadButtonを押したとき、右クリックで読み込みを選んだとき。
void __fastcall TForm1::loadExecute(TObject *Sender)
{
    if(OpenDialog1->Execute())
    Memo1->Lines->LoadFromFile(OpenDialog1->FileName);
}
//---------------------------------------------------------------------------

//ClearButton、右クリック"全消去"
void __fastcall TForm1::clearExecute(TObject *Sender)
{
    Memo1->Clear();
}
//---------------------------------------------------------------------------

//右クリック"終了"
void __fastcall TForm1::EndClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

//課題ｄ)でthisはどのように（どこで）使うのかわからなかった。
