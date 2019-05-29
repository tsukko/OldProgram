//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PlotTrigonometricFunction.h"
#include "PlotTrigonometricFunction2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::PScrollBarChange(TObject *Sender)
{
    PointEdit->Text=PScrollBar->Position;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::OKButton1Click(TObject *Sender)
{
    Form1->PEdit->Text=PointEdit->Text;
    Form2->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::CancelButtonClick(TObject *Sender)
{
    Form2->Close();
}
//---------------------------------------------------------------------------
