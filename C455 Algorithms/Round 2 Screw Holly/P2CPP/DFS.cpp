// C++ program to print DFS traversal from
// a given vertex in a given graph
#include <Sequence/Sequence1.hpp>
#include <Wrapper.h>

class DFS
{
public:
	Integer V;
	Sequence1<Integer>* adj;	
	Text* letters;

	DFS(Integer V, Sequence1<Integer>* adj, Text* letters) {
		this->V = V;
		this->letters = letters;
		this->adj = new Sequence1<Integer>[V];
		this->adj = adj;
		// Print out the matrix
		/*for (Integer i = 0; i < V; i++)
		{
			for (Integer j = 0; j < V; j++)
			{
				wcout << adj[i].entry(j) << " ";
			}
			wcout << "\n";
		}*/
	}
	
	void DFSVisit(Integer v, Integer d, Text* wordSoFar)
	{	
		wordSoFar->append(this->letters[(int)v]);
		d++;
		if (d >= 6) {			
			wcout << *wordSoFar << L"\n";
			return;
		}

		for (int i = 0; i < adj[v].length(); i++) {
			Text* tempText = new Text();
			tempText->append(*wordSoFar);
			DFSVisit(adj[v].entry(i), d, tempText);			
			delete tempText;
		}
	}
	void DFSVisitMatrix(Integer v, Integer d, Text* wordSoFar)
	{	
		wordSoFar->append(this->letters[(int)v]);
		d++;
		if (d >= 6) {
			wcout << *wordSoFar << L"\n";
			return;
		}

		for (int i = 0; i < adj[v].length(); i++) {
			Text* tempText = new Text();
			tempText->append(*wordSoFar);
			if (adj[v].entry(i) == 1) {
				DFSVisitMatrix(i, d, tempText);
			}			
			delete tempText;
		}
	}
	// DFS traversal of the vertices reachable from v.
	// It uses recursive DFSUtil()
	void DFSStart(Integer v, Integer d)
	{
		// Call the recursive helper function
		// to prInteger DFS traversal
		Text* output = new Text();
		DFSVisit( v, 0, output);		
		delete output;
	}
	void DFSStartMatrix(Integer v, Integer d)
	{		
		Text* output = new Text();
		DFSVisitMatrix(v, 0, output);
		delete output;
	}
};