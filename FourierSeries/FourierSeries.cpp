//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "FourierSeries.h"
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
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    CheckBox1->State=cbChecked;
    CheckBox2->State=cbUnchecked;
    CheckBox3->State=cbUnchecked;
    CheckBox4->State=cbUnchecked;
    CheckBox5->State=cbUnchecked;
    CheckBox6->State=cbUnchecked;
	CheckBox7->State=cbUnchecked;
    CheckBox8->State=cbUnchecked;
    CheckBox9->State=cbUnchecked;
    CheckBox10->State=cbUnchecked;
    CheckBox11->State=cbUnchecked;
    CheckBox12->State=cbUnchecked;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Chart1->Series[0]->Clear();
    double a[12],x[12],y[12],phy[12],z=0;
    float Pi=3.14159265358979323846,i;
    try{
        x[0]=StrToFloat(Edit1->Text);
        a[0]=StrToFloat(Edit2->Text);
        phy[0]=StrToFloat(Edit3->Text);
        x[1]=StrToFloat(Edit4->Text);
        a[1]=StrToFloat(Edit5->Text);
        phy[1]=StrToFloat(Edit6->Text);
        x[2]=StrToFloat(Edit7->Text);
        a[2]=StrToFloat(Edit8->Text);
        phy[2]=StrToFloat(Edit9->Text);
        x[3]=StrToFloat(Edit10->Text);
        a[3]=StrToFloat(Edit11->Text);
        phy[3]=StrToFloat(Edit12->Text);
        x[4]=StrToFloat(Edit13->Text);
        a[4]=StrToFloat(Edit14->Text);
        phy[4]=StrToFloat(Edit15->Text);
        x[5]=StrToFloat(Edit16->Text);
        a[5]=StrToFloat(Edit17->Text);
        phy[5]=StrToFloat(Edit18->Text);
        x[6]=StrToFloat(Edit19->Text);
        a[6]=StrToFloat(Edit20->Text);
        phy[6]=StrToFloat(Edit21->Text);
        x[7]=StrToFloat(Edit22->Text);
        a[7]=StrToFloat(Edit23->Text);
        phy[7]=StrToFloat(Edit24->Text);
        x[8]=StrToFloat(Edit25->Text);
        a[8]=StrToFloat(Edit26->Text);
        phy[8]=StrToFloat(Edit27->Text);
        x[9]=StrToFloat(Edit28->Text);
        a[9]=StrToFloat(Edit29->Text);
        phy[9]=StrToFloat(Edit30->Text);
        x[10]=StrToFloat(Edit31->Text);
        a[10]=StrToFloat(Edit32->Text);
        phy[10]=StrToFloat(Edit33->Text);
        x[11]=StrToFloat(Edit34->Text);
        a[11]=StrToFloat(Edit35->Text);
        phy[11]=StrToFloat(Edit36->Text);
    }
    catch(Exception &E){
        Edit1->Text="0";
        Edit2->Text="0";
        Edit3->Text="0";
        Edit4->Text="0";
        Edit5->Text="0";
    }
	float kk=StrToFloat(Edit39->Text);
	float i1=-1/x[0];
	float i2=kk/x[0];
	float t;
	if(i2-i1==0) t=1.0;
	else t=(i2-i1)/300;

	for(i=i1;i<i2;i=i+t){
		for(int u=0;u<=11;u++){
			y[u]=a[u]*sin(i*2*Pi*x[u]+phy[u]);
		}
		if(CheckBox14->State==cbUnchecked){
			if(CheckBox1->State==cbUnchecked) y[0]=0;
			if(CheckBox2->State==cbUnchecked) y[1]=0;
			if(CheckBox3->State==cbUnchecked) y[2]=0;
			if(CheckBox4->State==cbUnchecked) y[3]=0;
			if(CheckBox5->State==cbUnchecked) y[4]=0;
			if(CheckBox6->State==cbUnchecked) y[5]=0;
			if(CheckBox7->State==cbUnchecked) y[6]=0;
			if(CheckBox8->State==cbUnchecked) y[7]=0;
			if(CheckBox9->State==cbUnchecked) y[8]=0;
			if(CheckBox10->State==cbUnchecked) y[9]=0;
			if(CheckBox11->State==cbUnchecked) y[10]=0;
			if(CheckBox12->State==cbUnchecked) y[11]=0;
			z=y[0]+y[1]+y[2]+y[3]+y[4]+y[5]+y[6]+y[7]+y[8]+y[9]+y[10]+y[11];
		}
		else{
			if(CheckBox1->State==cbUnchecked) y[0]=1;
			if(CheckBox2->State==cbUnchecked) y[1]=1;
			if(CheckBox3->State==cbUnchecked) y[2]=1;
			if(CheckBox4->State==cbUnchecked) y[3]=1;
			if(CheckBox5->State==cbUnchecked) y[4]=1;
			if(CheckBox6->State==cbUnchecked) y[5]=1;
			if(CheckBox7->State==cbUnchecked) y[6]=1;
			if(CheckBox8->State==cbUnchecked) y[7]=1;
			if(CheckBox9->State==cbUnchecked) y[8]=1;
			if(CheckBox10->State==cbUnchecked) y[9]=1;
			if(CheckBox11->State==cbUnchecked) y[10]=1;
			if(CheckBox12->State==cbUnchecked) y[11]=1;
			z=y[0]*y[1]*y[2]*y[3]*y[4]*y[5]*y[6]*y[7]*y[8]*y[9]*y[10]*y[11];
		}
		Chart1->Series[0]->AddXY(i,z,"",clBlue);
	}

	Chart1->LeftAxis->Automatic;
	Chart1->BottomAxis->Automatic;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
    Chart1->Series[0]->Clear();
    Chart1->Series[1]->Clear();
    Chart1->Series[2]->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
    if(CheckBox1->State==cbUnchecked){
        Edit1->TabStop=false;
        Edit1->Enabled=false;
        Edit2->TabStop=false;
        Edit2->Enabled=false;
        Edit3->TabStop=false;
        Edit3->Enabled=false;
    }
    if(CheckBox1->State==cbChecked){
        Edit1->TabStop=true;
        Edit1->Enabled=true;
        Edit2->TabStop=true;
        Edit2->Enabled=true;
        Edit3->TabStop=true;
        Edit3->Enabled=true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox2Click(TObject *Sender)
{
    if(CheckBox2->State==cbUnchecked){
        Edit4->TabStop=false;
        Edit4->Enabled=false;
        Edit5->TabStop=false;
        Edit5->Enabled=false;
        Edit6->TabStop=false;
        Edit6->Enabled=false;
    }
    if(CheckBox2->State==cbChecked){
        Edit4->TabStop=true;
        Edit4->Enabled=true;
        Edit5->TabStop=true;
        Edit5->Enabled=true;
        Edit6->TabStop=true;
        Edit6->Enabled=true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox3Click(TObject *Sender)
{
    if(CheckBox3->State==cbUnchecked){
        Edit7->TabStop=false;
        Edit7->Enabled=false;
        Edit8->TabStop=false;
        Edit8->Enabled=false;
        Edit9->TabStop=false;
        Edit9->Enabled=false;
    }
    if(CheckBox3->State==cbChecked){
        Edit7->TabStop=true;
        Edit7->Enabled=true;
        Edit8->TabStop=true;
        Edit8->Enabled=true;
        Edit9->TabStop=true;
        Edit9->Enabled=true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox4Click(TObject *Sender)
{
    if(CheckBox4->State==cbUnchecked){
        Edit10->TabStop=false;
        Edit10->Enabled=false;
        Edit11->TabStop=false;
        Edit11->Enabled=false;
        Edit12->TabStop=false;
        Edit12->Enabled=false;
    }
    if(CheckBox4->State==cbChecked){
        Edit10->TabStop=true;
        Edit10->Enabled=true;
        Edit11->TabStop=true;
        Edit11->Enabled=true;
        Edit12->TabStop=true;
        Edit12->Enabled=true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox5Click(TObject *Sender)
{
    if(CheckBox5->State==cbUnchecked){
        Edit13->TabStop=false;
        Edit13->Enabled=false;
        Edit14->TabStop=false;
        Edit14->Enabled=false;
        Edit15->TabStop=false;
        Edit15->Enabled=false;
    }
    if(CheckBox5->State==cbChecked){
        Edit13->TabStop=true;
        Edit13->Enabled=true;
        Edit14->TabStop=true;
        Edit14->Enabled=true;
        Edit15->TabStop=true;
        Edit15->Enabled=true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox6Click(TObject *Sender)
{
    if(CheckBox6->State==cbUnchecked){
        Edit16->TabStop=false;
        Edit16->Enabled=false;
        Edit17->TabStop=false;
        Edit17->Enabled=false;
        Edit18->TabStop=false;
        Edit18->Enabled=false;
    }
    if(CheckBox6->State==cbChecked){
        Edit16->TabStop=true;
        Edit16->Enabled=true;
        Edit17->TabStop=true;
        Edit17->Enabled=true;
        Edit18->TabStop=true;
        Edit18->Enabled=true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox7Click(TObject *Sender)
{
    if(CheckBox7->State==cbUnchecked){
        Edit19->TabStop=false;
        Edit19->Enabled=false;
        Edit20->TabStop=false;
        Edit20->Enabled=false;
        Edit21->TabStop=false;
        Edit21->Enabled=false;
    }
    if(CheckBox7->State==cbChecked){
        Edit19->TabStop=true;
        Edit19->Enabled=true;
        Edit20->TabStop=true;
        Edit20->Enabled=true;
        Edit21->TabStop=true;
        Edit21->Enabled=true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox8Click(TObject *Sender)
{
    if(CheckBox8->State==cbUnchecked){
        Edit22->TabStop=false;
        Edit22->Enabled=false;
        Edit23->TabStop=false;
        Edit23->Enabled=false;
        Edit24->TabStop=false;
        Edit24->Enabled=false;
    }
    if(CheckBox8->State==cbChecked){
        Edit22->TabStop=true;
        Edit22->Enabled=true;
        Edit23->TabStop=true;
        Edit23->Enabled=true;
        Edit24->TabStop=true;
        Edit24->Enabled=true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox9Click(TObject *Sender)
{
    if(CheckBox9->State==cbUnchecked){
        Edit25->TabStop=false;
        Edit25->Enabled=false;
        Edit26->TabStop=false;
        Edit26->Enabled=false;
        Edit27->TabStop=false;
        Edit27->Enabled=false;
    }
    if(CheckBox9->State==cbChecked){
        Edit25->TabStop=true;
        Edit25->Enabled=true;
        Edit26->TabStop=true;
        Edit26->Enabled=true;
        Edit27->TabStop=true;
        Edit27->Enabled=true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox10Click(TObject *Sender)
{
    if(CheckBox10->State==cbUnchecked){
        Edit28->TabStop=false;
        Edit28->Enabled=false;
        Edit29->TabStop=false;
        Edit29->Enabled=false;
        Edit30->TabStop=false;
        Edit30->Enabled=false;
    }
    if(CheckBox10->State==cbChecked){
        Edit28->TabStop=true;
        Edit28->Enabled=true;
        Edit29->TabStop=true;
        Edit29->Enabled=true;
        Edit30->TabStop=true;
        Edit30->Enabled=true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox11Click(TObject *Sender)
{
    if(CheckBox11->State==cbUnchecked){
        Edit31->TabStop=false;
        Edit31->Enabled=false;
        Edit32->TabStop=false;
        Edit32->Enabled=false;
        Edit33->TabStop=false;
        Edit33->Enabled=false;
    }
    if(CheckBox11->State==cbChecked){
        Edit31->TabStop=true;
        Edit31->Enabled=true;
        Edit32->TabStop=true;
        Edit32->Enabled=true;
        Edit33->TabStop=true;
        Edit33->Enabled=true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox12Click(TObject *Sender)
{
    if(CheckBox12->State==cbUnchecked){
        Edit34->TabStop=false;
        Edit34->Enabled=false;
        Edit35->TabStop=false;
        Edit35->Enabled=false;
        Edit36->TabStop=false;
        Edit36->Enabled=false;
    }
    if(CheckBox12->State==cbChecked){
        Edit34->TabStop=true;
        Edit34->Enabled=true;
        Edit35->TabStop=true;
        Edit35->Enabled=true;
        Edit36->TabStop=true;
        Edit36->Enabled=true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox13Click(TObject *Sender)
{
    float Pi=3.14159265358979323846;
    if(CheckBox13->State==cbUnchecked){
        Edit3->Text="0";
        Edit6->Text="0";
        Edit9->Text="0";
        Edit12->Text="0";
        Edit15->Text="0";
        Edit18->Text="0";
        Edit21->Text="0";
        Edit24->Text="0";
        Edit27->Text="0";
        Edit30->Text="0";
        Edit33->Text="0";
        Edit36->Text="0";
    }
    if(CheckBox13->State==cbChecked){
        Edit3->Text=Pi/2;
        Edit6->Text=Pi/2;
        Edit9->Text=Pi/2;
        Edit12->Text=Pi/2;
        Edit15->Text=Pi/2;
        Edit18->Text=Pi/2;
        Edit21->Text=Pi/2;
        Edit24->Text=Pi/2;
        Edit27->Text=Pi/2;
        Edit30->Text=Pi/2;
        Edit33->Text=Pi/2;
        Edit36->Text=Pi/2;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
    CheckBox1->State=cbChecked;
    CheckBox2->State=cbChecked;
    CheckBox3->State=cbChecked;
    CheckBox4->State=cbChecked;
    CheckBox5->State=cbChecked;
    CheckBox6->State=cbChecked;
    CheckBox7->State=cbChecked;
    CheckBox8->State=cbChecked;
	CheckBox9->State=cbChecked;
    CheckBox10->State=cbChecked;
    CheckBox11->State=cbChecked;
    CheckBox12->State=cbChecked;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
    CheckBox1->State=cbUnchecked;
    CheckBox2->State=cbUnchecked;
    CheckBox3->State=cbUnchecked;
    CheckBox4->State=cbUnchecked;
    CheckBox5->State=cbUnchecked;
    CheckBox6->State=cbUnchecked;
    CheckBox7->State=cbUnchecked;
    CheckBox8->State=cbUnchecked;
    CheckBox9->State=cbUnchecked;
    CheckBox10->State=cbUnchecked;
    CheckBox11->State=cbUnchecked;
    CheckBox12->State=cbUnchecked;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	// sawtooth wave ƒmƒRƒMƒŠ”gŒ`
	float x,y,z,w[100],Pi=3.14159265358979323846;
    Chart1->Series[1]->Clear();
    for(x=-1;x<=4;x=x+0.01){
		z=0;
        for(int n=1;n<=Edit37->Text;n++){
            w[n]=pow(-1,n+1)*2/n;
            z=z+pow(-1,n+1)*2/n*sin(n*2*Pi*x);
        }
        Edit1->Text=1;
        Edit4->Text=2;
        Edit7->Text=3;
        Edit10->Text=4;
        Edit13->Text=5;
        Edit16->Text=6;
        Edit19->Text=7;
        Edit22->Text=8;
        Edit25->Text=9;
        Edit28->Text=10;
        Edit31->Text=11;
        Edit34->Text=12;
        Edit2->Text=w[1];
        Edit5->Text=w[2];
        Edit8->Text=w[3];
        Edit11->Text=w[4];
        Edit14->Text=w[5];
        Edit17->Text=w[6];
        Edit20->Text=w[7];
        Edit23->Text=w[8];
        Edit26->Text=w[9];
        Edit29->Text=w[10];
        Edit32->Text=w[11];
        Edit35->Text=w[12];
        CheckBox13->State=cbUnchecked;
        Chart1->Series[1]->AddXY(x,z,"",clBlue);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
    // Square wave ‹éŒ`”g
	float x,y,z,w[100],Pi=3.14159265358979323846;
    Chart1->Series[1]->Clear();
	for(x=-1;x<=4;x=x+0.01){
        z=0;
        for(int n=1;n<=Edit37->Text;n++){
            w[n]=(-1+pow(-1,n))/n;
            z=z+(-1+pow(-1,n))/n*sin(n*2*Pi*x);
        }
        Edit1->Text=1;
        Edit4->Text=2;
        Edit7->Text=3;
        Edit10->Text=4;
        Edit13->Text=5;
        Edit16->Text=6;
        Edit19->Text=7;
        Edit22->Text=8;
        Edit25->Text=9;
        Edit28->Text=10;
        Edit31->Text=11;
        Edit34->Text=12;
        Edit2->Text=w[1];
        Edit5->Text=w[2];
        Edit8->Text=w[3];
        Edit11->Text=w[4];
        Edit14->Text=w[5];
        Edit17->Text=w[6];
        Edit20->Text=w[7];
        Edit23->Text=w[8];
        Edit26->Text=w[9];
        Edit29->Text=w[10];
        Edit32->Text=w[11];
        Edit35->Text=w[12];
        CheckBox13->State=cbUnchecked;
        Chart1->Series[1]->AddXY(x,z,"",clBlue);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	// triangle wave ŽOŠp”g
	float x,y,z,w[100],Pi=3.14159265358979323846;
	Chart1->Series[1]->Clear();
	for(x=-1;x<=4;x=x+0.01){
        z=0;
        for(int n=1;n<=Edit37->Text;n++){
            w[n]=4/pow(Pi,2)*(1-pow(-1,n))/pow(n,2);
            z=z+4/pow(Pi,2)*(1-pow(-1,n))/pow(n,2)*cos(n*2*Pi*x);
        }
        Edit1->Text=1;
        Edit4->Text=2;
        Edit7->Text=3;
        Edit10->Text=4;
        Edit13->Text=5;
        Edit16->Text=6;
        Edit19->Text=7;
        Edit22->Text=8;
        Edit25->Text=9;
        Edit28->Text=10;
        Edit31->Text=11;
        Edit34->Text=12;
        Edit2->Text=w[1];
        Edit5->Text=w[2];
        Edit8->Text=w[3];
        Edit11->Text=w[4];
        Edit14->Text=w[5];
        Edit17->Text=w[6];
        Edit20->Text=w[7];
        Edit23->Text=w[8];
        Edit26->Text=w[9];
        Edit29->Text=w[10];
        Edit32->Text=w[11];
        Edit35->Text=w[12];
        CheckBox13->State=cbChecked;
        Chart1->Series[1]->AddXY(x,z,"",clBlue);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
    float x,y,z,w[100],Pi=3.14159265358979323846,gg,pp,kk;
    pp=StrToFloat(Edit38->Text);
    kk=StrToFloat(Edit39->Text);
	for(x=-1;x<=kk;x=x+0.01){
        z=0;
        for(int n=1;n<=Edit37->Text;n++){
            w[n]=(-1+pow(-1,n))/n;
            z=z+(-1+pow(-1,n))/n*sin(n*2*Pi*x);
        }
        gg=z*sin(pp*2*Pi*x);
        Chart1->Series[2]->AddXY(x,gg,"",clBlue);
    }
}
//---------------------------------------------------------------------------

