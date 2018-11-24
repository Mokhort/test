#pragma once
#ifndef PRICE
#define PRICE
#include <string>
#include <iostream>
using namespace std;

// Товар
class Price {
private:
	string store;
	string product;
	int cost;
	int number;
public:
	void setProduct(string p);
	string getProduct();

	void setStore(string p);
	string getStore();

	Price();

	void setCost(int p);
	int getCost();

	void setNumber(int p);
	int getNumber();

	friend istream& operator >> (istream &is, Price &q);
};
#endif
