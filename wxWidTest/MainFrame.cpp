#include "MainFrame.h"


wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_TOOL(OPEN_BUTTON, MainFrame::OpenData)
	EVT_TOOL(REMOVE_BUTTON, MainFrame::RemoveData)
	EVT_TOOL(SAVE_BUTTON, MainFrame::SaveData)
	EVT_TOOL(SAVE_AS_BUTTON, MainFrame::SaveAsData)
	EVT_TOOL(DEBUG_BUTTON, MainFrame::DebugWin)
	EVT_TOOL(ADD_BUTTON, MainFrame::AddData)
	EVT_TOOL(DELETE_BUTTON, MainFrame::DeleteData)
	EVT_RADIOBOX(RADIOBOX, MainFrame::ChooseDictionary)
wxEND_EVENT_TABLE()


MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	this->logic = new Logic;
	this->currentDict = 2;
	//Main Panel
	//wxPanel* panel = new wxPanel(this);
	//panel->SetBackgroundColour(wxColor(100, 100, 100));
	//Tool Bar
	this->toolBar = CreateToolBar(wxTB_TEXT);
	this->toolBar->AddTool(OPEN_BUTTON, "открыть из файла", wxBitmap(open_icon), "Открыть сохранение");
	this->toolBar->AddTool(REMOVE_BUTTON, "удалить файл", wxBitmap(remove_icon), "Удалить текущее сохранение");
	this->toolBar->AddSeparator();
	this->toolBar->AddTool(SAVE_BUTTON, "сохранить", wxBitmap(save_icon), "Сохранить");
	this->toolBar->AddTool(SAVE_AS_BUTTON, "сохранить как", wxBitmap(save_as_icon), "Сохранить как");
	this->toolBar->AddSeparator();
	this->toolBar->AddTool(DEBUG_BUTTON, "окно отладки", wxBitmap(debug_icon), "Окно Отладки");
	this->toolBar->AddSeparator();
	this->toolBar->AddTool(ADD_BUTTON, "добавить в справочник", wxBitmap(add_icon), "Добавляет информацию в текущий справочник");
	this->toolBar->AddTool(DELETE_BUTTON, "удалить из справочника", wxBitmap(delete_icon), "Удаляет информацию из текущего справочника");
	this->toolBar->AddTool(CLEAR_BUTTON, "очистить справочник", wxBitmap(clear_icon), "Очищает полностью текущий справочник");
	this->toolBar->Realize();
	//MainPanel
	this->mainPanel = new wxScrolledWindow(this);
	wxSizer* mainPanelSizer = new wxBoxSizer(wxVERTICAL);
	//Grid
	this->grid = new wxMyGrid(mainPanel);
	this->grid->CreateGrid(0, 4);
	this->grid->EnableEditing(false);
	this->grid->Refresh();
	//RadioBox
	wxArrayString choices;
	choices.Add("Клиенты");
	choices.Add("Услуги");
	choices.Add("Заказы");
	this->radioBox = new wxRadioBox(mainPanel, RADIOBOX, "Справочник", wxDefaultPosition, wxDefaultSize, choices);
	this->radioBox->SetSelection(2);

	mainPanelSizer->Add(radioBox, wxSizerFlags().Expand().Border());
	mainPanelSizer->Add(grid, wxSizerFlags(1).Expand().Border());

	this->mainPanel->SetSizer(mainPanelSizer);
	this->mainPanel->FitInside();
	this->mainPanel->SetScrollRate(16, 16);

	CreateStatusBar();
}

void MainFrame::OpenData(wxCommandEvent& evt) {
	wxLogStatus("Opened");
}

void MainFrame::RemoveData(wxCommandEvent& evt) {
	wxLogStatus("Removed");
}

void MainFrame::SaveData(wxCommandEvent& evt) {
	wxLogStatus("Saved");
}

void MainFrame::SaveAsData(wxCommandEvent& evt) {
	wxLogStatus("Saved As");
}

void MainFrame::DebugWin(wxCommandEvent& evt) {
	wxLogStatus("Opened Degub Win");
}

void MainFrame::ChooseDictionary() {
	this->grid->setColumnSize(mainPanel->GetClientSize().GetWidth());
	if (currentDict == 0)
	{
		this->grid->update(logic->getClientList());
	}
	else if (currentDict == 1)
	{
		this->grid->update(logic->getSubscribesList());
	}
	else
	{
		this->grid->update(logic->getOrderList());
	}
}

void MainFrame::ChooseDictionary(wxCommandEvent& evt) {
	this->currentDict = radioBox->GetSelection();
	wxLogStatus(wxString::Format(wxT("%i"), logic->getSubscribesList()->getCount()));
	this->grid->setColumnSize(mainPanel->GetClientSize().GetWidth());
	if (this->currentDict == 0)
	{
		this->grid->update(logic->getClientList());
	}
	else if (this->currentDict == 1)
	{
		this->grid->update(logic->getSubscribesList());
	}
	else
	{
		this->grid->update(logic->getOrderList());
	}
	//wxLogStatus(wxString::Format(wxT("%i"), i));
}

void MainFrame::AddData(wxCommandEvent& evt) {
	int type = radioBox->GetSelection();
	InputFrame* inputFrame = new InputFrame("Input", type, this->logic, this->grid);
	inputFrame->SetParent(this);
	if (type == 1) {
		inputFrame->SetMinSize(wxSize(400, 230));
		inputFrame->SetMaxSize(wxSize(400, 230));
	}
	else {
		inputFrame->SetMinSize(wxSize(400, 330));
		inputFrame->SetMaxSize(wxSize(400, 330));
	}
	inputFrame->Show();
}

void MainFrame::DeleteData(wxCommandEvent& evt) {
	int type = radioBox->GetSelection()+3;
	InputFrame* inputFrame = new InputFrame("Input", type, this->logic, this->grid);
	inputFrame->SetParent(this);
	if (type == 4) {
		inputFrame->SetMinSize(wxSize(400, 230));
		inputFrame->SetMaxSize(wxSize(400, 230));
	}
	else {
		inputFrame->SetMinSize(wxSize(400, 330));
		inputFrame->SetMaxSize(wxSize(400, 330));
	}
	inputFrame->Show();
}