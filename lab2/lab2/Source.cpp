#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <vector>
using namespace std;

int main() {
	ifstream file("text.txt");
	vector <string> tx;


	char ch;
	int counter;
	string sentense;

	while (file.get(ch))
	{
		sentense = sentense + ch;

		if (ch == '.') {
			tx.push_back(sentense);
			sentense = "";
		}
	}
	for (int i = 0; i < tx.size(); i++)
	{
		if (tx[i][1] == ' ')

			cout << tx[i] << ' ' << endl;

		if ((tx[i][0] == ' ') && (tx[i][2] == ' '))
			cout << tx[i] << ' ' << endl;

	}

	for (int i = 0; i < tx.size(); i++)
	{
		if ((tx[i][0] != ' ') && (tx[i][1] != ' '))
			cout << tx[i] << ' ' << endl;

		if (tx[i][0] == ' '&&tx[i][1] != ' '&&tx[i][2] != ' ')
			cout << tx[i] << ' ' << endl;

	}



	file.close();
	_getch();
}
