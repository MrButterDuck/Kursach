#pragma once
#include <wx/wx.h>
#include <wx/calctrl.h>
#include <typeinfo>
#include "DataTypes.h"
#include "Logic.h"
#include "wxMyGrid.h"

class InputFrame : public wxFrame
{
public:
	InputFrame(const wxString& title, char type, Logic* &logic, wxMyGrid* &grid);

private:
	Logic* logic;
	char type;
	wxMyGrid* grid;
	wxTextCtrl* inputFields[4];
	wxCalendarCtrl* calendar;
	void checkData(wxCommandEvent& evt);
};