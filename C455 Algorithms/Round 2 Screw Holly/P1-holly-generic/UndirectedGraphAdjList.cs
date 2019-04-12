using System;
using System.Collections.Generic;
using System.Text;
namespace P1
{
    public class UndirectedGraphAdjList<T>
    {
        public class Edge<T>
        // Note:
        // This class is finished for you
        // No work required here
        {
            // Edge is finite set of integer
            //   exemplar e
            //   constraint |e| = 2
            public T v1 { get; set; }
            public T v2 { get; set; }

            private T Get(int vertice)
            {
                return (T)Convert.ChangeType(vertice, typeof(T));
            }
            private T Get(string vertice)
            {
                return (T)Convert.ChangeType(vertice, typeof(T));
            }
            public Edge()
            // updates self
            // ensures self = {0,0}
            {
                v1 = Get(0);
                v2 = Get(0);
            } // Edge

            public Edge(T v1, T v2)
            // updates self
            // ensures self = {v1,v2}
            {
                this.v1 = v1;
                this.v2 = v2;
            } // Edge
            public void clear()
            // clears self        
            {
                v1 = Get(0);
                v2 = Get(0);
            } // clear
            public override string ToString()
            {
                StringBuilder sb = new StringBuilder("{" + v1 + "," + v2 + "}");
                return sb.ToString();
            } // ToString
        } // Edge

        T[] vertices;
        List<Edge<T>> edges;

        public UndirectedGraphAdjList()
        // updates self
        // ensures self.vertices = {}  and  self.edges = { }
        {
            vertices = new T[0];
            edges = new List<Edge<T>>();
        } // UndirectedGraphAdjMatrix

        public void clear()
        // clears self
        {
            vertices = new T[0];
            edges.Clear();
        } // clear

        public void SetVertices(T[] nv)
        // updates self
        // requires self.vertices = {}  and nv > 0
        // ensures self.vertices = {v: integer where (0 <= v < nv) (v)} and
        //         self.edges = {}
        {
            vertices = new T[nv.Length];
            for (int i = 0; i < nv.Length; i++) vertices[i] = nv[i];
        } // SetVertices

        public void AddEdge(T v1, T v2)
        // updates self
        // requires v1 is in self.vertices  and
        //          v2 is in self.vertices and
        //          {v1, v2} is not in self.edges
        // ensures self.vertices = #self.vertices  and
        //         self.edges = #self.edges union {{v1, v2}}
        {
            Edge<T> newEdge = new Edge<T>(v1, v2);
            edges.Add(newEdge);
        } // AddEdge

        public void RemoveEdge(T v1, T v2)
        // updates self
        // preserves v1, v2
        // requires v1 is in self.vertices and
        //          v2 is in self.vertices and
        //          {v1, v2} is in self.edges
        // ensures self.vertices = #self.vertices  and
        //         self.edges = #self.edges - {{v1, v2}}
        {
            int index = 0;
            while (index <= edges.Count - 1)
            {
                if (EqualityComparer<T>.Default.Equals(edges[index].v1, v1) && EqualityComparer<T>.Default.Equals(edges[index].v2, v2)) edges.RemoveAt(index);
                //if (edges[index].v1 == v1 && edges[index].v2 == v2) edges.RemoveAt(index);
                else index++;
            }
        } // RemoveEdge

        public T RemoveAnyIncidentEdge(T v1)
        // updates self
        // preserves v1
        // requires v1 is in self.vertices and
        //          there exists v: integer such that (
        //             {v1, v} is in self.edges)
        // ensures self.vertices = #self.vertices  and
        //         {v1, RemoveAnyIncidentEdge} is in #self.edges and
        //         self.edges = #self.edges - {{v1, RemoveAnyIncidentEdge}}
        {
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
        } // RemoveAnyIncidentEdge

        public Edge<T> RemoveAnyEdge()
        // updates self
        // requires self.edges /= {}
        // ensures self.vertices = #self.vertices  and
        //         RemoveAnyEdge is in #self.edges  and
        //         self.edges = #self.edges - {RemoveAnyEdge}
        {
            Edge<T> e = new Edge<T>(edges[0].v1, edges[0].v2);
            edges.RemoveAt(0);
            return e;
        } // RemoveAnyEdge

        public int NumberOfVertices()
        // restores self
        // requires true
        // ensures NumberOfVertices = |self.vertices|
        {
            return vertices.Length;
        } // NumberOfVertices

        public int NumberOfEdges()
        // restores self
        // requires true
        // ensures NumberOfEdges = |self.edges|
        {
            return edges.Count;
        } // NumberOfEdges

        public int Degree(T v)
        // restores self
        // requires true
        // ensures Degree = |{v2: integer where ({v, v2} is in self.edges) (v2)}|
        {
            int deg = 0;
            foreach (var edge in edges)
            {

                if (EqualityComparer<T>.Default.Equals(edge.v2, v) || EqualityComparer<T>.Default.Equals(edge.v1, v)) deg++;
            }
            return deg;
        } // Degree

        public bool IsEdge(T v1, T v2)
        // restores self
        // requires true
        // ensures IsEdge = {v1, v2} is in self.edges
        {
            Edge<T> removeEdge = new Edge<T>(v1, v2);
            foreach (var edge in edges)
            {
                if (EqualityComparer<T>.Default.Equals(edge.v1, v1) && EqualityComparer<T>.Default.Equals(edge.v2, v2)) return true;
                else if (EqualityComparer<T>.Default.Equals(edge.v1, v2) && EqualityComparer<T>.Default.Equals(edge.v2, v1)) return true;
            }
            return false;
        } // IsEdge

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            String vert = string.Join(",", vertices);
            String edge = string.Join(",", edges);
            sb.Append("({" + vert + "},");
            sb.Append("{" + edge + "})");
            return sb.ToString();
        } // ToString


    }
}