#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "TEXT.h"

using namespace std;


int main() {
	ifstream file("text.txt");


	char ch;
	int counter;
	string sentense;

	Text txt;
	while (file.get(ch))
	{
		sentense = sentense + ch;

		if (ch == '.') {
			txt.push(sentense);
			sentense = "";
		}
	}
	
	cout << "Input file:" << endl;
	txt.show();
	cout << "Result:" << endl;
	txt.sort();

	file.close();
	_getch();
}
