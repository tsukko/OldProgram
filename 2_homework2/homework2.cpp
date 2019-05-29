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

    //���
    if(y%2!=1){
        Memo1->Lines->Text="for��";
        Memo1->Lines->Add("");
        for(int j=1;j<=9;j++){
            for(int i=0;i<9;i++){
                Memo1->Lines->Text=Memo1->Lines->Text+String((i+1)*j)+"\t";
            }
            Memo1->Lines->Add("");
        }
    }

    //for�{�^���������񉟂��ƕ������B
    else{
        Memo1->Lines->Text="������";
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
    Memo1->Lines->Text="while��";
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

//SaveButton���������Ƃ����A�E�N���b�N�ŕۑ���I�񂾂Ƃ��B
void __fastcall TForm1::saveExecute(TObject *Sender)
{
    if(SaveDialog1->Execute())
    Memo1->Lines->SaveToFile(SaveDialog1->FileName);
}
//---------------------------------------------------------------------------

//LoadButton���������Ƃ��A�E�N���b�N�œǂݍ��݂�I�񂾂Ƃ��B
void __fastcall TForm1::loadExecute(TObject *Sender)
{
    if(OpenDialog1->Execute())
    Memo1->Lines->LoadFromFile(OpenDialog1->FileName);
}
//---------------------------------------------------------------------------

//ClearButton�A�E�N���b�N"�S����"
void __fastcall TForm1::clearExecute(TObject *Sender)
{
    Memo1->Clear();
}
//---------------------------------------------------------------------------

//�E�N���b�N"�I��"
void __fastcall TForm1::EndClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

//�ۑ肄)��this�͂ǂ̂悤�Ɂi�ǂ��Łj�g���̂��킩��Ȃ������B
