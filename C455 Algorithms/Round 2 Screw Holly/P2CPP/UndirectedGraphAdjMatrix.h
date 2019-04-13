#pragma once
#include <Sequence/Sequence1.hpp>
#include <Wrapper.h>
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
		T Getv1();
		T Getv2();		
		void ToString();
	};
	Sequence1<T> vertices;
	Sequence1<Edge<T>> edges;

public:
	UndirectedGraphAdjMatrix();
	~UndirectedGraphAdjMatrix();

	void clear();
	void SetVertices(Sequence1<T> nv);
	void AddEdge(T v1, T v2);
	void RemoveEdge(T v1, T v2);
	T RemoveAnyIncidentEdge(T v1);
	Edge<T> RemoveAnyEdge();
	Integer NumberOfVertices();
	Integer NumberOfEdges();
	Integer Degree(T v);
	Boolean IsEdge(T v1, T v2);
	Text ToString();
};