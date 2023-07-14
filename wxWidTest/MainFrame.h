#pragma once
#include <wx/wx.h>
#include "wxMyGrid.h"
#include <wx/wx.h>
#include "icons/open_icon.xpm"
#include "icons/remove_icon.xpm"
#include "icons/debug_icon.xpm"
#include "icons/save_icon.xpm"
#include "icons/save_as_icon.xpm"
#include "icons/clear_icon.xpm"
#include "icons/delete_icon.xpm"
#include "icons/add_icon.xpm"
#include <wx/scrolwin.h>
#include "InputWindow.h"
#include "DataTypes.h"
#include "Logic.h"
#include "Structs.h"

#define OPEN_BUTTON 2
#define REMOVE_BUTTON 3
#define SAVE_BUTTON 4
#define SAVE_AS_BUTTON 5
#define DEBUG_BUTTON 6
#define RADIOBOX 7
#define ADD_BUTTON 8
#define DELETE_BUTTON 9
#define CLEAR_BUTTON 10

class MainFrame: public wxFrame
{
public:
	MainFrame(const wxString& title);
	void ChooseDictionary();
private:
	Logic* logic;
	wxToolBar* toolBar;
	wxRadioBox* radioBox;
	wxMyGrid* grid;
	wxScrolledWindow* mainPanel;
	int currentDict;
	void OpenData(wxCommandEvent& evt);
	void RemoveData(wxCommandEvent& evt);
	void SaveData(wxCommandEvent& evt);
	void SaveAsData(wxCommandEvent& evt);
	void DebugWin(wxCommandEvent& evt);
	void ChooseDictionary(wxCommandEvent& evt);
	void AddData(wxCommandEvent& evt);
	void DeleteData(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};

