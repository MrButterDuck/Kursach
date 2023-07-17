#pragma once
#include <wx/wx.h>
#include "Logic.h"
#include "Structs.h"

#define RADIOBOX 30

class DebugFrame : public wxFrame
{
public:
	DebugFrame(const wxString& title, Logic * &logic, int type);

private:
	Logic *logic;
	int type;
	wxStaticText* text;
	wxRadioBox* radioBox;
	void PrintStruct(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};