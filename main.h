//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TButton *Clear;
	TButton *Seven;
	TButton *Eight;
	TButton *Nine;
	TButton *Sum;
	TButton *Four;
	TButton *Five;
	TButton *Six;
	TButton *Razn;
	TButton *One;
	TButton *Two;
	TButton *Three;
	TButton *Mult;
	TButton *Zero;
	TButton *Point;
	TButton *Result;
	TButton *Div;
	TLabel *Label1;
	TLabel *Label2;
	void __fastcall ClearClick(TObject *Sender);
	void __fastcall OneClick(TObject *Sender);
	void __fastcall TwoClick(TObject *Sender);
	void __fastcall ZeroClick(TObject *Sender);
	void __fastcall ThreeClick(TObject *Sender);
	void __fastcall FourClick(TObject *Sender);
	void __fastcall FiveClick(TObject *Sender);
	void __fastcall SixClick(TObject *Sender);
	void __fastcall SevenClick(TObject *Sender);
	void __fastcall EightClick(TObject *Sender);
	void __fastcall NineClick(TObject *Sender);
	void __fastcall PointClick(TObject *Sender);
	void __fastcall RaznClick(TObject *Sender);
	void __fastcall MultClick(TObject *Sender);
	void __fastcall DivClick(TObject *Sender);
	void __fastcall ResultClick(TObject *Sender);
	void __fastcall SumClick(TObject *Sender);
	void __fastcall Edit1KeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
