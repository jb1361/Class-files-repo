#include <wrapper.h>
#include <Sequence/Sequence1.hpp>
#include <UndirectedGraphAdjMatrix.cpp>
#include <UndirectedGraphAdjList.cpp>
#include <DFS.cpp>
#include <vector>
#include <sstream>

using namespace std;


Sequence1<Sequence1<Integer>>* edges;

int main(int argc, char *argv[]) {
	
	edges = new Sequence1<Sequence1<Integer>>();

	string input;
	getline(cin, input);
	int lettersCount = stoi(input);
	Text* vertices = new Text[lettersCount];

	

	for (int i = 0; i < lettersCount; i++)
	{
		getline(cin, input);
		wstring widestr = wstring(input.begin(), input.end());		
		vertices[i] = Text(widestr.c_str());
		
	}	
	UndirectedGraphAdjMatrix* g1 = new UndirectedGraphAdjMatrix(lettersCount);
	UndirectedGraphAdjList* g2 = new UndirectedGraphAdjList(lettersCount);

	string v1;
	string v2;
	getline(cin, v1);
	getline(cin, v2);
	while (v1 != "")
	{
		Sequence1<Integer>* newEdge = new Sequence1<Integer>();
		Integer v = Integer(stoi(v1));
		Integer vv = Integer(stoi(v2));
		newEdge->add(Integer(0), v);
		newEdge->add(Integer(1), vv);
	
		
		edges->add(edges->length(), *newEdge);
		v1 = "";
		v2 = "";
		getline(cin, v1);
		getline(cin, v2);
		
	}	
	for (Integer i = 0; i < edges->length(); i++)
	{				
		g1->addEdge(edges->entry(i).entry(0), edges->entry(i).entry(1));
		g2->addEdge(edges->entry(i).entry(0), edges->entry(i).entry(1));
	}
	

	DFS* dfs;
	
	if (argc == 1)
	{
		DFS* dfs = new DFS(lettersCount, g1->adj, vertices);				
		for (int i = 0; i < lettersCount; i++)
		{
			dfs->DFSStartMatrix(i, 0);
		}			
	}
	else if (argc == 2)
	{			
		DFS* dfs = new DFS(lettersCount, g2->adj, vertices);			
		dfs->DFSStart(Integer(stoi(argv[1])), 0);
	}

	return 0;
}
