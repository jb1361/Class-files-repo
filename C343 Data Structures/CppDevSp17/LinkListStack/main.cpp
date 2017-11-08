#include "main.h"

int main() {
	Stack1 stack;
	stack.push(1);
	stack.printTop();
	stack.Length();
	//l = 2;
	//stack.push(l);
	//stack.printStack();
	//l = 10;
	//stack.push(l);
	//stack.printStack();
	return 0;
	delete &stack;
}