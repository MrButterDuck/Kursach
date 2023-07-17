#include "DebugWindow.h"

wxBEGIN_EVENT_TABLE(DebugFrame, wxFrame)
EVT_RADIOBOX(RADIOBOX, DebugFrame::PrintStruct)
wxEND_EVENT_TABLE()

DebugFrame::DebugFrame(const wxString& title, Logic* &logic, int type) : wxFrame(nullptr, wxID_ANY, title) {
	this->logic = logic;
	this->type = type;
	wxScrolledWindow *mainPanel = new wxScrolledWindow(this);
	wxSizer* mainPanelSizer = new wxBoxSizer(wxVERTICAL);
	//Grid
	this->text = new wxStaticText(mainPanel, wxID_ANY, "~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n~\n");

	//RadioBox
	wxArrayString choices;
	switch (type) {
		case 0:choices.Add("Дерево Даты Рождения");choices.Add("Дерево Страны");choices.Add("Дерево Города");choices.Add("Хеш Таблица");break;
		case 1:choices.Add("Дерево Названия");choices.Add("Дерево Компании");choices.Add("Дерево Стоимости");choices.Add("Дерево Действия");choices.Add("Хеш Таблица");break;
		case 2:choices.Add("Дерево Логина");choices.Add("Дерево Названия");choices.Add("Дерево Компании");choices.Add("Дерево Даты Начала");choices.Add("Хеш Таблица");break;
	}

	this->radioBox = new wxRadioBox(mainPanel, RADIOBOX, "Справочник", wxDefaultPosition, wxDefaultSize, choices);

	radioBox->SetSelection(2);

	mainPanelSizer->Add(this->radioBox, wxSizerFlags().Expand().Border());
	mainPanelSizer->Add(this->text, wxSizerFlags(1).Expand().Border());
	//mainPanelSizer->Add(new wxButton(mainPanel, UPDATE_BUTTON, "ОБНОВИТЬ ТАБЛИЦУ"), wxSizerFlags().Expand().Border());

	mainPanel->SetSizer(mainPanelSizer);
	mainPanel->FitInside();
	CreateStatusBar();
}

void DebugFrame::PrintStruct(wxCommandEvent& evt) {
	
	switch (type) {
		case 0:this->text->SetLabelText(logic->PrintClientStruct(this->radioBox->GetSelection()));break;
		case 1:this->text->SetLabelText(logic->PrintSubscribeStruct(this->radioBox->GetSelection()));break;
		case 2:this->text->SetLabelText(logic->PrintOrderStruct(this->radioBox->GetSelection()));break;
	}
}