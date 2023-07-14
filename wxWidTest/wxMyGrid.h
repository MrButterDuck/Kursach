#pragma once
#include <wx/wx.h>
#include <wx/grid.h>
#include "DataTypes.h"
#include "Structs.h"

class wxMyGrid : public wxGrid
{
public:
	wxMyGrid(wxWindow* parent);
	void update(CycleList<Order>* lst);
	void update(OnePointList<Subscribe>* lst);
	void update(TwoPointList<Client>* lst);
	void setColumnSize(unsigned int size);
protected:
	wxSize DoGetBestSize() const override;
};

