// BuffOverflow.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <string.h>

void test_attack() {

	char buff[40];
	//char t[80];
	char str[] = "\xEE\xFF\xCA\xCA\xDD\xE0\x29\xB1\x68\xAD\xDE\x4C\xEE\xCA\xCC\xEC\xE0\x29\x11\x31";
	//strcpy(buff, str);
	
	//for (int i = 0; i < 80; i++) {
	///	buff[i] = t[i];
//	}
	printf(buff);
	return;
}


int main()
{
	test_attack();
	return 0;
}


