#include "main.h"
#include <string>
#include <iostream>
using namespace std;

string random() {
	string s = "";
	int l = rand() % 10 + 1;
	for (int j = 0; j < l; j++)
	{
		int c = rand() % 26 + 65;
		char asciiChar = c;
		s = s + asciiChar;
	}

	return s;

}
int main()
{
	string* stringptr[10];
	string strings[10];

	for (int i = 0; i < 10; i++)
	{
		strings[i] = random();
		stringptr[i] = &strings[i];
	}

	cout << "Array addresses before sort:" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << stringptr[i] << endl;
	}
	cout << endl;
	cout << "Array values before sort:" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << strings[i] << endl;
	}
	cout << endl;


	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			string left = *stringptr[i];
			if (left.compare(*stringptr[j]) < 0) {
				string* s = stringptr[j];
				stringptr[j] = stringptr[i];
				stringptr[i] = s;
			}
		}
	}
	cout << endl;
	cout << "Array addresses after sort:" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << stringptr[i] << endl;
	}
	cout << endl;
	cout << "Array values after sort:" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << *stringptr[i] << endl;
	}
	cout << endl;

	return 0;
}

