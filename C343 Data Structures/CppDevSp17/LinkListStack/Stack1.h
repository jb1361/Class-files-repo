#pragma once
class Stack1
{

private:
	class NodeRecord {
	public:
		int value;
		NodeRecord* next;
	};
	int length = 0;
public:
	Stack1();
	~Stack1();
	
	NodeRecord* top = new NodeRecord;
	void push(int x);
	int pop();
	void printTop();
	void printStack();
	int Length();
};
