#include "Logic.h"

Logic::Logic(int size, int k) {
	this->ht_szie = size;
	this->ht_k = k;
	this->OrderLoginTree = new AvlTree1<int>;
	this->OrderNameTree = new AvlTree1<int>;
	this->OrderCompanyTree = new AvlTree1< int>;
	this->OrderDateTree = new AvlTree1< int>;
	this->OrderHT = new HashTable1(100);

	this->SubscribeNameTree = new AvlTree2< int>;
	this->SubscribeCompanyTree = new AvlTree2<int>;
	this->SubscribeCostTree = new AvlTree2< int>;
	this->SubscribeMinDurTree = new AvlTree2< int>;
	this->SubscribeHT = new HashTable3(100);
	this->SubscribeHT->setK(ht_k);


	this->ClientCountryTree = new AvlTree3< int>;
	this->ClientTownTree = new AvlTree3< int>;
	this->ClientDateTree = new AvlTree3< int>;
	this->ClientHT = new HashTable2(ht_szie);

	this->ordersCount = 0;
	this->clientsCount = 0;
	this->subscribesCount = 0;
}

Logic::~Logic() {

}

bool Logic::AddData(Order& data) {
	if (this->OrderHT->Add(&data, this->ordersCount)) {
		OrderCompanyTree->push(data.getCompany(), ordersCount);
		OrderLoginTree->push(data.getLogin(), ordersCount);
		OrderDateTree->push(data.getStartDate().toString(), ordersCount);
		OrderNameTree->push(data.getName(), ordersCount);
		Orders.push_back(data);
		this->ordersCount++;
		return true;
	}
	else return false;
}

bool Logic::AddData(Subscribe& data) {
	std::string key = data.getName() + data.getCompany();
	if (SubscribeHT->add(&key, this->subscribesCount)) {
		SubscribeCompanyTree->push(data.getCompany(), subscribesCount);
		SubscribeNameTree->push(data.getName(), subscribesCount);
		SubscribeCostTree->push(std::to_string(data.getCost()), subscribesCount);
		SubscribeMinDurTree->push(std::to_string(data.getMinimalDuration()), subscribesCount);
		Subscribes.push_back(data);
		this->subscribesCount++;
		return true;
	}
	else return false;

}

bool Logic::AddData(Client& data) {
	if (this->ClientHT->Add(data.getLogin(), this->clientsCount)) {
		ClientCountryTree->push(data.getCountry(), clientsCount);
		ClientDateTree->push(data.getDate().toString(), clientsCount);
		ClientTownTree->push(data.getTown(), clientsCount);
		Clients.push_back(data);
		this->clientsCount++;
		return true;
	}
	else return false;

}

void Logic::DeleteOrderData(int id) {

	Order data = this->Orders.at(id);
	this->OrderLoginTree->delete_key(data.getLogin(), id);
	this->OrderNameTree->delete_key(data.getName(), id);
	this->OrderCompanyTree->delete_key(data.getCompany(), id);
	this->OrderDateTree->delete_key(data.getStartDate().toString(), id);
	this->OrderHT->Delete(&data);
	this->ordersCount--;
	if (id != subscribesCount) {
		Order last = this->Orders.at(this->ordersCount);
		std::swap(Orders[id], Orders[ordersCount]);
		this->OrderLoginTree->delete_key(last.getLogin(), this->ordersCount);
		this->OrderNameTree->delete_key(last.getName(), this->ordersCount);
		this->OrderCompanyTree->delete_key(last.getCompany(), this->ordersCount);
		this->OrderDateTree->delete_key(last.getStartDate().toString(), this->ordersCount);
		this->OrderHT->Delete(&last);
		this->Orders.pop_back();
		this->OrderCompanyTree->push(last.getCompany(), id);
		this->OrderLoginTree->push(last.getLogin(), id);
		this->OrderDateTree->push(last.getStartDate().toString(), id);
		this->OrderNameTree->push(last.getName(), id);
		this->OrderHT->Add(&last, id);
	}
	else this->Orders.pop_back();
}

bool Logic::DeleteSubscribeData(int id) {

	Subscribe data = this->Subscribes.at(id);
	std::string dataName = data.getName();
	if (this->searchData(nullptr, &dataName, nullptr, Date()))return false;
	this->SubscribeNameTree->delete_key(data.getName(), id);
	this->SubscribeCompanyTree->delete_key(data.getCompany(), id);
	this->SubscribeCostTree->delete_key(std::to_string(data.getCost()), id);
	this->SubscribeMinDurTree->delete_key(std::to_string(data.getMinimalDuration()), id);
	std::string key = data.getName() + data.getCompany();
	this->SubscribeHT->remove(&key);
	this->subscribesCount--;
	if (id != subscribesCount) {
		Subscribe last = this->Subscribes.at(this->subscribesCount);
		std::swap(Subscribes[id], Subscribes[subscribesCount]);
		this->SubscribeNameTree->delete_key(last.getName(), subscribesCount);
		this->SubscribeCompanyTree->delete_key(last.getCompany(), subscribesCount);
		this->SubscribeCostTree->delete_key(std::to_string(last.getCost()), subscribesCount);
		this->SubscribeMinDurTree->delete_key(std::to_string(last.getMinimalDuration()), subscribesCount);
		this->Subscribes.pop_back();
		key = last.getName() + last.getCompany();
		this->SubscribeHT->remove(&key);
		this->SubscribeNameTree->push(last.getName(), id);
		this->SubscribeCompanyTree->push(last.getCompany(), id);
		this->SubscribeCostTree->push(std::to_string(last.getCost()), id);
		this->SubscribeMinDurTree->push(std::to_string(last.getMinimalDuration()), id);
		this->SubscribeHT->add(&key, id);
	}
	else this->Subscribes.pop_back();
	return true;

}

bool Logic::DeleteClientData(int id) {	
	Client data = this->Clients.at(id);
	std::string dataLogin = data.getLogin();
	if (this->searchData(&dataLogin, nullptr, nullptr, Date()))return false;
	this->ClientCountryTree->delete_key(data.getCountry(), id);
	this->ClientTownTree->delete_key(data.getTown(), id);
	this->ClientDateTree->delete_key(data.getDate().toString(), id);
	this->ClientHT->Delete(data.getLogin());
	this->clientsCount--;
	if (id != clientsCount) {
		Client last = this->Clients.at(this->clientsCount);
		std::swap(Clients[id], Clients[clientsCount]);
		this->ClientCountryTree->delete_key(last.getCountry(), clientsCount);
		this->ClientTownTree->delete_key(last.getTown(), clientsCount);
		this->ClientDateTree->delete_key(last.getDate().toString(), clientsCount);
		this->Clients.pop_back();
		this->ClientHT->Delete(last.getLogin());
		this->ClientCountryTree->push(last.getCountry(), id);
		this->ClientTownTree->push(last.getTown(), id);
		this->ClientDateTree->push(last.getDate().toString(), id);
		this->ClientHT->Add(last.getLogin(), id);
	}
	else this->Clients.pop_back();
	return true;
}

unsigned int Logic::getClientCount() {
	return this->clientsCount;
}

unsigned int Logic::getSubscribesCount() {
	return this->subscribesCount;
}

unsigned int Logic::getOrderCount() {
	return this->ordersCount;
}

Order* Logic::getOrder(int i) {
	return &this->Orders.at(i);
}

Client* Logic::getClient(int i) {
	return &this->Clients.at(i);
}

Subscribe* Logic::getSubscribe(int i) {
	return &this->Subscribes.at(i);
}

std::vector<Order>* Logic::getOrderList() {
	return &this->Orders;
}
std::vector<Subscribe>* Logic::getSubscribesList() {
	return &this->Subscribes;
}
std::vector<Client>* Logic::getClientList() {
	return &this->Clients;
}

std::string Logic::PrintOrderStruct(int type) {
	switch (type) {
		case 0:return OrderLoginTree->print();
		case 1: return OrderNameTree->print();
		case 2: return OrderCompanyTree->print();
		case 3: return OrderDateTree->print();
		case 4: return OrderHT->Print();
	}
}

std::string Logic::PrintSubscribeStruct(int type) {
	switch (type) {
	case 0:return SubscribeNameTree->print();
	case 1: return SubscribeCompanyTree->print();
	case 2: return SubscribeCostTree->print();
	case 3: return SubscribeMinDurTree->print();
	case 4: return SubscribeHT->Print();
	}
}

std::string Logic::PrintClientStruct(int type) {
	switch (type) {
	case 0:return ClientDateTree->print();
	case 1: return ClientCountryTree->print();
	case 2: return ClientTownTree->print();
	case 3: return ClientHT->Print();
	}
}

void Logic::readFromFile(std::string path) {
	this->Clear(0);
	this->Clear(1);
	this->Clear(2);
	std::fstream in;
	in.open(path+"Clients.txt");
	std::string buffer;
	if (in.is_open())
	{
		while (std::getline(in, buffer))
		{
			std::stringstream l(buffer);
			int vertex_id;
			std::string login, country, town;
			int day, month, year;
			l >> login >> day >> month >> year >> country >> town;
			Client cln(login, Date(day, month, year), country, town);
			this->AddData(cln);
		}
	}
	in.close();
	in.open(path + "Subscribes.txt");
	if (in.is_open())
	{
		while (std::getline(in, buffer))
		{
			std::stringstream l(buffer);
			int vertex_id;
			std::string name, company;
			int cost, duration;
			l >> name >> company >> cost >> duration;
			Subscribe cln(name, company, cost, duration);
			this->AddData(cln);
		}
	}
	in.close();
	in.open(path + "Orders.txt");
	if (in.is_open())
	{
		while (std::getline(in, buffer))
		{
			std::stringstream l(buffer);
			int vertex_id;
			std::string login, name, company;
			int day, month, year;
			l >> login >> day >> month >> year >> name >> company;
			Order cln(login, name, company, Date(day, month, year));
			this->AddData(cln);
		}
	}
	in.close();
}

void Logic::writeToFile(std::string path) {
	std::ofstream in;
	in.open(path + "Clients.txt");
	if (in.is_open())
	{
		for (int i = 0; i < this->clientsCount; i++) {
			Client *cln = &this->Clients.at(i);
			in << cln->getLogin() << " " << cln->getDate().getDay() << " " << cln->getDate().getMonth() << " " << cln->getDate().getYear() << " " << cln->getCountry() << " " << cln->getTown() << std::endl;
		}
	}
	in.close();
	in.open(path + "Subscribes.txt");
	if (in.is_open())
	{
		for (int i = 0; i < this->subscribesCount; i++) {
			Subscribe* cln = &this->Subscribes.at(i);
			in << cln->getName() << " " << cln->getCompany() << " " << cln->getCost() << " " << cln->getMinimalDuration()  << std::endl;
		}
	}
	in.close();
	in.open(path + "Orders.txt");
	if (in.is_open())
	{
		for (int i = 0; i < this->ordersCount; i++) {
			Order* cln = &this->Orders.at(i);
			in << cln->getLogin() << " " << cln->getStartDate().getDay() << " " << cln->getStartDate().getMonth() << " " << cln->getStartDate().getYear() << " " << cln->getName() << " " << cln->getCompany() << std::endl;
		}
	}
	in.close();
}

void Logic::Clear(int type) {
	if (type == 0)
	{
		Clients.clear();
		delete ClientTownTree;
		delete ClientCountryTree;
		delete ClientDateTree;
		clientsCount = 0;
		this->ClientCountryTree = new AvlTree3< int>;
		this->ClientTownTree = new AvlTree3< int>;
		this->ClientDateTree = new AvlTree3< int>;
		this->ClientHT = new HashTable2(this->ht_szie);
	}
	else if (type == 1)
	{
		Subscribes.clear();
		delete SubscribeNameTree;
		delete SubscribeCompanyTree;
		delete SubscribeCostTree;
		delete SubscribeMinDurTree;
		delete SubscribeHT;
		subscribesCount = 0;
		this->SubscribeNameTree = new AvlTree2< int>;
		this->SubscribeCompanyTree = new AvlTree2<int>;
		this->SubscribeCostTree = new AvlTree2< int>;
		this->SubscribeMinDurTree = new AvlTree2< int>;
		this->SubscribeHT = new HashTable3(100);
		this->SubscribeHT->setK(this->ht_k);
	}
	else if (type == 2)
	{
		Orders.clear();
		delete OrderLoginTree;
		delete OrderNameTree;
		delete OrderCompanyTree;
		delete OrderDateTree;
		delete OrderHT;
		ordersCount = 0;
		this->OrderLoginTree = new AvlTree1<int>;
		this->OrderNameTree = new AvlTree1<int>;
		this->OrderCompanyTree = new AvlTree1< int>;
		this->OrderDateTree = new AvlTree1< int>;
		this->OrderHT = new HashTable1(100);
	}
}

CycleList<int>* Logic::searchData(std::string* login, std::string* Name, std::string* Company, Date startDate) {
	if (login) {
		Node<int>* res = OrderLoginTree->search_key(*login);
		if (res)return res->value;
		else return nullptr;
	}
	else if (Name) {
		Node<int>* res = OrderNameTree->search_key(*Name);
		if (res)return res->value;
		else return nullptr;
	}
	else if (Company) {
		Node<int>* res = OrderCompanyTree->search_key(*Company);
		if (res)return res->value;
		else return nullptr;
	}
	else {
		Node<int>* res = OrderDateTree->search_key(startDate.toString());
		if (res)return res->value;
		else return nullptr;
	}
}

OnePointList<int>* Logic::searchData(std::string* Name, std::string* Company, std::string* cost, std::string* dur) {
	if (Name) {
		treeNode<int>* res = SubscribeNameTree->search_key(*Name);
		if (res)return res->value;
		else return nullptr;
	}
	else if (Company) {
		treeNode<int>* res = SubscribeCompanyTree->search_key(*Company);
		if (res)return res->value;
		else return nullptr;
	}
	else if (cost) {
		treeNode<int>* res  = SubscribeCostTree->search_key(*cost);
		if (res)return res->value;
		else return nullptr;
	}
	else {
		treeNode<int>* res = SubscribeMinDurTree->search_key(*dur);
		if (res)return res->value;
		else return nullptr;
	}
}

TwoPointList<int>* Logic::searchData(Date date, std::string* Country, std::string* Town) {
	if (Country) {
		elem<int>* res = ClientCountryTree->search_key(*Country);
		if (res)return res->value;
		else return nullptr;
	}
	else if (Town) {
		elem<int>* res = ClientTownTree->search_key(*Town);
		if (res)return res->value;
		else return nullptr;
	}
	else {
		elem<int>* res = ClientDateTree->search_key(date.toString());
		if (res)return res->value;
		else return nullptr;
	}

}


int Logic::searchHT(Order data) {
	return OrderHT->Find(&data);
}

int Logic::searchHT(Subscribe data) {
	std::string key = data.getName() + data.getCompany();
	return SubscribeHT->find(&key);
}

int Logic::searchHT(Client data) {
	return ClientHT->search(data.getLogin());
}