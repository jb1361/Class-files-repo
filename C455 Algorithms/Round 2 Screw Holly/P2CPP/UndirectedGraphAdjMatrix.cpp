#include <Wrapper.h>
#include <Sequence/Sequence1.hpp>
#include <StaticArray/StaticArray1.hpp>
template <class T>
class UndirectedGraphAdjMatrix {
private:
	template <class T>
	class Edge {
	private:
		T v1;
		T v2;
	
	public:
		Edge() {
			v1 = 0;
			v2 = 0;
		}

		Edge(T v1, T v2) {
			this.v1 = v1;
			this.v2 = v2;
		}

		void clear()			       
		{
			v1 = 0;
			v2 = 0;
		}

		void ToString()
		{
			wcout << "{" << v1 << "," << v2 << "}";			
		} 
	};

	Sequence1<Edge<T>> edges;
	Sequence1<T> vertices;
public:
	UndirectedGraphAdjMatrix()
	{
		vertices = new List1<T>();
		edges = new List1<Edge<T>>();
	}
	~UndirectedGraphAdjMatrix()
	{
		vertices.~List1<T>;
		edges.~List1<T>;
	}

	void clear() {
		vertices = new List1<T>();
		edges.Clear();
	}

	void SetVertices(List1<T> nv) {
		vertices = new List1<T>();
		for (int i = 0; i < nv.Length; i++) vertices. nv[i];
	} 

	void AddEdge(T v1, T v2) {
		Edge<T> newEdge = new Edge<T>(v1, v2);
		edges.Add(newEdge);
	}

	void RemoveEdge(T v1, T v2) {
		int index = 0;
		while (index <= edges.Count - 1)
		{
			if (EqualityComparer<T>.Default.Equals(edges[index].v1, v1) && EqualityComparer<T>.Default.Equals(edges[index].v2, v2)) edges.RemoveAt(index);
			//if (edges[index].v1 == v1 && edges[index].v2 == v2) edges.RemoveAt(index);
			else index++;
		}
	}

	T RemoveAnyIncidentEdge(T v1) {
		int index = 0;
		while (index <= edges.Count - 1)
		{
			if (EqualityComparer<T>.Default.Equals(edges[index].v1, v1))
			{
				T r = edges[index].v2;
				edges.RemoveAt(index);
				return r;
			}
			else index++;
		}
		return (T)Convert.ChangeType(-1, typeof(T));
	}

	Edge<T> RemoveAnyEdge() {
		Edge<T> e = new Edge<T>(edges[0].v1, edges[0].v2);
		edges.RemoveAt(0);
		return e;
	}

	int NumberOfVertices() {
		return vertices.Length;
	}

	int NumberOfEdges() {
		return edges.Count;
	}

	int Degree(T v) {
		int deg = 0;
		foreach(var edge in edges)
		{

			if (EqualityComparer<T>.Default.Equals(edge.v2, v) || EqualityComparer<T>.Default.Equals(edge.v1, v)) deg++;
		}
		return deg;
	}

	bool IsEdge(T v1, T v2) {
		Edge<T> removeEdge = new Edge<T>(v1, v2);
		foreach(var edge in edges)
		{
			if (EqualityComparer<T>.Default.Equals(edge.v1, v1) && EqualityComparer<T>.Default.Equals(edge.v2, v2)) return true;
			else if (EqualityComparer<T>.Default.Equals(edge.v1, v2) && EqualityComparer<T>.Default.Equals(edge.v2, v1)) return true;
		}
		return false;
	}

	string ToString()
	{
		StringBuilder sb = new StringBuilder();
		String vert = string.Join(",", vertices);
		String edge = string.Join(",", edges);
		sb.Append("({" + vert + "},");
		sb.Append("{" + edge + "})");
		return sb.ToString();
	}

};