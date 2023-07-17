#pragma once
#include <wx/wx.h>
#include <wx/grid.h>
#include "DataTypes.h"
#include "Structs.h"

class wxMyGrid : public wxGrid
{
public:
	wxMyGrid(wxWindow* parent);
	void update(std::vector<Order>* lst);
	void update(std::vector<Subscribe>* lst);
	void update(std::vector<Client>* lst);
	void setColumnSize(unsigned int size);
	void printSearch(int id, Client val);
	void printSearch(int id, Subscribe val);
	void printSearch(int id, Order val);
	void printSearch(CycleList<int>* ids, std::vector<Order>* lst);
	void printSearch(TwoPointList<int>* ids, std::vector<Client>* lst);
	void printSearch(OnePointList<int>* ids, std::vector<Subscribe>* lst);
	void clearGrid();
protected:
	wxSize DoGetBestSize() const override;
};

