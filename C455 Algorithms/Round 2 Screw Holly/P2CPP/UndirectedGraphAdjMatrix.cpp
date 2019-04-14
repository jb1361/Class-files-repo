#include <Wrapper.h>
#include <Sequence/Sequence1.hpp>

class UndirectedGraphAdjMatrix {
public:
	Integer V; // No. of vertices
	//Text* letters;
	// Pointer to an array containing
	// adjacency lists
	Sequence1<Integer>* adj;

	UndirectedGraphAdjMatrix(Integer V/*, Text* letters*/)
	{
		this->V = V;

		this->adj = new Sequence1<Integer>[V];
		for (Integer i = 0; i < V; i++)
		{			
			for (Integer j = 0; j < V; j++)
			{				
				Integer zero = Integer(0);
				adj[i].add(adj[i].length(), zero);			
			}
		}	
	}

	void addEdge(Integer v, Integer w)
	{
		Integer one = Integer(1);	
		adj[v].entry(w) = one;		
	}

};