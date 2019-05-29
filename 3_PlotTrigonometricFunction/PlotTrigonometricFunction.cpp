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

//�O���t�ɏ����o����鎮�̌v�Z���s���֐��B
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

//Chart�̃O���t��MemoryStream�������֐��B
void ClearF()
{
    Form1->GraphChart->Series[0]->Clear();
    Form1->GraphChart->Series[1]->Clear();
    MeSt1->Clear();
}

//�O���t��y���̍ő�ŏ����Ay�̍ő�ŏ��ɂ��킹��֐��B
//y�͈̔͂�Text��ς���B�ƁAChart�̎�������ɕς��B
void  AutoSizeF()
{
    if(Form1->SizeCheckBox->Checked==true){
        Form1->GraphChart->BottomAxis->Automatic=true;
        Form1->GraphChart->LeftAxis->Automatic=true;
        Form1->GraphChart->RightAxis->Automatic=true;
        switch(Form1->RadioGroup1->ItemIndex){
            //�O�̃O���t��y�̍ŏ��l��荡�̃O���t�̂��̍ő�l���������ƃG���[���ł�B�o�Ă��܂��H
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

//�����ݒ�B
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    FunctionRadioGroup->ItemIndex=0;
    RadioGroup1->ItemIndex=0;
    PEdit->Text="200";
}
//---------------------------------------------------------------------------
//���ꂼ��̏����͈́B�O���t�ɕ`���֐��ς���B
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
    GraphChart->BottomAxis->Minimum=StrToFloat(XMinEdit->Text);     //x�̍ŏ�(�O���t�́j
    GraphChart->BottomAxis->Maximum=StrToFloat(XMaxEdit->Text);     //x�̍ő�
    GraphChart->LeftAxis->Minimum=StrToFloat(YMinEdit->Text);       //y�̍ŏ�
    GraphChart->LeftAxis->Maximum=StrToFloat(YMaxEdit->Text);       //y�̍ő�
    GraphChart->RightAxis->Minimum=StrToFloat(YMinEdit->Text);      //dy�̍ŏ�
    GraphChart->RightAxis->Maximum=StrToFloat(YMaxEdit->Text);      //dy�̍ő�
    xIncrementEdit->Text=String(GraphChart->BottomAxis->Increment);
    yIncrementEdit->Text=String(GraphChart->LeftAxis->Increment);
    dyIncrementEdit->Text=String(GraphChart->RightAxis->Increment);
}
//---------------------------------------------------------------------------

//Chart�ɃO���t��`���B
void __fastcall TForm1::GraphButtonClick(TObject *Sender)
{
    ClearF();
    float x=0,xmax,ymin,ymax,z,a,b,dy;

	try{
        x=StrToFloat(XMinEdit->Text);           //x�̍ŏ�
        xmax=StrToFloat(XMaxEdit->Text);        //x�̍ő�
        z=(xmax-x)/(StrToInt(PEdit->Text)-1);   //for����x���̑���
        if(FunctionRadioGroup->ItemIndex==3){   //ax*sin(bx)�̎��̎�a,b�̒l����̂ŁB
            a=StrToFloat(aEdit->Text);
            b=StrToFloat(bEdit->Text);
       }
    }
	catch(Exception &E){
       ShowMessage("�l����������");
       Abort();
    }

    if(x>=xmax){      //�͈͂��������Ȃ������ׂ�B�K�v�Ȃ��̂����H
       ShowMessage("�͈͂���������");
       return;
    }

    for(x;x<=xmax;x=x+z){             //�ŏ����ő�A�����A���̓_
        GraphChart->Series[0]->AddXY(x,y(x,a,b),"",clBlue);
        dy=(y(x+z/2,a,b)-y(x-z/2,a,b))/z;
        GraphChart->Series[1]->AddXY(x,dy,"",clGreen);

        //�������[�X�g���[���Ƀf�[�^���������ށB
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

//�_�̐��󔒂��ƃ{�^�������Ȃ��B
void __fastcall TForm1::PEditChange(TObject *Sender)
{
    if(PEdit->Text.Length()<1)
        GraphButton->Enabled=false;
    else GraphButton->Enabled=true;
}
//---------------------------------------------------------------------------

//�N���b�N���Ȃ���Hint�ō��W�łȂ��H
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

//Edit��x��,y���̍ő�l�ŏ��l��ς����Ƃ��B���̎l�B
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


//�E�N���b�N��'�摜�ŕۑ�'�����������B
void __fastcall TForm1::GPopSaveIClick(TObject *Sender)
{
    SaveDialog1->FilterIndex=1;
    SaveDialog1->DefaultExt="*.wmf";
    if(SaveDialog1->Execute())
        GraphChart->SaveToMetafileEnh(SaveDialog1->FileName);
}
//---------------------------------------------------------------------------

//Save�{�^����������x,y�̍��W(�������X�g���[���ɏ����ꂽ��)���Z�[�u����B
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
//Chart��ŉE�N���b�N����'�f�[�^�̕ۑ�'���������Ƃ��B
void __fastcall TForm1::GPopSaveDClick(TObject *Sender)
{
    SaveButton->Click();
}
//---------------------------------------------------------------------------

//�f�[�^�Ax,y���W�̃��[�h
void __fastcall TForm1::OpenButtonClick(TObject *Sender)
{
    float x,y;
    int i=0;    //�_�̐��𐔂��܂��B
    int p=RadioGroup1->ItemIndex;
    if(p==2)p=0;                 //Series��0��1�����Ȃ��̂ŁE�E�E

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
       }while(!in.eof());              //()�̒���false�ɂȂ�܂ŁH

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
//Chart��ŉE�N���b�N����'�f�[�^���J��'�����������B
void __fastcall TForm1::GPopOpenClick(TObject *Sender)
{
    OpenButton->Click();
}
//---------------------------------------------------------------------------

//����ӂ̓_�̐���ς��邽�߂̐V����Form��ǂݍ��ށB
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
             YLabel->Caption="y�͈̔�";
             GraphChart->Series[0]->Active=true;
             GraphChart->Series[1]->Active=false;
        break;
        case 1:
             YLabel->Caption="dy�͈̔�";
             GraphChart->Series[0]->Active=false;
             GraphChart->Series[1]->Active=true;
        break;
        case 2:
             YLabel->Caption="y�͈̔�";
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

