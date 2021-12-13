//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include <vector>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
const UnicodeString znaki[] = {"+", "-", "*", "/"};
std::vector<float> nums;
std::vector<UnicodeString> signs;
void AutomaticDo(TObject* Sender)
{
	if(nums.size() == 2)
	{
		double temp = nums[0];
        nums.erase(nums.begin());
		if(signs[0] == "+")
			temp += nums[0];
		if(signs[0] == "-")
			temp -= nums[0];
		if(signs[0] == "*")
			temp *= nums[0];
		if(signs[0] == "/")
			temp /= nums[0];
		nums.erase(nums.begin());
		signs.erase(signs.begin());
		nums.push_back(temp);
        Form1->Label1->Caption = temp;
    }
}
void AddNum(UnicodeString num, TObject* Sender)
{
	for(int i = 0; i < 4; i++)
		if(znaki[i] == Form1->Edit1->Text)
		{
			Form1->Label1->Caption += Form1->Edit1->Text;
			signs.push_back(Form1->Edit1->Text);
			Form1->Edit1->Text = "0";
		}
	if(Form1->Edit1->Text == "0")
		Form1->Edit1->Text = num;
	else
		Form1->Edit1->Text += num;
}
void AddSign(UnicodeString sign, TObject* Sender)
{
	for(int i = 0; i < 4; i++)
		if(znaki[i] == Form1->Edit1->Text)
		{
            return;
		}
	if(Form1->Edit1->Text != ""){
		Form1->Label1->Caption += Form1->Edit1->Text;
		nums.push_back(StrToFloat(Form1->Edit1->Text));
	}
	Form1->Edit1->Text = sign;
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClearClick(TObject *Sender)
{
	Edit1->Text = "0";
    Label1->Caption = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OneClick(TObject *Sender)
{
	AddNum("1", Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TwoClick(TObject *Sender)
{
	AddNum("2", Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ZeroClick(TObject *Sender)
{
	AddNum("0", Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ThreeClick(TObject *Sender)
{
	AddNum("3", Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FourClick(TObject *Sender)
{
	AddNum("4", Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FiveClick(TObject *Sender)
{
    AddNum("5", Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SixClick(TObject *Sender)
{
    AddNum("6", Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SevenClick(TObject *Sender)
{
    AddNum("7", Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::EightClick(TObject *Sender)
{
    AddNum("8", Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::NineClick(TObject *Sender)
{
    AddNum("9", Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PointClick(TObject *Sender)
{
	for(int i = 1; i < Edit1->Text.Length(); i++)
	{
		if(Edit1->Text[i] == ',') return;
	}
	Edit1->Text += ',';
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RaznClick(TObject *Sender)
{
	AddSign("-", Sender);
	AutomaticDo(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MultClick(TObject *Sender)
{
	AddSign("*", Sender);
	AutomaticDo(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DivClick(TObject *Sender)
{
	AddSign("/", Sender);
	AutomaticDo(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ResultClick(TObject *Sender)
{
	AddSign("0", Sender);
	AutomaticDo(Sender);
	Label1->Caption = "";
	Label2->Caption = "Îòâåò = " + FloatToStr(nums[0]);
	nums.clear();
    signs.clear();
//	double temp = nums[0];
//    nums.erase(nums.begin());
//	while (nums.size() != 0 && signs.size() != 0)
//	{
//		if(signs[0] == "+")
//		   temp += nums[0];
//		if(signs[0] == "-")
//		   temp -= nums[0];
//		if(signs[0] == "*")
//			temp *= nums[0];
//		if(signs[0] == "/")
//            temp /= nums[0];
//		nums.erase(nums.begin());
//        signs.erase(signs.begin());
//	}
//	Label2->Caption = "Îòâåò = " + FloatToStr(temp);
//	Edit1->Text = "0";
//	Label1->Caption = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SumClick(TObject *Sender)
{
	AddSign("+", Sender);
    AutomaticDo(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
	if(Key == VK_RETURN)
	{
		try
		{
			int amount_p = 0;
			for(int i = 1; i < Edit1->Text.Length(); i++)
			{
				if(Edit1->Text[i] == ',') amount_p++;
				for(int j = 0; j < 4; j++)
					if(znaki[j] == Edit1->Text[i] && Edit1->Text.Length() != 1)
						throw new Exception("Íåëüçÿ ïèñàòü ÷èñëà è çíàêè ñðàçó");


			}
			if(amount_p > 1) throw new Exception("ÄÂÅ ÒÎ×ÊÈ?!");
			int amount_neravenst = 0;
			for(int i = 0; i < 4; i++)
			{
				if(znaki[i] == Edit1->Text)
				{
					signs.push_back(Edit1->Text);
					Label1->Caption += Edit1->Text;
					Edit1->Text = "";
                    return;
				}

			}
			if(Label1->Caption.Length() != 0){
			AnsiString tem = Label1->Caption;
			for(int i = 0; i < 4; i++)
				{
					if(!(tem.Pos(znaki[i])))
					{
					   amount_neravenst++;
					}
				}
			}
			if(amount_neravenst == 4) throw new Exception("ÍÅËÜÇß ÄÎÁÀÂËßÒÜ ×ÈÑËÀ Ê ×ÈÑËÀÌ");
			if(Edit1->Text != "") nums.push_back(StrToFloat(Edit1->Text));
			Label1->Caption += Edit1->Text;
			Edit1->Text = "";
		}
		catch(Exception& exc)
		{
			ShowMessage(exc.ToString());
            Edit1->Clear();
            Edit1->SetFocus();
		}
		AutomaticDo(Sender);
	}
}
//---------------------------------------------------------------------------
