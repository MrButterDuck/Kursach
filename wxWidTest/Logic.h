#pragma once
#include "Structs.h"
#include "DataTypes.h"
class Logic
{
private:
	CycleList<Order> *Orders;
	AvlTree1<std::string, Order*>* OrderLoginTree;
	AvlTree1<std::string, Order*>* OrderNameTree;
	AvlTree1<std::string, Order*>* OrderCompanyTree;
	AvlTree1<Date, Order*>* OrderDateTree;
	HashTable1 *OrderHT;

	OnePointList<Subscribe> *Subscribes;
	AvlTree2<std::string, Subscribe*> *SubscribeNameTree;
	AvlTree2<std::string, Subscribe*> *SubscribeCompanyTree;
	AvlTree2<unsigned int, Subscribe*> *SubscribeCostTree;
	AvlTree2<unsigned int, Subscribe*> *SubscribeMinDurTree;
	HashTable3* SubscribeHT;
	// À»≈Õ“€
	TwoPointList<Client> *Clients;
	AvlTree3<std::string, Client*>* ClientCountryTree;
	AvlTree3<std::string, Client*>* ClientTownTree;
	AvlTree3<Date, Client*>* ClientDateTree;
	HashTable2 *ClientHT;

	unsigned int ordersCount, subscribesCount, clientsCount;
public:
	Logic();
	void AddData(Order& data);
	void AddData(Subscribe& data);
	void AddData(Client& data);
	void DeleteData(Order& data);
	void DeleteData(Subscribe& data);
	void DeleteData(Client& data);
	unsigned int getClientCount();
	unsigned int getSubscribesCount();
	unsigned int getOrderCount();
	Order* getOrder(int i);
	Subscribe* getSubscribe(int i);
	Client* getClient(int i);
	CycleList<Order>* getOrderList();
	OnePointList<Subscribe>* getSubscribesList();
	TwoPointList<Client>* getClientList();
	~Logic();
};



