#pragma once
#include <string>

class Date
{
private:
	int day;
	int month;
	unsigned short int year;
public:
	Date(int day = 1, int month = 1, unsigned short int year = 1970)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	int getDay() { return this->day; }
	int getMonth() { return this->month; }
	unsigned short int getYear() { return this->year; }
	std::string toString() {
		return std::to_string(this->day) + "." + std::to_string(this->month) + "." + std::to_string(this->year);
	}
	bool operator==(const Date& p) {
		return (this->day == p.day && this->month == p.month && this->year == p.year);
	}
	bool operator!=(const Date& p) {
		return !(*this == p);
	}
	bool operator<(const Date& p) {
		if (this->year < p.year)return true;
		else if ((this->year == p.year) && (this->month < p.month))return true;
		else if ((this->year == p.year) && (this->month == p.month) && (this->day < p.day))return true;
		else return false;
	}
	bool operator>(const Date& p) {
		return (*this != p) && !(*this < p);
	}
	bool operator<=(const Date& p) {
		return (*this < p) || (* this == p);
	}
	bool operator>=(const Date& p) {
		return (*this > p) || (*this == p);
	}
};

class Client
{
private:
	std::string login;
	Date date;
	std::string country;
	std::string town;
public:
	Client(std::string login = "", Date date = Date(), std::string country = "", std::string town = "")
	{
		this->login = login;
		this->date = date;
		this->country = country;
		this->town = town;
	}
	std::string getLogin() { return this->login; }
	Date getDate() { return this->date; }
	std::string getCountry() { return this->country; }
	std::string getTown() { return this->town; }
	bool operator==(const Client& p) {
		return (this->login == p.login && this->date == p.date && this->country == p.country && this->town == p.town);
	}
	bool operator!=(const Client& p) {
		return !(*this == p);
	}
	bool operator<(const Client& p) {
		if (this->date < p.date)return true;
		else if ((this->date == p.date) && (this->login < p.login))return true;
		else if ((this->date == p.date) && (this->login == p.login) && (this->country < p.country))return true;
		else if ((this->date == p.date) && (this->login == p.login) && (this->country == p.country) && (this->town < p.town))return true;
		else return false;
	}
	bool operator>(const Client& p) {
		return (*this != p) && !(*this < p);
	}
	bool operator<=(const Client& p) {
		return (*this < p) || (*this == p);
	}
	bool operator>=(const Client& p) {
		return (*this > p) || (*this == p);
	}
};

class Subscribe
{
private:
	std::string name;
	std::string company;
	unsigned short int cost;
	unsigned short int minimalDuration;
public:
	Subscribe(std::string name ="", std::string company = "", unsigned short int cost = 0, unsigned short int minimalDuration = 0)
	{
		this->name = name;
		this->company = company;
		this->cost = cost;
		this->minimalDuration = minimalDuration;
	}
	std::string getName() { return this->name; }
	std::string getCompany() { return this->company; }
	unsigned short int getCost() { return this->cost; }
	unsigned short int getMinimalDuration() { return this->minimalDuration; }
	bool operator==(const Subscribe& p) {
		return (this->name == p.name && this->company == p.company && this->cost == p.cost && this->minimalDuration == p.minimalDuration);
	}
	bool operator!=(const Subscribe& p) {
		return !(*this == p);
	}
	bool operator<(const Subscribe& p) {
		if (this->cost < p.cost)return true;
		else if ((this->cost == p.cost) && (this->minimalDuration < p.minimalDuration))return true;
		else if ((this->cost == p.cost) && (this->minimalDuration == p.minimalDuration) && (this->name < p.name))return true;
		else if ((this->cost == p.cost) && (this->minimalDuration == p.minimalDuration) && (this->name == p.name) && (this->company < p.company))return true;
		else return false;
	}
	bool operator>(const Subscribe& p) {
		return (*this != p) && !(*this < p);
	}
	bool operator<=(const Subscribe& p) {
		return (*this < p) || (*this == p);
	}
	bool operator>=(const Subscribe& p) {
		return (*this > p) || (*this == p);
	}
};

class Order
{
private:
	std::string login;
	std::string name;
	std::string company;
	Date startDate;
public:
	Order(std::string login = "", std::string name = "", std::string company = "", Date startDate = Date())
	{
		this->login = login;
		this->name = name;
		this->company = company;
		this->startDate = startDate;
	}
	std::string getLogin() { return this->login; }
	std::string getName() { return this->name; }
	std::string getCompany() { return this->company; }
	Date getStartDate() { return this->startDate; }
	bool operator==(const Order& p) {
		return (this->login == p.login && this->name == p.name && this->company == p.company && this->startDate == p.startDate);
	}
	bool operator!=(const Order& p) {
		return !(*this == p);
	}
	bool operator<(const Order& p) {
		if (this->startDate < p.startDate)return true;
		else if ((this->startDate == p.startDate) && (this->login < p.login))return true;
		else if ((this->startDate == p.startDate) && (this->login == p.login) && (this->name < p.name))return true;
		else if ((this->startDate == p.startDate) && (this->login == p.login) && (this->name == p.name) && (this->company < p.company))return true;
		else return false;
	}
	bool operator>(const Order& p) {
		return (*this != p) && !(*this < p);
	}
	bool operator<=(const Order& p) {
		return (*this < p) || (*this == p);
	}
	bool operator>=(const Order& p) {
		return (*this > p) || (*this == p);
	}
};

