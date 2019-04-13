#include <wrapper.h>
#include <Sequence/Sequence1.hpp>
#include <UndirectedGraphAdjMatrix.cpp>
#include <iostream>
int main(int argc, char *argv[]) {
	
	UndirectedGraphAdjMatrix* g = new UndirectedGraphAdjMatrix();

	/*struct Vertex
	{
		Integer letterId;
		Sequence1<Integer>* list;
	};

	Sequence1<Vertex>* list = new Sequence1<Vertex>();*/

	
	int letters = 0;
	cin >> letters;
	Sequence1<Text>* lettersList = new Sequence1<Text>();
	Sequence1<Integer>* v = new Sequence1<Integer>();
	Text* input = new Text();
	Integer* v1 = new Integer();
	Integer* v2 = new Integer();
	int count = 0;
	cin >> *input;
	// Couldn't be bothered to figure out why cin was still reading after eof
	while (count < 49) {
		if (count < letters) {
			cin >> *input;
			wcout << *input;
			lettersList->add(lettersList->length(), *input);
			Integer* i = new Integer(count);
			v->add(v->length(), *i);
			input = new Text();
		}
		else {
			cin >> *v1;
			cin >> *v2;
			g->AddEdge(v1, v2);
			v1 = new Integer();
			v2 = new Integer();
		}
		count++;
	}
	g->SetVertices(v);
	wcout << *lettersList << L"\n";
	g->ToString();
	system("pause");
	return 0;
}
