//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "homework1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
void func(int z[],int j)
{  //sortä÷êî
   int ttt,fff;
   do {
      fff=0;
      for(int i=0;i<j;i++){
         if (z[i]<z[i+1]){
             ttt=z[i+1];
             z[i+1]=z[i];
             z[i]=ttt;
             fff=1;
         }
      }
    }while (fff);
}

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
   RadioGroup1->ItemIndex=0;
   RadioGroup2->ItemIndex=0;
   RadioGroup3->ItemIndex=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B1Click(TObject *Sender)
{
   //if(B1->Caption=="Ç⁄ÇΩÇÒ(&B)")B1->Caption="button(&B)";
   //else B1->Caption="Ç⁄ÇΩÇÒ(&B)";
   B1->Caption=(B1->Caption=="Ç⁄ÇΩÇÒ(&B)")?"button(&B)":"Ç⁄ÇΩÇÒ(&B)";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
   switch(RadioGroup1->ItemIndex){
      case 0:
         Label1->Caption="+";
      break;
      case 1:
         Label1->Caption="-";
      break;
      case 2:
         Label1->Caption="*";
      break;
      case 3:
         Label1->Caption="/";
      break;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
   float a,b,c;
   try{
      a=StrToFloat(Edit1->Text);
      b=StrToFloat(Edit2->Text);
   }
   catch(...){
      MessageDlg("ãLì¸Ç‡ÇÍÇ©ílÇ™Ç®Ç©ÇµÇ¢",mtError,TMsgDlgButtons() << mbOK, 0);
      Edit1->SetFocus();
      return;
   }

   switch(RadioGroup1->ItemIndex){
      case 0:
         c=a+b;
      break;
      case 1:
         c=a-b;
      break;
      case 2:
         c=a*b;
      break;
      case 3:
         if(b==0) Edit2->Text="";
         else c=a/b;
      break;
   }
   Edit3->Text=FormatFloat("0.000",c);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioGroup2Click(TObject *Sender)
{
   switch(RadioGroup2->ItemIndex){
      case 0:
         Label3->Caption=">";
         Label4->Caption=">";
         Label5->Caption=">";
         Label6->Caption=">";
      break;
      case 1:
         Label3->Caption="<";
         Label4->Caption="<";
         Label5->Caption="<";
         Label6->Caption="<";
      break;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
   int z[5];
   try{
      z[0]=StrToInt(Edit4->Text);
      z[1]=StrToInt(Edit5->Text);
      z[2]=StrToInt(Edit6->Text);
      z[3]=StrToInt(Edit7->Text);
      z[4]=StrToInt(Edit8->Text);
   }
   catch(...){
      MessageDlg("Ç®Ç©ÇµÇ¢Ç≈Ç∑",mtError,TMsgDlgButtons() << mbOK, 0);
      Edit4->SetFocus();
      return;
   }

   func(z,4);

   switch(RadioGroup2->ItemIndex){
      case 0:
         Edit4->Text=z[0];
         Edit5->Text=z[1];
         Edit6->Text=z[2];
         Edit7->Text=z[3];
         Edit8->Text=z[4];
      break;
      case 1:
         Edit4->Text=z[4];
         Edit5->Text=z[3];
         Edit6->Text=z[2];
         Edit7->Text=z[1];
         Edit8->Text=z[0];
      break;
   }
   if (Edit4->Text==Edit5->Text)Label3->Caption="=";
   if (Edit5->Text==Edit6->Text)Label4->Caption="=";
   if (Edit6->Text==Edit7->Text)Label5->Caption="=";
   if (Edit7->Text==Edit8->Text)Label6->Caption="=";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::E1Change(TObject *Sender)
{
   B2->Enabled=(E1->Text=="")?false:true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::B2Click(TObject *Sender)
{
   AnsiString B;
   int i=0,k=1,x=1,y,d[100];
   B=E1->Text + ",";

   for(i;i<100;i++){
      if (x>0){
         y=B.AnsiPos(",");
         d[i]=StrToInt(B.SubString(1,y-1));
         B.Delete(1,y);
         x=B.Length();
         if(x==0)break;
      }
   }

   func(d,i);
   E2->Text=String(d[0]);
   for(k=1;k<=i;k++){
      switch(RadioGroup3->ItemIndex){
         case 0:
            if(d[k-1]==d[k])E2->Text=E2->Text + " = " + String(d[k]);
            else E2->Text=E2->Text + " > " + String(d[k]);
         break;
         case 1:
            if(d[k-1]==d[k])E2->Text=String(d[k])+" = "+E2->Text;
            else E2->Text=String(d[k])+" < "+E2->Text;
         break;
      }
   }
}
//---------------------------------------------------------------------------

