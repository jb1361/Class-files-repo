// pointerTest.cpp : Defines the entry point for the console application.
//

//Just shows off operator overloading where in this case ofstream>>
//has no definition so it it being created rather than overloaded


#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream myfile;
	ofstream& operator>>(ofstream& os, int obj);
	istream& operator >> (std::istream& is, T& obj);
	myfile.open("example.txt");
	int x;
	myfile >> x;
	myfile.close();
		
}

