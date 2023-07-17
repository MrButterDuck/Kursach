#include "MainFrame.h"


wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_TOOL(OPEN_BUTTON, MainFrame::OpenData)
	EVT_TOOL(REMOVE_BUTTON, MainFrame::RemoveData)
	EVT_TOOL(SAVE_BUTTON, MainFrame::SaveData)
	EVT_TOOL(CLEAR_BUTTON, MainFrame::ClearData)
	EVT_TOOL(DEBUG_BUTTON, MainFrame::DebugWin)
	EVT_TOOL(ADD_BUTTON, MainFrame::AddData)
	EVT_TOOL(DELETE_BUTTON, MainFrame::DeleteData)
	EVT_TOOL(SEARCH_BUTTON, MainFrame::SearchData)
	EVT_TOOL(CLEAR_SEACH_BUTTON, MainFrame::ChooseDictionary)
	EVT_RADIOBOX(RADIOBOX, MainFrame::ChooseDictionary)
	EVT_BUTTON(UPDATE_BUTTON, MainFrame::ChooseDictionary)
wxEND_EVENT_TABLE()


MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	this->logic = new Logic;
	this->currentDict = 2;
	//Main Panel
	//wxPanel* panel = new wxPanel(this);
	//panel->SetBackgroundColour(wxColor(100, 100, 100));
	//Tool Bar
	this->toolBar = CreateToolBar(wxTB_TEXT);
	this->toolBar->AddTool(OPEN_BUTTON, "������� �� �����", wxBitmap(open_icon), "������� ����������");
	//this->toolBar->AddTool(REMOVE_BUTTON, "������� ����", wxBitmap(remove_icon), "������� ������� ����������");
	this->toolBar->AddSeparator();
	this->toolBar->AddTool(SAVE_BUTTON, "���������", wxBitmap(save_icon), "���������");
	//this->toolBar->AddTool(SAVE_AS_BUTTON, "��������� ���", wxBitmap(save_as_icon), "��������� ���");
	this->toolBar->AddSeparator();
	this->toolBar->AddTool(DEBUG_BUTTON, "���� �������", wxBitmap(debug_icon), "���� �������");
	this->toolBar->AddSeparator();
	this->toolBar->AddTool(ADD_BUTTON, "�������� � ����������", wxBitmap(add_icon), "��������� ���������� � ������� ����������");
	this->toolBar->AddTool(DELETE_BUTTON, "������� �� �����������", wxBitmap(delete_icon), "������� ���������� �� �������� �����������");
	this->toolBar->AddTool(CLEAR_BUTTON, "�������� ����������", wxBitmap(clear_icon), "������� ��������� ������� ����������");
	this->toolBar->AddSeparator();
	this->toolBar->AddTool(SEARCH_BUTTON, "���� ������", wxBitmap(find_icon), "���� � ������� �����������");
	this->toolBar->AddTool(CLEAR_SEACH_BUTTON, "�������� �����", wxBitmap(clear_search_icon), "������� �����");
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
	choices.Add("�������");
	choices.Add("������");
	choices.Add("������");
	this->radioBox = new wxRadioBox(mainPanel, RADIOBOX, "����������", wxDefaultPosition, wxDefaultSize, choices);
	this->radioBox->SetSelection(2);

	mainPanelSizer->Add(radioBox, wxSizerFlags().Expand().Border());
	mainPanelSizer->Add(grid, wxSizerFlags(1).Expand().Border());
	//mainPanelSizer->Add(new wxButton(mainPanel, UPDATE_BUTTON, "�������� �������"), wxSizerFlags().Expand().Border());

	this->mainPanel->SetSizer(mainPanelSizer);
	this->mainPanel->FitInside();
	this->mainPanel->SetScrollRate(16, 16);

	CreateStatusBar();
}

void MainFrame::OpenData(wxCommandEvent& evt) {
	logic->readFromFile("./save/");
	this->ChooseDictionary();
}

void MainFrame::RemoveData(wxCommandEvent& evt) {
	wxLogStatus("Removed");
}

void MainFrame::SaveData(wxCommandEvent& evt) {
	logic->writeToFile("./save/");
}

void MainFrame::ClearData(wxCommandEvent& evt) {
	this->logic->Clear(this->currentDict);
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
}

void MainFrame::DebugWin(wxCommandEvent& evt) {
	wxLogStatus("Opened Degub Win");
	DebugFrame* debugFrame = new DebugFrame("Debug", this->logic, this->currentDict);
	debugFrame->SetMinSize(wxSize(1000, 1000));
	debugFrame->SetMaxSize(wxSize(1000, 1000));
	debugFrame->Show();
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
	//wxArrayInt arrInt = this->grid->GetSelectedRows();
	//if (!arrInt.IsEmpty())wxLogStatus(wxString::Format(wxT("%i"), arrInt[0]));
	//else wxLogStatus(wxString::Format(wxT("%i"), 0));
	InputFrame* inputFrame = new InputFrame("Input", this->currentDict, this->logic, this->grid);
	inputFrame->SetParent(this);
	if (this->currentDict == 1) {
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
	/*InputFrame* inputFrame = new InputFrame("Input", type, this->logic, this->grid);
	inputFrame->SetParent(this);
	if (type == 4) {
		inputFrame->SetMinSize(wxSize(400, 230));
		inputFrame->SetMaxSize(wxSize(400, 230));
	}
	else {
		inputFrame->SetMinSize(wxSize(400, 330));
		inputFrame->SetMaxSize(wxSize(400, 330));
	}
	inputFrame->Show();*/
	wxArrayInt arrInt = this->grid->GetSelectedRows();
	if (arrInt.IsEmpty()) (new wxMessageDialog(nullptr, "�� ���� �� ����� ������� �� �������", "���� ������ � �� ������", wxOK))->ShowModal();
	else {
		if (this->currentDict == 0) {
			this->logic->DeleteClientData(arrInt[0]);
			this->ChooseDictionary();
		}
		else if (this->currentDict == 1) {
			this->logic->DeleteSubscribeData(arrInt[0]);
			this->ChooseDictionary();
		}
		else if (this->currentDict == 2) {
			this->logic->DeleteOrderData(arrInt[0]);
			this->ChooseDictionary();
		}
	}
}

void MainFrame::SearchData(wxCommandEvent& evt) {
	//wxArrayInt arrInt = this->grid->GetSelectedRows();
	//if (!arrInt.IsEmpty())wxLogStatus(wxString::Format(wxT("%i"), arrInt[0]));
	//else wxLogStatus(wxString::Format(wxT("%i"), 0));
	InputFrame* inputFrame = new InputFrame("Search", this->currentDict+3, this->logic, this->grid);
	inputFrame->SetParent(this);
	if (this->currentDict == 1) {
		inputFrame->SetMinSize(wxSize(400, 230));
		inputFrame->SetMaxSize(wxSize(400, 230));
	}
	else {
		inputFrame->SetMinSize(wxSize(400, 330));
		inputFrame->SetMaxSize(wxSize(400, 330));
	}
	inputFrame->Show();
}
