#include <string>
#include <iostream>
#include "PRICE.h"
using namespace std;

void Price::setProduct(string p) {
	product = p;
}

string Price::getProduct() {
	return product;
}

void Price::setStore(string p) {
	store = p;
}

string Price::getStore() {
	return store;
}

void Price::setCost(int p) {
	cost = p;
}

int Price::getCost() {
	return cost;
}
void Price::setNumber(int p) {
	number = p;
}
int Price::getNumber() {
	return number;
}

Price::Price() {
	cost = 0;
}

istream & operator >>(istream &is, Price &q)
{
	string wstore, wproduct;
	int wcost;
	cin >> wstore >> wproduct >> wcost;
	q.setStore(wstore);
	q.setProduct(wproduct);
	q.setCost(wcost);
	return is;
}