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

void wxMyGrid::update(std::vector<Order>* lst) {
	if (this->GetNumberRows() >= 1)this->DeleteRows(0, this->GetNumberRows());
	this->AppendRows(lst->size());
	this->ClearGrid();
	int j = 0;
	for (auto val: *lst) {
		this->SetCellValue(wxGridCellCoords(j, 0), val.getLogin());
		this->SetCellValue(wxGridCellCoords(j, 1), val.getName());
		this->SetCellValue(wxGridCellCoords(j, 2), val.getCompany());
		this->SetCellValue(wxGridCellCoords(j, 3), val.getStartDate().toString());
		j++;
	}
	this->SetColLabelValue(0, "Логин");
	this->SetColLabelValue(1, "Название\nподписки");
	this->SetColLabelValue(2, "Компания");
	this->SetColLabelValue(3, "Дата начала");
}

void wxMyGrid::update(std::vector<Subscribe>* lst) {
	if (this->GetNumberRows() >= 1)this->DeleteRows(0, this->GetNumberRows());
	this->AppendRows(lst->size());
	this->ClearGrid();
	int j = 0;
	for (auto val : *lst) {
		this->SetCellValue(wxGridCellCoords(j, 0), val.getName());
		this->SetCellValue(wxGridCellCoords(j, 1), val.getCompany());
		this->SetCellValue(wxGridCellCoords(j, 2), std::to_string(val.getCost()));
		this->SetCellValue(wxGridCellCoords(j, 3), std::to_string(val.getMinimalDuration()));
		j++;
	}
	this->SetColLabelValue(0, "Название\nподписки");
	this->SetColLabelValue(1, "Компания");
	this->SetColLabelValue(2, "Стоимость");
	this->SetColLabelValue(3, "Минимальный\nсрок действия");
}

void wxMyGrid::update(std::vector<Client>* lst) {
	if (this->GetNumberRows() >= 1)this->DeleteRows(0, this->GetNumberRows());
	this->AppendRows(lst->size());
	this->ClearGrid();
	int j = 0;
	for (auto val : *lst) {
		this->SetCellValue(wxGridCellCoords(j, 0), val.getLogin());
		this->SetCellValue(wxGridCellCoords(j, 1), val.getDate().toString());
		this->SetCellValue(wxGridCellCoords(j, 2), val.getCountry());
		this->SetCellValue(wxGridCellCoords(j, 3), val.getTown());
		j++;
	}
	this->SetColLabelValue(0, "Логин");
	this->SetColLabelValue(1, "Дата рождения");
	this->SetColLabelValue(2, "Страна");
	this->SetColLabelValue(3, "Город");
}

void wxMyGrid::printSearch(int id, Client val) {
	if (this->GetNumberRows() >= 1)this->DeleteRows(0, this->GetNumberRows());
	this->AppendRows(1);
	this->SetCellValue(wxGridCellCoords(0, 0), val.getLogin());
	this->SetCellValue(wxGridCellCoords(0, 1), val.getDate().toString());
	this->SetCellValue(wxGridCellCoords(0, 2), val.getCountry());
	this->SetCellValue(wxGridCellCoords(0, 3), val.getTown());
}

void wxMyGrid::printSearch(TwoPointList<int>* ids, std::vector<Client>* lst) {
	if (this->GetNumberRows() >= 1)this->DeleteRows(0, this->GetNumberRows());
	this->AppendRows(ids->getCount());
	for (int j = 0; j < ids->getCount(); j++) {
		this->SetCellValue(wxGridCellCoords(j, 0), lst->at(*ids->get_element(j)).getLogin());
		this->SetCellValue(wxGridCellCoords(j, 1), lst->at(*ids->get_element(j)).getDate().toString());
		this->SetCellValue(wxGridCellCoords(j, 2), lst->at(*ids->get_element(j)).getCountry());
		this->SetCellValue(wxGridCellCoords(j, 3), lst->at(*ids->get_element(j)).getTown());
	}
}

void wxMyGrid::printSearch(int id, Subscribe val) {
	if (this->GetNumberRows() >= 1)this->DeleteRows(0, this->GetNumberRows());
	this->AppendRows(1);
	this->SetCellValue(wxGridCellCoords(0, 0), val.getName());
	this->SetCellValue(wxGridCellCoords(0, 1), val.getCompany());
	this->SetCellValue(wxGridCellCoords(0, 2), std::to_string(val.getCost()));
	this->SetCellValue(wxGridCellCoords(0, 3), std::to_string(val.getMinimalDuration()));
}

void wxMyGrid::printSearch(OnePointList<int>* ids, std::vector<Subscribe>* lst) {
	if (this->GetNumberRows() >= 1)this->DeleteRows(0, this->GetNumberRows());
	this->AppendRows(ids->getCount());
	for (int j = 0; j < ids->getCount(); j++) {
		this->SetCellValue(wxGridCellCoords(j, 0), lst->at(*ids->get_element(j)).getName());
		this->SetCellValue(wxGridCellCoords(j, 1), lst->at(*ids->get_element(j)).getCompany());
		this->SetCellValue(wxGridCellCoords(j, 2), std::to_string(lst->at(*ids->get_element(j)).getCost()));
		this->SetCellValue(wxGridCellCoords(j, 3), std::to_string(lst->at(*ids->get_element(j)).getMinimalDuration()));
	}
}

void wxMyGrid::printSearch(int id, Order val) {
	if (this->GetNumberRows() >= 1)this->DeleteRows(0, this->GetNumberRows());
	this->AppendRows(1);
	this->SetCellValue(wxGridCellCoords(0, 0), val.getLogin());
	this->SetCellValue(wxGridCellCoords(0, 1), val.getName());
	this->SetCellValue(wxGridCellCoords(0, 2), val.getCompany());
	this->SetCellValue(wxGridCellCoords(0, 3), val.getStartDate().toString());
}

void wxMyGrid::printSearch(CycleList<int>* ids, std::vector<Order>* lst) {
	if (this->GetNumberRows() >= 1)this->DeleteRows(0, this->GetNumberRows());
	this->AppendRows(ids->getCount());
	for (int j = 0; j < ids->getCount(); j++) {
		this->SetCellValue(wxGridCellCoords(j, 0), lst->at(*ids->get_data_by_id(j)).getLogin());
		this->SetCellValue(wxGridCellCoords(j, 1), lst->at(*ids->get_data_by_id(j)).getName());
		this->SetCellValue(wxGridCellCoords(j, 2), lst->at(*ids->get_data_by_id(j)).getCompany());
		this->SetCellValue(wxGridCellCoords(j, 3), lst->at(*ids->get_data_by_id(j)).getStartDate().toString());
	}
}
void wxMyGrid::clearGrid() {
	if (this->GetNumberRows() >= 1)this->DeleteRows(0, this->GetNumberRows());
}