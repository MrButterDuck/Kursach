#include "startWindows.h"


startFrame::startFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	this->SetMinSize(wxSize(250, 250));
	this->SetMaxSize(wxSize(250, 250));
	wxPanel* panel = new wxPanel(this);
	//wxImage m_image = wxImage("./icons/waflee.png", wxBITMAP_TYPE_PNG);
	wxButton* btn;
	new wxStaticText(panel, wxID_ANY, "размер ХТ для справочника\nклиентов", wxPoint(20, 20));
	spn1 = new wxSpinCtrl(panel, wxID_ANY,"размер ХТ для\nсправочника клиентов", wxPoint(180, 20), wxDefaultSize, wxSP_ARROW_KEYS, 10, 100);
	spn1->SetValue(10);
	new wxStaticText(panel, wxID_ANY, "хочешь вафли?", wxPoint(90, 120));
	wxArrayString chs;
	chs.Add("ДА!");
	chs.Add("ОЧЕНЬ ДА!");
	wxChoice* lol = new wxChoice(panel, 333, wxPoint(180, 120), wxDefaultSize, chs);
	//spn2 = new wxSpinCtrl(panel, wxID_ANY, "хочешь вайли?", wxPoint(180, 120), wxDefaultSize, wxSP_ARROW_KEYS, 2, 15);
	lol->SetSelection(0);
	btn = new wxButton(panel, 333, "Поехали", wxPoint(80, 170), wxSize(90, 20));
	btn->Bind(wxEVT_BUTTON, &startFrame::OK, this);
}

void startFrame::OK(wxCommandEvent& evt) {
	MainFrame* mainFrame = new MainFrame("ВАФЛЯ", this->spn1->GetValue(), 1 );
	mainFrame->Center();
	mainFrame->Maximize();
	mainFrame->SetIcon(wxIcon(waffle_icon));
	mainFrame->Show();
	mainFrame->ChooseDictionary();
	this->Close();
}