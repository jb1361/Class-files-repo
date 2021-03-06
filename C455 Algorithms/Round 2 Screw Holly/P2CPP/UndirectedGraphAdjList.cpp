// C++ program to print DFS traversal from
// a given vertex in a given graph
#include <Sequence/Sequence1.hpp>
#include <Wrapper.h>

class UndirectedGraphAdjList
{
public:
	Integer V; // No. of vertices
	//Text* letters;
	// Pointer to an array containing
	// adjacency lists
	Sequence1<Integer> *adj;

	UndirectedGraphAdjList(Integer V/*, Text* letters*/)
	{
		this->V = V;		
		adj = new Sequence1<Integer>[V];
	}

	void addEdge(Integer v, Integer w)
	{
		adj[v].add(adj[v].length(), w);				
	}	
};