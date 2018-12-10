#pragma once
#ifndef COMMON
#define COMMON
#include "PRICE.h"
#include <string>
#include <iostream>
using namespace std;

// Прайс состоит из товаров
class CommonPrice {
public:
	int tsize, n, counter = 1;
	Price *mas;
	CommonPrice();

	~CommonPrice();

	CommonPrice(const CommonPrice &obj);


	friend CommonPrice operator += (CommonPrice &obj, const Price &p)
	{
		Price *tmp = new Price[obj.tsize + 1];

		for (int i = 0; i< obj.tsize; i++)
			tmp[i] = obj.mas[i];

		tmp[obj.tsize] = p;
		tmp[obj.tsize].setNumber(obj.counter);
		delete[] obj.mas;
		obj.mas = tmp;
		obj.tsize++;
		obj.counter++;
		return obj;
	}

	CommonPrice & operator -=(int wnumber);
	

	friend ostream & operator << (ostream & os, const CommonPrice & com);


	void sort();
	void prodofstore(string storefp);
};
#endif
