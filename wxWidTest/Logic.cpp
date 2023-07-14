#include "Logic.h"

Logic::Logic() {
	this->Orders = new CycleList<Order>;
	this->OrderLoginTree = new AvlTree1<std::string, Order*>;
	this->OrderNameTree = new AvlTree1<std::string, Order*>;
	this->OrderCompanyTree = new AvlTree1<std::string, Order*>;
	this->OrderDateTree = new AvlTree1<Date, Order*>;
	this->OrderHT = new HashTable1(100);

	this->Subscribes = new OnePointList<Subscribe>;
	this->SubscribeNameTree = new AvlTree2<std::string, Subscribe*>;
	this->SubscribeCompanyTree = new AvlTree2<std::string, Subscribe*>;
	this->SubscribeCostTree = new AvlTree2<unsigned int, Subscribe*>;
	this->SubscribeMinDurTree = new AvlTree2<unsigned int, Subscribe*>;
	this->SubscribeHT = new HashTable3(100);
	this->SubscribeHT->setK(3);

	this->Clients = new TwoPointList<Client>;
	this->ClientCountryTree = new AvlTree3<std::string, Client*>;
	this->ClientTownTree = new AvlTree3<std::string, Client*>;
	this->ClientDateTree = new AvlTree3<Date, Client*>;
	this->ClientHT = new HashTable2(10000);

	this->ordersCount = 0;
	this->clientsCount = 0;
	this->subscribesCount = 0;
}

Logic::~Logic() {
	delete Orders;
	delete Subscribes;
	delete Clients;
}

void Logic::AddData(Order& data) {
	Orders->push_back(data);
	int i = 0;
	for (i = 0; i < this->Orders->getCount() && data != *this->Orders->get_data_by_id(i); i++);
	this->OrderLoginTree->push(this->Orders->get_data_by_id(i)->getLogin(), this->Orders->get_data_by_id(i));
	this->OrderNameTree->push(this->Orders->get_data_by_id(i)->getName(), this->Orders->get_data_by_id(i));
	this->OrderCompanyTree->push(this->Orders->get_data_by_id(i)->getCompany(), this->Orders->get_data_by_id(i));
	this->OrderDateTree->push(this->Orders->get_data_by_id(i)->getStartDate(), this->Orders->get_data_by_id(i));
	this->OrderHT->Add(this->Orders->get_data_by_id(i));
	this->ordersCount++;
}

void Logic::AddData(Subscribe& data) {
	Subscribes->push_back(data);
	int i = 0;
	for (i = 0; i < this->Subscribes->getCount() && data != *this->Subscribes->get_element(i); i++);
	this->SubscribeNameTree->push(this->Subscribes->get_element(i)->getName(), this->Subscribes->get_element(i));
	this->SubscribeCompanyTree->push(this->Subscribes->get_element(i)->getCompany(), this->Subscribes->get_element(i));
	this->SubscribeCostTree->push(this->Subscribes->get_element(i)->getCost(), this->Subscribes->get_element(i));
	this->SubscribeMinDurTree->push(this->Subscribes->get_element(i)->getMinimalDuration(), this->Subscribes->get_element(i));
	this->subscribesCount++;
}

void Logic::AddData(Client& data) {
	this->Clients->push_back(data);
	int i = 0;
	for (i = 0; i < this->Clients->getCount() && data != *this->Clients->get_element(i); i++);
	this->ClientCountryTree->push(this->Clients->get_element(i)->getCountry(), this->Clients->get_element(i));
	this->ClientTownTree->push(this->Clients->get_element(i)->getTown(), this->Clients->get_element(i));
	this->ClientDateTree->push(this->Clients->get_element(i)->getDate(), this->Clients->get_element(i));
	this->ClientHT->Add(this->Clients->get_element(i));
	this->clientsCount++;
}

void Logic::DeleteData(Order& data) {
	int i = 0;
	for (i = 0; i < this->Orders->getCount() && data != *this->Orders->get_data_by_id(i); i++);
	if (i < this->Orders->getCount()) {
		if (data == *this->Orders->get_data_by_id(i)) {
			//this->OrderNameTree->delete_key(this->Orders->get_data_by_id(i)->getName(), this->Orders->get_data_by_id(i));
			//this->OrderCompanyTree->delete_key(this->Orders->get_data_by_id(i)->getCompany(), this->Orders->get_data_by_id(i));
			//this->OrderLoginTree->push(this->Orders->get_data_by_id(i)->getLogin(), this->Orders->get_data_by_id(i));
			//this->OrderDateTree->push(this->Orders->get_data_by_id(i)->getStartDate(), this->Orders->get_data_by_id(i));
			//this->OrderHT->Delete(this->Orders->get_data_by_id(i));
			this->Orders->delete_by_value(data);
		}
	}
	this->ordersCount--;
}

void Logic::DeleteData(Subscribe& data) {
	int i = 0;
	for (i = 0; i < this->Subscribes->getCount() && data != *this->Subscribes->get_element(i); i++);
	if (i < this->Subscribes->getCount()) {
		if (data == *this->Subscribes->get_element(i)) {
			this->SubscribeNameTree->delete_key(this->Subscribes->get_element(i)->getName(), this->Subscribes->get_element(i));
			this->SubscribeCompanyTree->delete_key(this->Subscribes->get_element(i)->getCompany(), this->Subscribes->get_element(i));
			this->SubscribeCostTree->push(this->Subscribes->get_element(i)->getCost(), this->Subscribes->get_element(i));
			this->SubscribeMinDurTree->push(this->Subscribes->get_element(i)->getMinimalDuration(), this->Subscribes->get_element(i));
			this->SubscribeHT->remove(this->Subscribes->get_element(i));
			this->Subscribes->delete_element(data);
		}
	}
	this->subscribesCount--;
}

void Logic::DeleteData(Client& data) {
	int i = 0;
	for (i = 0; i < this->Clients->getCount() && data != *this->Clients->get_element(i); i++);
	if (i < this->Clients->getCount()) {
		if (data == *this->Clients->get_element(i)) {
			this->ClientCountryTree->delete_key(this->Clients->get_element(i)->getCountry(), this->Clients->get_element(i));
			this->ClientTownTree->push(this->Clients->get_element(i)->getTown(), this->Clients->get_element(i));
			this->ClientDateTree->push(this->Clients->get_element(i)->getDate(), this->Clients->get_element(i));
			this->ClientHT->Delete(this->Clients->get_element(i));
			this->Clients->delete_element(data);
		}
	}
	this->clientsCount--;
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
	return this->Orders->get_data_by_id(i);
}

Client* Logic::getClient(int i) {
	return this->Clients->get_element(i);
}

Subscribe* Logic::getSubscribe(int i) {
	return this->Subscribes->get_element(i);
}

CycleList<Order>* Logic::getOrderList() {
	return this->Orders;
}
OnePointList<Subscribe>* Logic::getSubscribesList() {
	return this->Subscribes;
}
TwoPointList<Client>* Logic::getClientList() {
	return this->Clients;
}
