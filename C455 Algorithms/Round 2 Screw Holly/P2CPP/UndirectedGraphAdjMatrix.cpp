#include <Wrapper.h>
#include <Sequence/Sequence1.hpp>

class UndirectedGraphAdjMatrix {
private:
	class Edge {
	public:
		Integer* v1 = new Integer();
		Integer* v2 = new Integer();
	
		Edge() { 
			v1 = new Integer();
			v2 = new Integer();
		}

		Edge(Integer* V1, Integer* V2) {						
			v1->transferFrom(*V1);
			v2->transferFrom(*V2);
		}
		//Edge operator = (Edge& rhs)
		//{
		//	v1->transferFrom(*rhs.v1);
		//	v2->transferFrom(*rhs.v2);		
		//	return self;
		//}	// operator =
		void transferFrom(Edge& source)
		{
			v1->transferFrom(*source.v1);
			v2->transferFrom(*source.v2);
		} // transferFrom

		void clear()			       
		{
			v1 = new Integer();
			v2 = new Integer();
		}

		void ToString()
		{
			wcout << "(" << *v1 << "," << *v2 << ")";			
		} 
	};

	Sequence1<Edge>* edges;
	Sequence1<Integer>* vertices;
public:
	UndirectedGraphAdjMatrix()
	{
		vertices = new Sequence1<Integer>();
		edges = new Sequence1<Edge>();
	}

	void clear() {
		vertices = new Sequence1<Integer>();
		edges->clear();
	}

	void SetVertices(Sequence1<Integer>* nv) {	
		vertices = new Sequence1<Integer>();
		vertices->transferFrom(*nv);			
	} 

	void AddEdge(Integer* v1, Integer* v2) {
		Edge* newEdge = new Edge(v1,v2);	
		edges->add(edges->length(), *newEdge);
	}

	Integer NumberOfVertices() {
		return vertices->length();
	}

	Integer NumberOfEdges() {
		return edges->length();
	}

	/*Integer Degree(Text v) {
		Integer deg = 0;
		Integer index = 0;
		while (index <= edges->length - 1)
		{
			Edge* edge = *edges->entry(index);
			if (edge->v1 == v || edge.Getv1 == v) deg++;
			index++;
		}
		return deg;
	}*/

	//Boolean IsEdge(Text v1, Text v2) {
	//	Integer index = 0;		
	//	while (index <= edges->length - 1)
	//	{
	//		Edge edge = edges->entry(index);
	//		if (edge.Getv1 == v1 && edge.Getv2 == v2) return true;
	//		else if (edge.Getv1 == v2 && edge.Getv2 == v1) return true;
	//		index++;
	//	}
	//	return false;
	//}

	void ToString()
	{	
		wcout << L"(" << *vertices << L",{";
		Integer index = 0;
		while (index <= edges->length() - 1)
		{
			Edge* g = &(edges->entry(index));
			g->ToString();
			//wcout << edges->entry(index).ToString() << L"\n";
			index++;
		}		
		wcout << L"})\n";

		/*Integer* out = new Integer();
		out->add(out->size(), '({');*/
		//Integer* vertText = new Integer();
		//Integer* edgeText = new Integer();
		//Integer index = 0;	
		//while (index <= vertices->length() - 1)
		//{	
		//	if (vertText->size() != 0) {
		//		vertText->add(vertText->size(), ',');
		//	}
		//	vertText->add(vertText->size(), *vertices->entry(index));
		//	index++;
		//}
		//
		//while (index <= edges->length() - 1)
		//{
		//	Integer* v1 = new Integer();
		//	Integer* v2 = new Integer();
		//	v1 = edges->entry(index).v1;
		//	v2 = edges->entry(index).v2;
		//	if (edgeText->size() != 0) {
		//		edgeText->add(edgeText->size(),',');
		//	}
		//	//Dr. Hollys wrappers do not have any elegant join methods
		//	edgeText->add(edgeText->size(), '(');
		//	edgeText->append(*v1);
		//	edgeText->add(edgeText->size(), ',');
		//	edgeText->append(*v2);
		//	edgeText->add(edgeText->size(), '(');
		//	index++;
		//}		
		//out->append(*vertText);
		//Integer* test = new Integer();
		//
		//out->add(out->size(), '},');
		//out->add(out->size(), '{');
		////out->append(*edgeText);
		//out->add(out->size(), '})');
		//
		//return out;
	}

};