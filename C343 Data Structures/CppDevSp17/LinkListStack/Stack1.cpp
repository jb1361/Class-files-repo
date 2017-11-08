#include <iostream>
using namespace std;

class Stack1
{
	
private:
	int length = 0;
	class NodeRecord {
	public:
		int value;
		NodeRecord* next;
	};
	NodeRecord* top = new NodeRecord;
public:
	Stack1() {
		cout << "test" << endl;
		top->next = NULL;
	}
public:
	void push(int x) {
		if (top != NULL) {
			//NodeRecord* top = new NodeRecord;
			//top->value = x;
		//	top->next = top;
			length++;
		}
		else {
			top->value = x;
			length++;
		}
	}

	void printTop() {
		cout << top->value << endl;
	}

	void printStack() {
		NodeRecord* p = new NodeRecord;
		p = top;
		while (p != NULL) {
			cout << p->value << endl;
			p = p->next;
		}	
	}
	void Length() {
		cout << length << endl;
	}

};

