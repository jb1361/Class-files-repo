#pragma once
#include "Stack1.h"
#include <iostream>
using namespace std;
int main() {
	Stack1 stack;
	stack.push(5);
	stack.push(10);
	stack.push(50);
	cout << "peek: " << stack.peek() << endl;
	stack.replaceTop(3);
	cout << "peek after replaceTop: " << stack.peek() << endl;
	cout << "Stack Length: " << stack.length() << endl;
	cout << "Stack before pop: " << endl;
	stack.printStack();
	cout << "pop value: " << stack.pop() << endl;
	cout << "Stack after pop: " << endl;
	stack.printStack();
	return 0;

}