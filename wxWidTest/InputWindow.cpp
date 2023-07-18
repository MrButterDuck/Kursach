#include "InputWindow.h"


wxBEGIN_EVENT_TABLE(InputFrame, wxFrame)
	EVT_CHOICE(220, InputFrame::updateSearch )
wxEND_EVENT_TABLE()

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
		if (type == 0) {
			btn = new wxButton(panel, 120, "Добавить", wxPoint(160, 260), wxSize(80, 20));
			btn->Bind(wxEVT_BUTTON, &InputFrame::checkData, this);
		}
		else {
			wxArrayString choices;
			choices.Add("по логину");
			choices.Add("по стране");
			choices.Add("по городу");
			choices.Add("по дате");
			this->choice = new wxChoice(panel, 220, wxPoint(30, 260), wxSize(80, 20), choices);
			this->choice->Select(0);
			btn = new wxButton(panel, 120, "Поиск", wxPoint(290, 260), wxSize(80, 20));
			btn->Bind(wxEVT_BUTTON, &InputFrame::searchData, this);
		}

	}
	else if (type == 2) {
		new wxStaticText(panel, wxID_ANY, "Логин", wxPoint(10, 20));
		new wxStaticText(panel, wxID_ANY, "Название услуги и\nДистрибьютор", wxPoint(10, 50));
		new wxStaticText(panel, wxID_ANY, "Дата начала действия", wxPoint(10, 110));
		wxArrayString logins;
		std::vector<Client>* loginList = this->logic->getClientList();
		for (auto cl : *loginList)logins.Add(cl.getLogin());
		wxArrayString subs;
		std::vector<Subscribe>* subList = this->logic->getSubscribesList();
		for (auto sb : *subList)subs.Add(sb.getName()+" "+ sb.getCompany());
		orderInput[0] = new wxChoice(panel, 543, wxPoint(150, 20), wxSize(230, 20), logins);
		orderInput[1] = new wxChoice(panel, 543, wxPoint(150, 50), wxSize(230, 20), subs);
		calendar = new wxCalendarCtrl(panel, 104, wxDefaultDateTime, wxPoint(150,110));
		btn = new wxButton(panel, 120, "Добавить", wxPoint(160, 260), wxSize(80, 20));
		btn->Bind(wxEVT_BUTTON, &InputFrame::checkData, this);
	}
	else if (type == 4 || type == 1) {
		std::string lables[4]{ "Название услуги", "Дистрибьютор","Стоимость в месяц", "Минимальный срок\nдействия" }; 
		for (int i = 0; i < 4; i++)
		{
			new wxStaticText(panel, wxID_ANY, lables[i], wxPoint(10, 20 + 30 * i));
			inputFields[i] = new wxTextCtrl(panel, 100 + i, wxEmptyString, wxPoint(150, 20 + 30 * i), wxSize(230, 20));
		}
		if (type == 1) {
			btn = new wxButton(panel, 120, "Добавить", wxPoint(160, 150), wxSize(80, 20));
			btn->Bind(wxEVT_BUTTON, &InputFrame::checkData, this);
		}
		else {
			wxArrayString choices;
			choices.Add("по названию");
			choices.Add("по компании");
			choices.Add("по стоимости");
			choices.Add("по длительности");
			choices.Add("по ключу");
			this->choice = new wxChoice(panel, 220, wxPoint(30, 150), wxSize(80, 20), choices);
			this->choice->Select(0);
			btn = new wxButton(panel, 120, "Поиск", wxPoint(290, 150), wxSize(80, 20));
			btn->Bind(wxEVT_BUTTON, &InputFrame::searchData, this);

		}
	}
	else if (type == 5) {
		std::string lables[4]{ "Логин", "Название услуги","Дистрибьютор", "Дата начала действия" };
		for (int i = 0; i < 4; i++)
		{
			new wxStaticText(panel, wxID_ANY, lables[i], wxPoint(10, 20 + 30 * i));
			if (i != 3)inputFields[i] = new wxTextCtrl(panel, 100 + i, wxEmptyString, wxPoint(150, 20 + 30 * i), wxSize(230, 20));
			else calendar = new wxCalendarCtrl(panel, 100 + i, wxDefaultDateTime, wxPoint(150, 20 + 30 * i));
		}
		wxArrayString choices;
		choices.Add("по логину");
		choices.Add("по названию");
		choices.Add("по компании");
		choices.Add("по дате");
		choices.Add("по ключу");
		this->choice = new wxChoice(panel, 220, wxPoint(30, 260), wxSize(80, 20), choices);
		this->choice->Select(0);
		btn = new wxButton(panel, 120, "Поиск", wxPoint(290, 260), wxSize(80, 20));
		btn->Bind(wxEVT_BUTTON, &InputFrame::searchData, this);
	}
}

void InputFrame::checkData(wxCommandEvent& evt) {
	if (type == 0 ) {
		if (inputFields[0]->IsEmpty())wxMessageBox("Не все поля заполнены");
		else if (inputFields[0]->GetValue().IsNumber())wxMessageBox("Введите корректный логин");
		else if (inputFields[1]->IsEmpty())wxMessageBox("Не все поля заполнены");
		else if (!inputFields[1]->GetValue().IsWord())wxMessageBox("Введите корректное название страны");
		else if (inputFields[2]->IsEmpty())wxMessageBox("Не все поля заполнены");
		else if (!inputFields[2]->GetValue().IsWord())wxMessageBox("Введите корректное название города");
		else {
			int day = calendar->GetDate().GetDay();
			int month = calendar->GetDate().GetMonth();
			int year = calendar->GetDate().GetYear();
			Client buf = Client(std::string(inputFields[0]->GetValue().MakeLower().mb_str()), Date(day, month, year), std::string(inputFields[2]->GetValue().mb_str()), std::string(inputFields[1]->GetValue().mb_str()));
			if (!logic->AddData(buf)) {
				if(logic->HtisFull())(new wxMessageDialog(nullptr, "Справочник клиентов переполнен", "Больше не влезет", wxOK))->ShowModal();
				else (new wxMessageDialog(nullptr, "Запись не является уникальной", "Для мамы ты всегда уникален", wxOK))->ShowModal();
			}
			this->grid->update(logic->getClientList());
			this->Close();
		}

	}
	else if (type == 2 ) {
		if (orderInput[0]->IsEmpty())wxMessageBox("Не все поля заполнены");
		else if (orderInput[1]->IsEmpty())wxMessageBox("Не все поля заполнены");
		else{
			std::vector<Client>* loginList = this->logic->getClientList();
			std::vector<Subscribe>* subList = this->logic->getSubscribesList();
			std::string login = loginList->at(orderInput[0]->GetSelection()).getLogin();
			std::string name = subList->at(orderInput[1]->GetSelection()).getName();
			std::string company = subList->at(orderInput[1]->GetSelection()).getCompany();
			int day = calendar->GetDate().GetDay();
			int month = calendar->GetDate().GetMonth();
			int year = calendar->GetDate().GetYear();
			Order buf = Order(login, name, company, Date(day, month, year));
			if(!logic->AddData(buf))(new wxMessageDialog(nullptr, "Запись не является уникальной", "Для мамы ты всегда уникален", wxOK))->ShowModal();
			this->grid->update(logic->getOrderList());
			this->Close();
		}
	}
	else if (type == 1 ) {
		if (inputFields[0]->IsEmpty())wxMessageBox("Не все поля заполнены");
		else if (!inputFields[0]->GetValue().IsWord())wxMessageBox("Введите корректное название услуги");
		else if (inputFields[1]->IsEmpty())wxMessageBox("Не все поля заполнены");
		else if (!inputFields[1]->GetValue().IsWord())wxMessageBox("Введите корректного дистрибьютора");
		else if (inputFields[2]->IsEmpty())wxMessageBox("Не все поля заполнены");
		else if (inputFields[3]->IsEmpty())wxMessageBox("Не все поля заполнены");
		else if (!inputFields[2]->GetValue().IsNumber())wxMessageBox("Введите корректную стоимость в месяц");
		else if (!inputFields[3]->GetValue().IsNumber())wxMessageBox("Введите корректный минимальный срок действия");
		else {
			short int i = wxAtoi(inputFields[2]->GetValue());
			short int j = wxAtoi(inputFields[2]->GetValue());
			if (j < 0 || i < 0)wxMessageBox("Значения не могут быть отрицательными");
			else {
				Subscribe buf = Subscribe(std::string(inputFields[0]->GetValue().mb_str()), std::string(inputFields[1]->GetValue().mb_str()), wxAtoi(inputFields[2]->GetValue()), wxAtoi(inputFields[3]->GetValue()));
				if(!logic->AddData(buf))(new wxMessageDialog(nullptr, "Запись не является уникальной", "Для мамы ты всегда уникален", wxOK))->ShowModal();
				this->grid->update(logic->getSubscribesList());
				this->Close();
			}
		}
	}
}

void InputFrame::searchData(wxCommandEvent& evt) {
	if (type == 3) {
		if (choice->GetSelection() == 0 && !inputFields[0]->IsEmpty()) {
			int res = logic->searchHT(Client(inputFields[0]->GetValue().ToStdString(), Date(), " ", " "));
			if (res != -1)this->grid->printSearch(res, logic->getClientList()->at(res));
			else this->grid->clearGrid();
		}
		else if (choice->GetSelection() == 1 && !inputFields[1]->IsEmpty()) {
			std::string buf = inputFields[1]->GetValue().ToStdString();
			TwoPointList<int>* res = logic->searchData(Date(), &buf, nullptr);
			if (res)this->grid->printSearch(res, logic->getClientList());
			else this->grid->clearGrid();
		}
		else if (choice->GetSelection() == 2 && !inputFields[2]->IsEmpty()) {
			std::string buf = inputFields[2]->GetValue().ToStdString();
			TwoPointList<int>* res = logic->searchData(Date(), nullptr, &buf);
			if (res)this->grid->printSearch(res, logic->getClientList());
			else this->grid->clearGrid();
		}
		else if (choice->GetSelection() == 3) {
			TwoPointList<int>* res = logic->searchData(Date(calendar->GetDate().GetDay(), calendar->GetDate().GetMonth(), calendar->GetDate().GetYear()), nullptr, nullptr);
			if (res)this->grid->printSearch(res, logic->getClientList());
			else this->grid->clearGrid();
		}

	}
	else if (type == 4) {
		if (choice->GetSelection() == 0 && !inputFields[0]->IsEmpty()) {
			std::string buf = inputFields[0]->GetValue().ToStdString();
			OnePointList<int>* res = logic->searchData(&buf, nullptr, nullptr, nullptr);
			if (res)this->grid->printSearch(res, logic->getSubscribesList());
			else this->grid->clearGrid();
		}
		else if (choice->GetSelection() == 1 && !inputFields[1]->IsEmpty()) {
			std::string buf = inputFields[1]->GetValue().ToStdString();
			OnePointList<int>* res = logic->searchData(nullptr, &buf, nullptr, nullptr);
			if (res)this->grid->printSearch(res, logic->getSubscribesList());
			else this->grid->clearGrid();
		}
		else if (choice->GetSelection() == 2 && !inputFields[2]->IsEmpty()) {
			std::string buf = inputFields[2]->GetValue().ToStdString();
			OnePointList<int>* res = logic->searchData(nullptr, nullptr, &buf, nullptr);
			if (res)this->grid->printSearch(res, logic->getSubscribesList());
			else this->grid->clearGrid();
		}
		else if (choice->GetSelection() == 3) {
			std::string buf = inputFields[3]->GetValue().ToStdString();
			OnePointList<int>* res = logic->searchData(nullptr , nullptr, nullptr, &buf);
			if (res)this->grid->printSearch(res, logic->getSubscribesList());
			else this->grid->clearGrid();
		}
		if (choice->GetSelection() == 4 && !inputFields[0]->IsEmpty() && !inputFields[1]->IsEmpty()) {
			int res = logic->searchHT(Subscribe(inputFields[0]->GetValue().ToStdString(), inputFields[0]->GetValue().ToStdString(), -1, -1));
			if (res != -1)this->grid->printSearch(res, logic->getSubscribesList()->at(res));
			else this->grid->clearGrid();
		}
	}
	else if (type == 5) {
		if (choice->GetSelection() == 0 && !inputFields[0]->IsEmpty()) {
			std::string buf = inputFields[0]->GetValue().ToStdString();
			CycleList<int>* res = logic->searchData(&buf, nullptr, nullptr, Date());
			if (res)this->grid->printSearch(res, logic->getOrderList());
			else this->grid->clearGrid();
		}
		else if (choice->GetSelection() == 1 && !inputFields[1]->IsEmpty()) {
			std::string buf = inputFields[1]->GetValue().ToStdString();
			CycleList<int>* res = logic->searchData(nullptr, &buf, nullptr, Date());
			if (res)this->grid->printSearch(res, logic->getOrderList());
			else this->grid->clearGrid();
		}
		else if (choice->GetSelection() == 2 && !inputFields[2]->IsEmpty()) {
			std::string buf = inputFields[2]->GetValue().ToStdString();
			CycleList<int>* res = logic->searchData(nullptr, nullptr, &buf, Date());
			if (res)this->grid->printSearch(res, logic->getOrderList());
			else this->grid->clearGrid();
		}
		else if (choice->GetSelection() == 3) {
			CycleList<int>* res = logic->searchData(nullptr, nullptr, nullptr, Date(calendar->GetDate().GetDay(), calendar->GetDate().GetMonth(), calendar->GetDate().GetYear()));
			if (res)this->grid->printSearch(res, logic->getOrderList());
			else this->grid->clearGrid();
		}
		if (choice->GetSelection() == 4 && !inputFields[0]->IsEmpty() && !inputFields[1]->IsEmpty() && !inputFields[2]->IsEmpty()) {
			int res = logic->searchHT(Order(inputFields[0]->GetValue().ToStdString(), inputFields[1]->GetValue().ToStdString(), inputFields[2]->GetValue().ToStdString(), Date(calendar->GetDate().GetDay(), calendar->GetDate().GetMonth(), calendar->GetDate().GetYear())));
			if (res != -1)this->grid->printSearch(res, logic->getSubscribesList()->at(res));
			else this->grid->clearGrid();
		}
	}
}

void InputFrame::updateSearch(wxCommandEvent& evt) {
	if (type == 3) {
		if (choice->GetSelection() == 0) {
			inputFields[0]->Enable();
			inputFields[1]->Disable();
			inputFields[2]->Disable();
			calendar->Disable();
		}
		if (choice->GetSelection() == 1) {
			inputFields[0]->Disable();
			inputFields[1]->Enable();
			inputFields[2]->Disable();
			calendar->Disable();
		}
		if (choice->GetSelection() == 2) {
			inputFields[0]->Disable();
			inputFields[1]->Disable();
			inputFields[2]->Enable();
			calendar->Disable();
		}
		if (choice->GetSelection() == 3) {
			inputFields[0]->Disable();
			inputFields[1]->Disable();
			inputFields[2]->Disable();
			calendar->Enable();
		}
	}
	else if (type == 4) {
		if (choice->GetSelection() == 0) {
			inputFields[0]->Enable();
			inputFields[1]->Disable();
			inputFields[2]->Disable();
			inputFields[3]->Disable();
		}
		if (choice->GetSelection() == 1) {
			inputFields[0]->Disable();
			inputFields[1]->Enable();
			inputFields[2]->Disable();
			inputFields[3]->Disable();
		}
		if (choice->GetSelection() == 2) {
			inputFields[0]->Disable();
			inputFields[1]->Disable();
			inputFields[2]->Enable();
			inputFields[3]->Disable();
		}
		if (choice->GetSelection() == 3) {
			inputFields[0]->Disable();
			inputFields[1]->Disable();
			inputFields[2]->Disable();
			inputFields[3]->Enable();
		}
		if (choice->GetSelection() == 4) {
			inputFields[0]->Enable();
			inputFields[1]->Enable();
			inputFields[2]->Disable();
			inputFields[3]->Disable();
		}
	}
	else if (type == 5) {
		if (choice->GetSelection() == 0) {
			inputFields[0]->Enable();
			inputFields[1]->Disable();
			inputFields[2]->Disable();
			calendar->Disable();
		}
		if (choice->GetSelection() == 1) {
			inputFields[0]->Disable();
			inputFields[1]->Enable();
			inputFields[2]->Disable();
			calendar->Disable();
		}
		if (choice->GetSelection() == 2) {
			inputFields[0]->Disable();
			inputFields[1]->Disable();
			inputFields[2]->Enable();
			calendar->Disable();
		}
		if (choice->GetSelection() == 3) {
			inputFields[0]->Disable();
			inputFields[1]->Disable();
			inputFields[2]->Disable();
			calendar->Enable();
		}
		if (choice->GetSelection() == 4) {
			inputFields[0]->Enable();
			inputFields[1]->Enable();
			inputFields[2]->Enable();
			calendar->Enable();
		}
	}
}

