//---------------------------------------------------------------------------

#ifndef PlotTrigonometricFunction2H
#define PlotTrigonometricFunction2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE 管理のコンポーネント
        TEdit *PointEdit;
        TButton *CancelButton;
        TScrollBar *PScrollBar;
        TLabel *PMinLabel;
        TLabel *PMaxLabel;
        TButton *OKButton1;
        void __fastcall CancelButtonClick(TObject *Sender);
        void __fastcall OKButton1Click(TObject *Sender);
        void __fastcall PScrollBarChange(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
