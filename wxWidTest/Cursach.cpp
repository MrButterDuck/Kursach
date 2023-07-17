#include "Cursach.h"
#include "MainFrame.h"
#include "icons/waffle.xpm"
#include <wx/wx.h>

wxIMPLEMENT_APP(Cursach);

bool Cursach::OnInit() {
	struct stat buffer;
	std::string path = "./save/";
	if (stat(path.c_str(), &buffer) != 0) {
		_mkdir(path.c_str());
		std::ofstream file;
		file.open(path + "Clients.txt");
		file.close();
		file.open(path + "Subscribes.txt");
		file.close();
		file.open(path + "Orders.txt");
		file.close();
	}
	MainFrame* mainFrame = new MainFrame("ÂÀÔËß");
	mainFrame->Center();
	mainFrame->Maximize();
	mainFrame->SetIcon(wxIcon(waffle_icon));
	mainFrame->Show();
	mainFrame->ChooseDictionary();
	return true;
}