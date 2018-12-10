#include <string>
#include <iostream>
#include "COMMON.h"
using namespace std;

CommonPrice::CommonPrice()
{
	n = 8;
	tsize = 0;
	mas = new Price[n];
}

CommonPrice::~CommonPrice() {
	delete[]mas;
}

CommonPrice::CommonPrice(const CommonPrice &obj)
{
	mas = new Price[obj.tsize];
	for (int i = 0; i < tsize; i++)
		mas[i] = obj.mas[i];

	tsize = obj.tsize;
	
}

CommonPrice & CommonPrice::operator -=(int wnumber)//void pop(int wnumber) <<
{
	int k = 0;

	if ((wnumber <= 0) || (wnumber > tsize)) {
		throw 123;
	}


	Price *tmp = new Price[tsize - 1];
	for (int i = 0; i < tsize; i++) {
		if (wnumber != mas[i].getNumber()) {
			tmp[k] = mas[i];
			k++;
		}
	}
	delete[] mas;
	mas = tmp;
	tsize--;

}

ostream & operator << (ostream & os, const CommonPrice & com)
{
	if (com.tsize == 0) {
		cout << "spisok is empty" << endl;
	}
	else {
		for (int i = 0; i < com.tsize; i++)
			cout << com.mas[i].getNumber() << " " << com.mas[i].getStore() << " " << com.mas[i].getProduct() << " " << com.mas[i].getCost() << endl;
	}
	return os;
}


void CommonPrice::sort() {//сортировка пузырьком по алфавиту
	int counter = 1;
	for (int i = 0; i < tsize; i++)
		for (int j = tsize - 1; j > i; j--) {
			if (mas[j - 1].getStore() > mas[j].getStore()) {
				Price tmp = mas[j - 1];
				mas[j - 1] = mas[j];
				mas[j] = tmp;
			}
		}
	for (int i = 0; i < tsize; i++)
	{
		mas[i].setNumber(counter);
		counter++;
	}
}

void CommonPrice::prodofstore(string storefp) {
	int count = 0;
	for (int i = 0; i < tsize; i++)
		if (mas[i].getStore() == storefp)
		{
			cout << mas[i].getProduct() << " " << mas[i].getCost() << endl;
			count++;
		}
	if (count == 0)
	{
		cout << "wrong store" << endl;
	}
}