#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

// Товар
class Price {
private:
	string store;
	string product;
	int cost;
	int number;
public:
	//Price *next;
	void setProduct(string p) {
		product = p;
	}

	string getProduct() {
		return product;
	}

	void setStore(string p) {
		store = p;
	}

	string getStore() {
		return store;
	}

	Price() {
		cost = 0;
	}
	void setCost(int p) {
		cost = p;
	}

	int getCost() {
		return cost;
	}
	void setNumber(int p) {
		number = p;
	}
	int getNumber() {
		return number;
	}
};

// Прайс состоит из товаров
class CommonPrice {
public:
	int tsize, n, counter = 1;
	Price *mas;
	CommonPrice()
	{
		cout << "\n //Constructor//\n";
		n = 3;
		tsize = 0;
		mas = new Price[n];
	}

	~CommonPrice() {
		cout << "\n //Destructor//\n";
		delete[]mas;
	}

	CommonPrice(const CommonPrice &obj)
	{
		mas = new Price;
		for (int i = 0; i<tsize; i++)
			mas[i] = obj.mas[i];

		tsize = obj.tsize;
		cout << "\n//Copy constructor//\n";
	}



	void push(Price p)
	{
		Price *tmp = new Price[tsize + 1];

		for (int i = 0; i<tsize; i++)
			tmp[i] = mas[i];

		tmp[tsize] = p;
		tmp[tsize].setNumber(counter);
		delete[] mas;
		mas = tmp;
		tsize++;
		counter++;
		//return ;
	}

	CommonPrice & operator <<(int wnumber)//void pop(int wnumber)
	{
		int k = 0;

		if (wnumber <= 0) {
			throw 123;
			//cout << "error" << endl;
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


	void show() {
		if (tsize == 0) {
			cout << "spisok is empty" << endl;
		}
		else {
			for (int i = 0; i < tsize; i++)
				cout << mas[i].getNumber() << " " << mas[i].getStore() << " " << mas[i].getProduct() << " " << mas[i].getCost() << endl;
		}
	}
	void sort() {//сортировка пузырьком по алфавиту
		for (int i = 0; i < tsize; i++)
			for (int j = tsize - 1; j > i; j--) {
				if (mas[j - 1].getStore() > mas[j].getStore()) {
					Price tmp = mas[j - 1];
					mas[j - 1] = mas[j];
					mas[j] = tmp;
				}
			}
	}

	void prodofstore(string storefp) {
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

};


//void any(CommonPrice p)
//{
//
//	
//}

int main() {

	CommonPrice p;
	Price q;
	string wstore, wproduct, storefp;
	int wcost, wnumber;

	cout << "Write the name of store, product and cost :" << endl;
	for (int i = 0; i < 3; i++) {

		cin >> wstore >> wproduct >> wcost;
		q.setStore(wstore);
		q.setProduct(wproduct);
		q.setCost(wcost);
		//p >> q;
		p.push(q);

	}
	p.sort();
	p.show();

	/*any(p);*/
	int r;
	bool fl = true;
	while (fl) {
		cout << "0 - exit" << endl;
		cout << "1 - add objects" << endl;
		cout << "2 - delete object" << endl;
		cout << "3 - show objects" << endl;
		cout << "4 - show procucts of one store" << endl;

		cin >> r;
		switch (r) {
		case 0:
			fl = false;
			break;
		case 1:
			cout << "Write the name of store, product and cost :" << endl;

			cin >> wstore >> wproduct >> wcost;
			q.setStore(wstore);
			q.setProduct(wproduct);
			q.setCost(wcost);
			//p >> q;
			p.push(q);


			p.sort();	//+сортировка по алфавиту
			break;
		case 2:
			cout << "Write the number, which you want to delete :" << endl;
			cin >> wnumber;
			try
			{
				p << wnumber;
				//p.pop(wnumber);
			}
			catch (int e)
			{
				cout << e << " " << "Error" << endl;
			}
			catch (...)
			{
				cout << "Error" << endl;
			}
			break;
		case 3:
			p.sort();//сортировка по алфавиту + show
			p.show();
			cout << endl;
			break;
		case 4:
			cout << "write a store:" << endl;
			cin >> storefp;
			p.prodofstore(storefp);// вывод всех товаров магазина
			break;

			_getch();
		}
	}

}

