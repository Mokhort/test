#include <iostream>
#include <conio.h>
#include <string>
#include "PRICE.h"
#include "COMMON.h"

using namespace std;


int main() {

	CommonPrice p;
	Price q;
	string wstore, wproduct, storefp;
	int wcost, wnumber;

	cout << "Write the name of store, product and cost :" << endl;
	for (int i = 0; i < 3; i++) {

		cin >> q;
		p += q;
		//p.push(q);

	}
	p.sort();
	cout << p;

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
			cin >> q;

			p+= q;
			//p.push(q);


			p.sort();	//+���������� �� ��������
			break;
		case 2:
			cout << "Write the number, which you want to delete :" << endl;
			cin >> wnumber;
			try
			{
				p -= wnumber;
			}
			catch (int e)
			{
				cout << e << " " << "Error! Wrong number" << endl;
			}
			catch (...)
			{
				cout << "Error" << endl;
			}
			break;
		case 3:
			p.sort();//���������� �� �������� + show
			cout << p;
			cout << endl;
			break;
		case 4:
			cout << "write a store:" << endl;
			cin >> storefp;
			p.prodofstore(storefp);// ����� ���� ������� ��������
			break;

			_getch();
		}
	}

}

