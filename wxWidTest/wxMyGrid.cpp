#include "wxMyGrid.h"

wxMyGrid::wxMyGrid(wxWindow* parent) : wxGrid(parent, wxID_ANY) {

}

wxSize wxMyGrid::DoGetBestSize() const{
	return GetParent()->GetClientSize();
}

void wxMyGrid::setColumnSize(unsigned int size) {
	int colWidth = (size - wxSystemSettings::GetMetric(wxSYS_VSCROLL_X) - this->GetRowLabelSize()) / 4;
	for (int i = 0; i < 4; i++) this->SetColSize(i, colWidth);
}

void wxMyGrid::update(CycleList<Order>* lst) {
	if (this->GetNumberRows() >= 1)this->DeleteRows(0, this->GetNumberRows());
	this->AppendRows(lst->getCount());
	this->ClearGrid();
	for (int j = 0; j < lst->getCount(); j++) {
		Order* data = lst->get_data_by_id(j);
		this->SetCellValue(wxGridCellCoords(j, 0), data->getLogin());
		this->SetCellValue(wxGridCellCoords(j, 1), data->getName());
		this->SetCellValue(wxGridCellCoords(j, 2), data->getCompany());
		this->SetCellValue(wxGridCellCoords(j, 3), data->getStartDate().toString());
	}
	this->SetColLabelValue(0, "Логин");
	this->SetColLabelValue(1, "Название\nподписки");
	this->SetColLabelValue(2, "Компания");
	this->SetColLabelValue(3, "Дата начала");
}

void wxMyGrid::update(OnePointList<Subscribe>* lst) {
	if (this->GetNumberRows() >= 1)this->DeleteRows(0, this->GetNumberRows());
	this->AppendRows(lst->getCount());
	this->ClearGrid();
	for (int j = 0; j < lst->getCount(); j++) {
		Subscribe* data = lst->get_element(j);
		this->SetCellValue(wxGridCellCoords(j, 0), data->getName());
		this->SetCellValue(wxGridCellCoords(j, 1), data->getCompany());
		this->SetCellValue(wxGridCellCoords(j, 2), std::to_string(data->getCost()));
		this->SetCellValue(wxGridCellCoords(j, 3), std::to_string(data->getMinimalDuration()));
	}
	this->SetColLabelValue(0, "Название\nподписки");
	this->SetColLabelValue(1, "Компания");
	this->SetColLabelValue(2, "Стоимость");
	this->SetColLabelValue(3, "Минимальный\nсрок действия");
}

void wxMyGrid::update(TwoPointList<Client>* lst) {
	if (this->GetNumberRows() >= 1)this->DeleteRows(0, this->GetNumberRows());
	this->AppendRows(lst->getCount());
	this->ClearGrid();
	for (int j = 0; j < lst->getCount(); j++) {
		Client* data = lst->get_element(j);
		this->SetCellValue(wxGridCellCoords(j, 0), data->getLogin());
		this->SetCellValue(wxGridCellCoords(j, 1), data->getDate().toString());
		this->SetCellValue(wxGridCellCoords(j, 2), data->getCountry());
		this->SetCellValue(wxGridCellCoords(j, 3), data->getTown());
	}
	this->SetColLabelValue(0, "Логин");
	this->SetColLabelValue(1, "Дата рождения");
	this->SetColLabelValue(2, "Страна");
	this->SetColLabelValue(3, "Город");
}