// Activity1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

const int max = 10;
const int strmax = 30;


class sqMatrix {

	public:
		sqMatrix(){}
		bool allPositive() const;
		void whereNotPositive(ostream) const;
	private:
		int size;
		int sq[max][max];


};




