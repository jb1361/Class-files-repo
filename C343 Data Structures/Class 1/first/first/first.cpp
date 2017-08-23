
#include "stdafx.h"
#include <IoStream>
#include <fstream>
using namespace std;


char infilename[13];

void main() {
	std::cout << "Enter file name:";
	cin >> infilename;
	ifstream infile(infilename, ios::in);
	if (infile.fail()) {
		cerr << "Input failed" << endl;
		exit(1);
	}
	int x;
	double y;
	char ch;
	while (infile >> x >> y >> ch) {
		cout << x << y << ch << endl;
	}

}