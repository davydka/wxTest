// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include "wx/graphics.h"
class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};
class MyFrame: public wxFrame
{
public:
    MyFrame();
private:
};
enum
{
    ID_Hello = 1
};
wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame();
    frame->Show( true );
	printf("cool\n");
    return true;
}
MyFrame::MyFrame()
        //: wxFrame(NULL, wxID_ANY, "hello application", wxDefaultPosition, wxSize(640, 480), 0 | wxNO_BORDER)
        : wxFrame(NULL, wxID_ANY, "hello application", wxDefaultPosition, wxSize(640, 480), 0 | wxFRAME_SHAPED)
{
	
    CreateStatusBar();
    SetStatusText( "hello hello hello" );


	wxGraphicsPath path = wxGraphicsRenderer::GetDefaultRenderer()->CreatePath();
	//path.AddEllipse(0, 0,GetRect().width-20,GetRect().height/2);
	//path.AddRectangle(0,0,640,448);
	path.AddRectangle(0,0,640,480);
	SetShape(path);
	/*
	wxPanel * panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(300, 300));
	panel->SetBackgroundColour(wxColour(* wxRED));
	*/
}
