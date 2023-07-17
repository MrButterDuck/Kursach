#pragma once
#include "Structs.h"
#include "DataTypes.h"
#include <fstream>
#include <sstream>
#include <vector>
class Logic
{
private:
	std::vector<Order> Orders;
	AvlTree1< int>* OrderLoginTree;
	AvlTree1< int>* OrderNameTree;
	AvlTree1<int>* OrderCompanyTree;
	AvlTree1< int>* OrderDateTree;
	HashTable1 *OrderHT;

	std::vector <Subscribe> Subscribes;
	AvlTree2<int> *SubscribeNameTree;
	AvlTree2< int> *SubscribeCompanyTree;
	AvlTree2<int> *SubscribeCostTree;
	AvlTree2<int> *SubscribeMinDurTree;
	HashTable3* SubscribeHT;
	// À»≈Õ“€
	std::vector <Client> Clients;
	AvlTree3<int>* ClientCountryTree;
	AvlTree3< int>* ClientTownTree;
	AvlTree3< int>* ClientDateTree;
	HashTable2 *ClientHT;

	unsigned int ordersCount, subscribesCount, clientsCount;
public:
	Logic();
	void AddData(Order& data);
	void AddData(Subscribe& data);
	void AddData(Client& data);
	void DeleteOrderData(int id);
	void DeleteSubscribeData(int id);
	void DeleteClientData(int id);
	std::string PrintOrderStruct(int type);
	std::string PrintSubscribeStruct(int type);
	std::string PrintClientStruct(int type);
	unsigned int getClientCount();
	unsigned int getSubscribesCount();
	unsigned int getOrderCount();
	Order* getOrder(int i);
	Subscribe* getSubscribe(int i);
	Client* getClient(int i);
	std::vector<Order>* getOrderList();
	std::vector<Subscribe>* getSubscribesList();
	std::vector<Client>* getClientList();
	void readFromFile(std::string path);
	void writeToFile(std::string path);
	void Clear(int type);
	CycleList<int>* searchData(std::string* login, std::string* Name, std::string* Company, Date startDate);
	OnePointList<int>* searchData(std::string* Name, std::string* Company, std::string* cost, std::string* dur);
	TwoPointList<int>* searchData(Date date, std::string* Country, std::string* Town);
	int searchHT(Order data);
	int searchHT(Subscribe data);
	int searchHT(Client data);
	~Logic();
};



