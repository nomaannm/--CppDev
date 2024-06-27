#include "APP.h"
#include "MainFrame.h"
#include<wx/wx.h>


wxIMPLEMENT_APP(APP);

bool APP::OnInit() {
	MainFrame* mainFrame = new MainFrame("C++ App");
	mainFrame->SetClientSize(800, 480);
	mainFrame->Center();
	mainFrame->Show();
	return true;
}
