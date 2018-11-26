#pragma once
#ifndef TEXT
#define TEXT
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

class Text {
public:
	int tsize, n, counter = 1;
	string *mas;
	Text()
	{
		cout << "\n //Constructor//\n";
		n = 1;
		tsize = 0;
		mas = new string[n];
	}

	~Text() {
		cout << "\n //Destructor//\n";
		delete[]mas;
	}


	void push(string p)
	{
		string *tmp = new string[tsize + 1];

		for (int i = 0; i < tsize; i++)
			tmp[i] = mas[i];
		tmp[tsize] = p;

		delete[] mas;
		mas = tmp;
		tsize++;

	}

	void show() {
		if (tsize == 0) {
			cout << "spisok is empty" << endl;
		}
		else {
			for (int i = 0; i < tsize; i++)
				cout << mas[i];
			cout << endl;
		}

	}
	void sort() {
		for (int i = 0; i < tsize; i++)
		{

			if (mas[i][1] == ' ')

				cout << mas[i] << ' ';

			if ((mas[i][0] == ' ') && (mas[i][2] == ' '))
				cout << mas[i] << ' ';

		}

		for (int i = 0; i < tsize; i++)
		{
			if ((mas[i][0] != ' ') && (mas[i][1] != ' '))
				cout << mas[i] << ' ';

			if (mas[i][0] == ' '&&mas[i][1] != ' '&&mas[i][2] != ' ')
				cout << mas[i] << ' ';

		}
	}
};

#endif
