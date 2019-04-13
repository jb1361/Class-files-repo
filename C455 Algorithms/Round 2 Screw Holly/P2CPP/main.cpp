#include <wrapper.h>
#include <Sequence/Sequence1.hpp>
#include <UndirectedGraphAdjMatrix.cpp>

int main() {	
	UndirectedGraphAdjMatrix<Integer>* g1 = new UndirectedGraphAdjMatrix<Integer>();
	
	Sequence1<Integer>* v = new Sequence1<Integer>();
	Integer i = 0;
	v->append(i);
	wcout << v;

	//void LoadGraphs(UndirectedGraph<Integer> &g, UndirectedGraph<Text> &g2);
	//void LoadGraphs(UndirectedGraph* g, UndirectedGraph* g2)
	//{
		/*
		 *    G1 = (V, E)
		 *    V = {0, 1, 2, 3, 4, 5, 6, 7}
		 *    E = {(0, 1), (0, 4), (1, 5), (2, 3), (2, 5), (2, 6), (3, 6), (3, 7), (5, 5), (5, 6), (6, 7)}
		 */

		 //Sequence1<T>* v = new Sequence1<T>();		
		 //const char l = '0';
		 //Text t = new Text();
		 //t.append(l);
		 //v->add(i, t);
		 //v->add(i,j);
		 //wcout << t;

		 /*v->add(i,i);
		 v->add(i,i);
		 v->add(i,i);
		 v->add(i,i);
		 v->add(i,i);
		 v->add(i,i);
		 v->add(i,i);*/

		 //g.SetVertices(v);

		 //g.AddEdge(0, 1);
		 //g.AddEdge(0, 4);
		 //g.AddEdge(1, 5);
		 //g.AddEdge(2, 3);
		 //g.AddEdge(2, 5);
		 //g.AddEdge(2, 6);
		 //g.AddEdge(3, 6);
		 //g.AddEdge(3, 7);
		 //g.AddEdge(5, 5);
		 //g.AddEdge(5, 6);
		 //g.AddEdge(6, 7);
		 //
		 //// V = { A,C,D,E,E,I,L,N,O,O,P,R,T}
		 //// E = { (A, C),(A, D),(A, E),(A, I),(A, N),(C, D), ...}
		 //Sequence1<Text> *sv = new Sequence1<Text>();
		 //sv.append('A');
		 //sv.append('C');
		 //sv.append('D');
		 //sv.append('E');
		 //sv.append('E');
		 //sv.append('I');
		 //sv.append('L');
		 //sv.append('N');
		 //sv.append('O');
		 //sv.append('O');
		 //sv.append('P');
		 //sv.append('R');
		 //sv.append('T');

		 //g2.SetVertices(sv);

		 //g2.AddEdge("C", "D");
		 //g2.AddEdge("C", "I");
		 //g2.AddEdge("C", "A");
		 //g2.AddEdge("C", "E");
		 //g2.AddEdge("C", "O");

		 //g2.AddEdge("O", "C");
		 //g2.AddEdge("O", "E");
		 //g2.AddEdge("O", "D");
		 //g2.AddEdge("O", "R");
		 //g2.AddEdge("O", "L");

		 //g2.AddEdge("E", "A");
		 //g2.AddEdge("E", "C");
		 //g2.AddEdge("E", "O");
		 //g2.AddEdge("E", "R");
		 //g2.AddEdge("E", "D");

		 //g2.AddEdge("A", "C");
		 //g2.AddEdge("A", "D");
		 //g2.AddEdge("A", "E");
		 //g2.AddEdge("A", "I");
		 //g2.AddEdge("A", "N");

		 //g2.AddEdge("R", "O");
		 //g2.AddEdge("R", "L");
		 //g2.AddEdge("R", "E");
		 //g2.AddEdge("R", "D");
		 //g2.AddEdge("R", "E");

		 //g2.AddEdge("I", "C");
		 //g2.AddEdge("I", "A");
		 //g2.AddEdge("I", "D");
		 //g2.AddEdge("I", "N");
		 //g2.AddEdge("I", "T");

		 //g2.AddEdge("D", "A");
		 //g2.AddEdge("D", "C");
		 //g2.AddEdge("D", "E");
		 //g2.AddEdge("D", "O");
		 //g2.AddEdge("D", "R");
		 //g2.AddEdge("D", "L");
		 //g2.AddEdge("D", "E");
		 //g2.AddEdge("D", "P");
		 //g2.AddEdge("D", "O");
		 //g2.AddEdge("D", "T");
		 //g2.AddEdge("D", "N");
		 //g2.AddEdge("D", "I");

		 //g2.AddEdge("L", "O");
		 //g2.AddEdge("L", "R");
		 //g2.AddEdge("L", "D");
		 //g2.AddEdge("L", "E");
		 //g2.AddEdge("L", "P");

		 //g2.AddEdge("N", "I");
		 //g2.AddEdge("N", "A");
		 //g2.AddEdge("N", "D");
		 //g2.AddEdge("N", "O");
		 //g2.AddEdge("N", "T");

		 //g2.AddEdge("E", "D");
		 //g2.AddEdge("E", "R");
		 //g2.AddEdge("E", "L");
		 //g2.AddEdge("E", "P");
		 //g2.AddEdge("E", "O");

		 //g2.AddEdge("O", "T");
		 //g2.AddEdge("O", "N");
		 //g2.AddEdge("O", "D");
		 //g2.AddEdge("O", "E");
		 //g2.AddEdge("O", "P");

		 //g2.AddEdge("T", "I");
		 //g2.AddEdge("T", "N");
		 //g2.AddEdge("T", "D");
		 //g2.AddEdge("T", "O");
		 //g2.AddEdge("T", "P");

		 //g2.AddEdge("P", "T");
		 //g2.AddEdge("P", "O");
		 //g2.AddEdge("P", "D");
		 //g2.AddEdge("P", "E");
		 //g2.AddEdge("P", "L");
	 //}


	system("pause");
	return 0;
}
