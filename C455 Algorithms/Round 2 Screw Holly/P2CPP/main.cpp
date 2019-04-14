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

	//UndirectedGraphAdjMatrix* g1 = new UndirectedGraphAdjMatrix();
	
	//Sequence1<Integer>* adj = new Sequence1<Integer>();
	edges = new Sequence1<Sequence1<Integer>>();

	string input;
	getline(cin, input);
	int lettersCount = stoi(input);
	Text* vertices = new Text[lettersCount];

	

	for (int i = 0; i < lettersCount; i++)
	{
		getline(cin, input);
		//cout << "Input: " << input << "\n";
		wstring widestr = wstring(input.begin(), input.end());
		//cout << "Wstring: " << *widestr.c_str() << "\n";
		//cout << "i: " << i << "\n";
		vertices[i] = Text(widestr.c_str());
		
	}	
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
		//wcout << "v1: " << edges->entry(i).entry(0) << L", ";
		//wcout << "v2: " << edges->entry(i).entry(1) << L"\n";
		g2->addEdge(edges->entry(i).entry(0), edges->entry(i).entry(1));
	}
	//wcout << "Letters: " << *vertices << L"\n";
	//wcout << "Letters Count: " << lettersCount << L"\n";
	//wcout << "Edges: " << *edges << L"\n";
	//wcout << g2->adj[1] << L"\n";

	DFS* dfs = new DFS(lettersCount, g2->adj, vertices);	

	if (argc == 1)
	{
		for (int i = 0; i < lettersCount; i++)
		{
			dfs->DFSStart(i, 0);
		}		
	}
	else if (argc == 2)
	{
		dfs->DFSStart(Integer(stoi(argv[0])), 0);	
	}


	
	//g1->SetVertices(v);	
	//g1->ToString();
	//system("pause");
	return 0;
}
