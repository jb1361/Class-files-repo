#pragma once
class Stack1
{

private:
	class NodeRecord {
	public:
		int value;
		NodeRecord* next;
	};
	int len = 0;
public:
	Stack1();
	~Stack1();
	NodeRecord* top = new NodeRecord;
	void push(int x);
	int pop();
	int peek();
	void printStack();
	int length();
	void replaceTop(int x);
};
