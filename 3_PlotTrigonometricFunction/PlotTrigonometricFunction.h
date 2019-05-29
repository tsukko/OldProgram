//---------------------------------------------------------------------------

#ifndef PlotTrigonometricFunctionH
#define PlotTrigonometricFunctionH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Series.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <VclTee.TeeGDIPlus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE 管理のコンポーネント
        TBitBtn *BitBtn1;
        TRadioGroup *FunctionRadioGroup;
        TButton *SaveButton;
        TButton *OpenButton;
        TButton *GraphButton;
        TEdit *PEdit;
        TLabel *PLabel;
        TEdit *XMinEdit;
        TLabel *XLabel2;
        TEdit *XMaxEdit;
        TChart *GraphChart;
        TPointSeries *Series1;
        TPopupMenu *GPop;
        TMenuItem *GPopSaveI;
        TMenuItem *GPopOpen;
        TMenuItem *N1;
        TMenuItem *Exit;
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
        TMenuItem *GPopSaveD;
        TLabel *XLabel;
        TLabel *YLabel;
        TEdit *YMinEdit;
        TEdit *YMaxEdit;
        TLabel *YLabel2;
        TRadioGroup *RadioGroup1;
        TEdit *aEdit;
        TEdit *bEdit;
        TLabel *aLabel;
        TLabel *bLabel;
        TButton *ChangeButton;
        TPointSeries *Series2;
        TCheckBox *SizeCheckBox;
        TEdit *xIncrementEdit;
        TEdit *yIncrementEdit;
        TEdit *dyIncrementEdit;
        TButton *Button1;
        TButton *ClearButton;
        void __fastcall GraphButtonClick(TObject *Sender);
        void __fastcall FunctionRadioGroupClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall GPopSaveIClick(TObject *Sender);
        void __fastcall ExitClick(TObject *Sender);
        void __fastcall PEditChange(TObject *Sender);
        void __fastcall GraphChartMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall XMinEditChange(TObject *Sender);
        void __fastcall XMaxEditChange(TObject *Sender);
        void __fastcall YMinEditChange(TObject *Sender);
        void __fastcall YMaxEditChange(TObject *Sender);
        void __fastcall SaveButtonClick(TObject *Sender);
        void __fastcall GPopSaveDClick(TObject *Sender);
        void __fastcall GPopOpenClick(TObject *Sender);
        void __fastcall OpenButtonClick(TObject *Sender);
        void __fastcall ChangeButtonClick(TObject *Sender);
        void __fastcall RadioGroup1Click(TObject *Sender);
        void __fastcall SizeCheckBoxClick(TObject *Sender);
        void __fastcall ClearButtonClick(TObject *Sender);
        void __fastcall YLabelClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
