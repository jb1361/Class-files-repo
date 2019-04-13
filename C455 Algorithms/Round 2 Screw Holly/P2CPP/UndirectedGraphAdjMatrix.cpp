#include <Wrapper.h>
#include <Sequence/Sequence1.hpp>
template <class T>
class UndirectedGraphAdjMatrix {
private:
	template <class T>
	class Edge {
	private:
		Text v1;
		Text v2;
	
	public:
		Edge() {
			Text* v = new Text();
			v->add(Integer(0), '0');
			v1 = *v;
			v2 = *v;
		}

		Edge(T v1, T v2) {
			this.Getv1 = v1;
			this.Getv2 = v2;
		}

		void clear()			       
		{
			Text* v = new Text();
			v->add(Integer(0), '0');
			v1 = *v;
			v2 = *v;
		}
		template <class T>
		T Getv1() {
			return v1;
		}
		template <class T>
		T Getv2() {
			return v2;
		}
		void ToString()
		{
			wcout << "{" << v1 << "," << v2 << "}";			
		} 
	};

	Sequence1<T>* edges;
	Sequence1<T>* vertices;
public:
	UndirectedGraphAdjMatrix()
	{
		vertices = new Sequence1<T>();
		edges = new Sequence1<Edge<T>>();
	}
	~UndirectedGraphAdjMatrix()
	{
		vertices->~Sequence1<T>;
		edges->~Sequence1<T>;
	}

	void clear() {
		vertices = new Sequence1<T>();
		edges->Clear();
	}

	void SetVertices(Sequence1<T> &nv) {
		vertices = new Sequence1<T>();
		vertices->transferFrom(nv);
		//for (int i = 0; i < nv->length; i++) vertices->add(Integer(i), nv->entry(i));
	} 

	void AddEdge(T v1, T v2) {
		//Edge<T>* newEdge = new Edge<T>(v1, v2);
		T* t = new T();
		t[0] = v1;
		t[1] = v2;
		//newEdge->v1 = ToText(v1);
		edges->add(edges->length(), *t);
	}

	void RemoveEdge(T v1, T v2) {
		Integer index = 0;
		while (index <= edges->length - 1)
		{			
			if (edges->entry(index).Getv1 == v1 && edges->entry(index).Getv2 == v2) edges->remove(index);
			else index++;
		}
	}

	/*Edge<T> RemoveAnyEdge() {
		Edge<T> e = new Edge<T>(edges[0].Getv1, edges[0].Getv2);
		edges->remove(0);
		return e;
	}*/

	Integer NumberOfVertices() {
		return vertices->length;
	}

	Integer NumberOfEdges() {
		return edges->length;
	}

	Integer Degree(T v) {
		Integer deg = 0;
		Integer index = 0;
		while (index <= edges->length - 1)
		{
			Edge<T> edge = edges->entry(index);
			if (edge.Getv2 == v || edge.Getv1 == v) deg++;
			index++;
		}
		return deg;
	}

	Boolean IsEdge(T v1, T v2) {
		Integer index = 0;		
		while (index <= edges->length - 1)
		{
			Edge<T> edge = edges->entry(index);
			if (edge.Getv1 == v1 && edge.Getv2 == v2) return true;
			else if (edge.Getv1 == v2 && edge.Getv2 == v1) return true;
			index++;
		}
		return false;
	}

	Text ToString()
	{
		Text* out = new Text();
		out->add(out->size(), '({');
		Text* vertText = new Text();
		Text* edgeText = new Text();
		Integer index = 0;	
		while (index <= vertices->length() - 1)
		{	
			Edge<T>* vertice = new Edge<T>(edges->entry(index));
			//vertice = edges->entry(index);
			if (vertText->size() != 0) {
				vertText->add(vertText->size(), ',');
			}
			vertText.append(vertice);			
			index++;
		}
		while (index <= edges->length() - 1)
		{
			Edge<T>* edge = new Edge<T>(edges->entry(index));
			if (edgeText->size() != 0) {
				edgeText.append(',');
			}
			//Dr. Hollys wrappers do not have any elegant join methods
			edgeText.append('(');
			edgeText.append(edge.Getv1);
			edgeText.append(',');
			edgeText.append(edge.Getv2);
			edgeText.append('(');
			index++;
		}		
		out.append(vertText);
		out.append('},');
		out.append('{');
		out.append(edgeText);
		out.append('})');
		return *out;
	}

};