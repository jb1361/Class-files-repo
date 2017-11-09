#pragma once
#include <iostream>
#include "Stack1.h"
using namespace std;

Stack1::Stack1() {
	top = NULL;
	}
Stack1::~Stack1() {
	delete top;
}

void Stack1::push(int x) {
	NodeRecord* nextNode = new NodeRecord;
	nextNode->value = x;
	nextNode->next = NULL;
	if (top == NULL) top = nextNode;
	else {
		NodeRecord* p;
		p = top;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = nextNode;
	}
	len++;
	

}
int Stack1::pop() {
	int val = top->value;
	top = top->next;
	len--;
	return val;
}

int Stack1::peek() {
	return top->value;
}

void Stack1::replaceTop(int x) {
	top->value = x;
}
void Stack1::printStack() {
	NodeRecord* p = new NodeRecord;
	p = top;
	while (p != NULL) {
		cout << p->value << endl;
		p = p->next;
	}	
}
int Stack1::length() {
	return len;
}



