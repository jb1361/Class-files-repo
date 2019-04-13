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
	Text* lettersList = new Text[lettersCount];

	UndirectedGraphAdjList* g2 = new UndirectedGraphAdjList(lettersCount, lettersList);

	for (int i = 0; i < lettersCount; i++)
	{
		getline(cin, input);
		wstring widestr = wstring(input.begin(), input.end());
		lettersList[i] = Text(widestr.c_str());
	}

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
		
		g2->addEdge(edges->entry(i).entry(0), edges->entry(i).entry(1));
	}
	wcout << "Letters: " << *lettersList << L"\n";
	wcout << "Letters Count: " << lettersCount << L"\n";
	wcout << "Edges: " << *edges << L"\n";
	wcout << *g2->adj << L"\n";

	DFS* dfs = new DFS();
	cout << "Starting DFS Search\n";
	for (int i = 0; i < lettersCount; i++)
	{
		//dfs->DFSStart(&(g2->adj), i, 0, &lettersList);
	}
	cout << "Test";

	if (argc == 1)
	{

		// run Operations #1 & #2
	}
	else if (argc == 2)
	{
		//  run Operations #3 & #4
	}


	//for (int i = 0; i < letters; i++)
	//{
		//dfs->DFSStart(i);
	//}
	//g1->SetVertices(v);	
	//g1->ToString();
	//system("pause");
	return 0;
}
