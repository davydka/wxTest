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
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
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
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    //SetMenuBar( menuBar );
	//menuBar->Enable(false);
    //CreateStatusBar();
    //SetStatusText( "hello hello hello" );
    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);


	wxGraphicsPath path = wxGraphicsRenderer::GetDefaultRenderer()->CreatePath();
	//path.AddEllipse(0, 0,GetRect().width-20,GetRect().height/2);
	path.AddRectangle(0,0,640,448);
	//path.AddRectangle(0,0,640,480);
	SetShape(path);
	/*
	wxPanel * panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(300, 300));
	panel->SetBackgroundColour(wxColour(* wxRED));
	*/
}
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}
