#include <Wrapper.h>
#include <Sequence/Sequence1.hpp>

class UndirectedGraphAdjMatrix {


public:

	Sequence1<Integer>* vertices;

	UndirectedGraphAdjMatrix()
	{
		vertices = new Sequence1<Integer>();
		
	}
	
	/*void addEdge(Integer* v1, Integer* v2) {
		Edge* newEdge = new Edge(v1,v2);	
		edges->add(edges->length(), *newEdge);
	}

	void ToString()
	{	
		wcout << L"(" << *vertices << L",{";
		Integer index = 0;
		while (index <= edges->length() - 1)
		{
			Edge* g = &(edges->entry(index));
			g->ToString();
			index++;
		}		
		wcout << L"})\n";
	}*/

};