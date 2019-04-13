// C++ program to print DFS traversal from
// a given vertex in a given graph
#include <Sequence/Sequence1.hpp>
#include <Wrapper.h>

class DFS
{
public:

	void DFSVisit(Sequence1<Integer> adj[], Integer v, Integer d, Text* wordSoFar, Text* letters[])
	{

		wordSoFar->append(*letters[(int)v]);
		d++;
		if (d >= 6) {
			wcout << *wordSoFar << L"\n";
		}

		for (int i = 0; i < adj[v].length(); i++) {
			Text* tempText = new Text();
			tempText->append(*tempText);
			DFSVisit(adj, adj[v].entry(i), d, tempText, letters);
			delete tempText;
		}
	}
	// DFS traversal of the vertices reachable from v.
	// It uses recursive DFSUtil()
	void DFSStart(Sequence1<Integer>* adj[], Integer v, Integer d, Text* letters[])
	{
		// Call the recursive helper function
		// to prInteger DFS traversal
		Text* output = new Text();
		DFSVisit(*adj, v, 0, output, letters);
		delete output;
	}
};