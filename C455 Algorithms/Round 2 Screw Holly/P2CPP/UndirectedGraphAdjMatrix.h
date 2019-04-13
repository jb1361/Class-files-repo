#pragma once
#include <Sequence/Sequence1.hpp>

template <class T>
class UndirectedGraphAdjMatrix {

private:
	template <class T>
	class Edge {
	private:
		T v1;
		T v2;
	public:
		Edge(void);
		Edge(T v1, T v2);
		void clear();
		void ToString();
	};
	Sequence1<T> vertices;
	Sequence1<Edge<T>> edges;

public:
	UndirectedGraphAdjMatrix();
	~UndirectedGraphAdjMatrix();

	void clear();
	void SetVertices(T[] nv);
	void AddEdge(T v1, T v2);
	void RemoveEdge(T v1, T v2);
	T RemoveAnyIncidentEdge(T v1);
	Edge<T> RemoveAnyEdge();
	int NumberOfVertices();
	int NumberOfEdges();
	int Degree(T v);
	bool IsEdge(T v1, T v2);
	string ToString();
};