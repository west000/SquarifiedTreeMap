//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainWindow.h"
#include "SquarifiedAlgorithm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSquarifiedTreeMap *SquarifiedTreeMap;
//---------------------------------------------------------------------------
__fastcall TSquarifiedTreeMap::TSquarifiedTreeMap(TComponent* Owner)
        : TForm(Owner)
{
        this->Visible = true;
        // ��������
        float array[] = {10, 8, 8, 7, 6, 6, 4, 3, 2, 2, 1, 1};
        vector<float> data(array, array+12);
        //float array[] = {82, 25, 36, 50, 89};
        //vector<float> data(array, array+5);
        //float array[] = {821, 251, 100};
        //vector<float> data(array, array+3);
        
        // treemap����ÿ���������ϽǺ����½ǵ�λ��
        vector<ViewRect> treemap;
        getTreeMap(treemap, data, 600, 600);
        TColor colors[] = {clMaroon, clGreen, clOlive, clNavy, clPurple, clTeal, clGray};
        for(int i = 0; i<treemap.size(); ++i)
        {
                // ������εĳ��������
                int width = (treemap[i].width - treemap[i].xoffset);
                int height = (treemap[i].height - treemap[i].yoffset);
                int area =  width * height;
                String caption = "\nsize : " + IntToStr((int)data[i]) + "\n";
                String name("Area");
                name += IntToStr(i).c_str();
                CreateLabel(name, treemap[i].yoffset, treemap[i].xoffset, width, height, caption, clYellow);
        }
}

// ����һ��Label����Ϊһ��������Ϣ����ʾ����
void __fastcall TSquarifiedTreeMap::CreateLabel(String name, float top, float left, float width, float height, String caption, TColor color)
{
        TLabel *bg = new TLabel(this);
        bg->Parent = this;
        bg->AutoSize = false;
        bg->Color = clHotLight;
        bg->Cursor = crHandPoint;
        bg->Enabled = false;
        bg->Top = top - 1;
        bg->Left = left - 1;
        bg->Height = height + 2;
        bg->Width = width + 2;
        bg->Show();


        TLabel *label = new TLabel(this);
        if(name != "")
                label->Name = name.c_str();
        label->Parent = this;
        label->AutoSize = false;
        label->Alignment = taCenter;
        label->Color = color;
        label->Cursor = crHandPoint;
        label->Enabled = true;
        label->Layout = tlCenter;
        label->Top = top + 1;
        label->Left = left + 1;
        label->Width = width - 1;
        label->Height = height - 1;
        label->Caption = caption.c_str();
        label->Font->Charset = GB2312_CHARSET;
        label->Font->Size = 10;
        label->Show();

        label->OnMouseEnter = LabelOnMouseEnter;
        label->OnMouseLeave = LabelOnMouseLeave;
        label->OnMouseMove = LabelOnMouseMove;

        //label->OnMouseLeave = LabelOnMouseLeave;
        //label->OnMouseMove = LabelOnMouseMove;
}

void __fastcall TSquarifiedTreeMap::LabelOnMouseEnter(TObject *Sender)
{
        TLabel *p = (TLabel*)Sender;
        p->Color = clSkyBlue;
        String name = p->ClassName();
        //this->InfoPanel->Caption = name + " : " + p->Name;
        //this->InfoPanel->Caption = p->Caption;
}

// ����Label���뿪����Ӧ�¼�
void __fastcall TSquarifiedTreeMap::LabelOnMouseLeave(TObject *Sender)
{
        TLabel *p = (TLabel*)Sender;
        p->Color = clYellow;
        //this->InfoPanel->Visible = false;
        //this->InfoPanel->Caption = "";
}

// �����Label���ƶ�����Ӧ�¼�
void __fastcall TSquarifiedTreeMap::LabelOnMouseMove(TObject *Sender, TShiftState state, int x, int y)
{
        TLabel *p = (TLabel*)Sender;
        POINT pt;
        pt.x = x, pt.y = y;
        pt = p->ClientToParent(pt, p->Parent);
        //this->InfoPanel->Top = pt.y;
        //this->InfoPanel->Left = pt.x;
        //this->InfoPanel->Visible = true;
}

// ���ڰ�ť����¼�
void __fastcall TSquarifiedTreeMap::AboutClick(TObject *Sender)
{
        // ��������
        String str = "���ߣ���ΰ�b\r\n���ڣ�2016-11-26\r\n�ڹ㶫��ҵ��ѧ";
        MessageBox(0, str.c_str(), "����", MB_OK );
}
//---------------------------------------------------------------------------


