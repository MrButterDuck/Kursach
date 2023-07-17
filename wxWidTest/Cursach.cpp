#include "Cursach.h"
#include "MainFrame.h"
#include "startWindows.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(Cursach);

bool Cursach::OnInit() {
	(new startFrame("хочу вафли"))->Show();
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

	return true;
}