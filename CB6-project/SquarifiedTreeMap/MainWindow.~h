//---------------------------------------------------------------------------

#ifndef MainWindowH
#define MainWindowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TSquarifiedTreeMap : public TForm
{
__published:	// IDE-managed Components
        TButton *About;
        void __fastcall AboutClick(TObject *Sender);
        void __fastcall CreateLabel(String name, float top, float left, float width, float height, String caption, TColor color);
        void __fastcall LabelOnMouseEnter(TObject *Sender);
        void __fastcall LabelOnMouseLeave(TObject *Sender);
        void __fastcall LabelOnMouseMove(TObject *Sender, TShiftState state, int x, int y);
private:	// User declarations
public:		// User declarations
        __fastcall TSquarifiedTreeMap(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSquarifiedTreeMap *SquarifiedTreeMap;
//---------------------------------------------------------------------------
#endif
