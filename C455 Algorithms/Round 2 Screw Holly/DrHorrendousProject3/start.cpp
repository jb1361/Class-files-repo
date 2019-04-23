#include <iostream>
#include <vector>
#include <queue>
#include <stack>


using namespace std;

struct Vertex
{
	bool visited = false;
	int parent = 0;
	vector<int> neighbors = vector<int>();
	int cost = 0;
	int key = 0;
};

int main(int argc, char *argv[]) {
	auto list = new vector<Vertex*>();

	int vertex = 0;
	cin >> vertex;
	while (vertex != -1)
	{
		auto sublist = new Vertex();
		sublist->key = vertex;
		list->push_back(sublist);
		cin >> vertex;
		while (vertex != -1)
		{
			sublist->neighbors.push_back(vertex);
			cin >> vertex;
		}
		cin >> vertex;
	}

	auto q = new queue<Vertex*>();
	q->push(list->front());
	while (!q->empty()) {
		auto v = q->front();
		q->pop();
		vector<int>::iterator i;
		for (i = v->neighbors.begin(); i != v->neighbors.end(); i++)
		{
			Vertex* w = (*list)[*i - 1];
			if (!w->visited) {
				w->cost = v->cost + 1;
				w->visited = true;
				w->parent = v->key;
				q->push(w);
			}			
		}		
	}

	stack<int> s = stack<int>();
	Vertex* v = list->back();
	cout << "Cost of shortest path: " << v->cost << endl;
	while (v != NULL) {
		s.push(v->key);
		if (v->parent != 0) {
			v = (*list)[v->parent - 1];
		}
		else v = NULL;
	}
	cout << "Path: {";
	while (!s.empty()) {
		cout << s.top();
		s.pop();
		if (!s.empty()) {
			cout << ", ";
		}
	}
	cout << "}";
	return 0;
}
