#pragma once
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "icons/waffle.xpm"
#include "MainFrame.h"

class startFrame : public wxFrame
{
public:
	startFrame(const wxString& title);
	void ChooseDictionary();
private:
	int* size;
	int* k;
	wxSpinCtrl *spn1, *spn2;
	void OK(wxCommandEvent& evt);

	//wxDECLARE_EVENT_TABLE();
};

