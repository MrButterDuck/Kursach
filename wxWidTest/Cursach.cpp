#include "Cursach.h"
#include "MainFrame.h"
#include "icons/waffle.xpm"
#include <wx/wx.h>

wxIMPLEMENT_APP(Cursach);

bool Cursach::OnInit() {
	MainFrame* mainFrame = new MainFrame("Хачу вафли");
	mainFrame->Center();
	mainFrame->Maximize();
	mainFrame->SetIcon(wxIcon(waffle_icon));
	mainFrame->Show();
	mainFrame->ChooseDictionary();
	return true;
}