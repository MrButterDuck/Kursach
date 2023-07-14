#include "InputWindow.h"


InputFrame::InputFrame(const wxString& title, char type, Logic* &logic, wxMyGrid* &grid) : wxFrame(nullptr, wxID_ANY, title) {
	this->type = type;
	this->logic = logic;
	this->grid = grid;
	wxPanel* panel = new wxPanel(this);
	wxButton* btn;
	if (type == 0 || type == 3) {
		std::string lables[4]{"Логин", "Город Проживания","Страна проживания", "Дата рождения"}; 
		for (int i = 0; i < 4; i++)
		{
			new wxStaticText(panel, wxID_ANY, lables[i], wxPoint(10, 20 + 30 * i));
			if (i != 3)inputFields[i] = new wxTextCtrl(panel, 100 + i, wxEmptyString, wxPoint(150, 20 + 30 * i), wxSize(230, 20));
			else calendar = new wxCalendarCtrl(panel, 100 + i, wxDefaultDateTime, wxPoint(150, 20 + 30 * i));
		}
		if (type == 0)btn = new wxButton(panel, 120, "Добавить", wxPoint(160, 260), wxSize(80, 20));
		else btn = new wxButton(panel, 120, "Удалить", wxPoint(160, 260), wxSize(80, 20));
		btn->Bind(wxEVT_BUTTON, &InputFrame::checkData, this);
	}
	else if (type == 2 || type == 5) {
		std::string lables[4]{ "Логин", "Название услуги", "Дистрибьютор", "Дата начала действия" }; 
		for (int i = 0; i < 4; i++)
		{
			new wxStaticText(panel, wxID_ANY, lables[i], wxPoint(10, 20 + 30 * i));
			if(i != 3)inputFields[i] = new wxTextCtrl(panel, 100 + i, wxEmptyString, wxPoint(150, 20 + 30 * i), wxSize(230, 20));
			else calendar = new wxCalendarCtrl(panel, 100 + i, wxDefaultDateTime, wxPoint(150, 20 + 30 * i));
		}
		if (type == 2)btn = new wxButton(panel, 120, "Добавить", wxPoint(160, 260), wxSize(80, 20));
		else btn = new wxButton(panel, 120, "Удалить", wxPoint(160, 260), wxSize(80, 20));
		btn->Bind(wxEVT_BUTTON, &InputFrame::checkData, this);
	}
	else if (type == 4 || type == 1) {
		std::string lables[4]{ "Название услуги", "Дистрибьютор","Стоимость в месяц", "Минимальный срок\nдействия" }; 
		for (int i = 0; i < 4; i++)
		{
			new wxStaticText(panel, wxID_ANY, lables[i], wxPoint(10, 20 + 30 * i));
			inputFields[i] = new wxTextCtrl(panel, 100 + i, wxEmptyString, wxPoint(150, 20 + 30 * i), wxSize(230, 20));
		}
		if(type == 1)btn = new wxButton(panel, 120, "Добавить", wxPoint(160, 150), wxSize(80, 20));
		else btn = new wxButton(panel, 120, "Удалить", wxPoint(160, 150), wxSize(80, 20));
		btn->Bind(wxEVT_BUTTON, &InputFrame::checkData, this);
	}

}

void InputFrame::checkData(wxCommandEvent& evt) {
	if (type == 0 || type == 3) {
		if (inputFields[0]->IsEmpty())wxMessageBox("Не все поля заполнены");
		else if (inputFields[1]->IsEmpty())wxMessageBox("Не все поля заполнены");
		else if (inputFields[2]->IsEmpty())wxMessageBox("Не все поля заполнены");
		else if (type == 0) {
			int day = calendar->GetDate().GetDay();
			int month = calendar->GetDate().GetMonth();
			int year = calendar->GetDate().GetYear();
			Client buf = Client(std::string(inputFields[0]->GetValue().mb_str()), Date(day, month, year), std::string(inputFields[1]->GetValue().mb_str()), std::string(inputFields[2]->GetValue().mb_str()));
			logic->AddData(buf);
			this->grid->update(logic->getClientList());
			this->Close();
		}
		else if (type == 3) {
			int day = calendar->GetDate().GetDay();
			int month = calendar->GetDate().GetMonth();
			int year = calendar->GetDate().GetYear();
			Client buf = Client(std::string(inputFields[0]->GetValue().mb_str()), Date(day, month, year), std::string(inputFields[1]->GetValue().mb_str()), std::string(inputFields[2]->GetValue().mb_str()));
			logic->DeleteData(buf);
			this->grid->update(logic->getClientList());
			this->Close();
		}
	}
	else if (type == 2 || type == 5) {
		if (inputFields[0]->IsEmpty())wxMessageBox("Не все поля заполнены");
		else if (inputFields[1]->IsEmpty())wxMessageBox("Не все поля заполнены");
		else if (inputFields[2]->IsEmpty())wxMessageBox("Не все поля заполнены");
		else if (type == 2){
				int day = calendar->GetDate().GetDay();
				int month = calendar->GetDate().GetMonth();
				int year = calendar->GetDate().GetYear();
				Order buf = Order(std::string(inputFields[0]->GetValue().mb_str()), std::string(inputFields[1]->GetValue().mb_str()), std::string(inputFields[2]->GetValue().mb_str()), Date(day, month, year));
				logic->AddData(buf);
				this->grid->update(logic->getOrderList());
				this->Close();
		}
		else if (type == 5) {
			int day = calendar->GetDate().GetDay();
			int month = calendar->GetDate().GetMonth();
			int year = calendar->GetDate().GetYear();
			Order buf = Order(std::string(inputFields[0]->GetValue().mb_str()), std::string(inputFields[1]->GetValue().mb_str()), std::string(inputFields[2]->GetValue().mb_str()), Date(day, month, year));
			logic->DeleteData(buf);
			this->grid->update(logic->getOrderList());
			this->Close();
		}
	}
	else if (type == 1 || type == 4) {
		if (inputFields[0]->IsEmpty())wxMessageBox("Не все поля заполнены");
		else if (inputFields[1]->IsEmpty())wxMessageBox("Не все поля заполнены");
		else if (inputFields[2]->IsEmpty())wxMessageBox("Не все поля заполнены");
		else if (inputFields[3]->IsEmpty())wxMessageBox("Не все поля заполнены");
		else if (!inputFields[2]->GetValue().IsNumber())wxMessageBox("Введите корректную стоимость в месяц");
		else if (!inputFields[3]->GetValue().IsNumber())wxMessageBox("Введите корректный минимальный срок действия");
		else if (type == 1) {
			short int i = wxAtoi(inputFields[2]->GetValue());
			short int j = wxAtoi(inputFields[2]->GetValue());
			if (j < 0 || i < 0)wxMessageBox("Значения не могут быть отрицательными");

			else {
				Subscribe buf = Subscribe(std::string(inputFields[0]->GetValue().mb_str()), std::string(inputFields[1]->GetValue().mb_str()), wxAtoi(inputFields[2]->GetValue()), wxAtoi(inputFields[2]->GetValue()));
				logic->AddData(buf);
				this->grid->update(logic->getSubscribesList());
				this->Close();
			}
		}
		else if (type == 4) {
			Subscribe buf = Subscribe(std::string(inputFields[0]->GetValue().mb_str()), std::string(inputFields[1]->GetValue().mb_str()), wxAtoi(inputFields[2]->GetValue()), wxAtoi(inputFields[2]->GetValue()));
			logic->DeleteData(buf);
			this->grid->update(logic->getSubscribesList());
			this->Close();
		}
	}
}

