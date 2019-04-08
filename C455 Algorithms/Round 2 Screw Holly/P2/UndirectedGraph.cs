using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P1
{
    class UndirectedGraph<T>
    {
        UndirectedGraphAdjList<T> g2 = new UndirectedGraphAdjList<T>();
        UndirectedGraphAdjMatrix<T> g1 = new UndirectedGraphAdjMatrix<T>();
      

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
   
        public void SetVertices(T[] n)
        {           
            g1.SetVertices(n);
            g2.SetVertices(n);
        }
        public void AddEdge(T x,T y)
        {
            g1.AddEdge(x, y);

        }
        public void RemoveEdge(T v1,T v2)
        {
            g1.RemoveEdge(v1, v2);
        }
        public T RemoveAnyIncidentEdge(T v1)
        {
            return g1.RemoveAnyIncidentEdge(v1);
        }
        public void clear()
        {
            g1.clear();
        }

        public int NumberOfVertices()
        {
            return g1.NumberOfVertices();
        }
       
        public int NumberOfEdges()
        {
            return g1.NumberOfEdges();
        }
        public int Degree(T v1)
        {
            return g1.Degree(v1);
        }
        public bool IsEdge(T v1,T v2)
        {
            return g1.IsEdge(v1, v2);
        }
        public Edge<T> RemoveAnyEdge()
        {
            UndirectedGraphAdjMatrix<T>.Edge<T> e = g1.RemoveAnyEdge();
            Edge<T> ee = new Edge<T>(e.v1, e.v2);
            return ee;
        }

        // Operation #1
        public void ListRecursiveSearch()
        {

        }
        // Operation #2
        public void ListIterativeSearch()
        {

        }
        // Operation #3
        public void MatrixRecursiveSearch()
        {

        }
        // Operation #4
        public void MatrixIterativeSearch()
        {

        }
        public override string ToString()
        {
            return g1.ToString();
        } // ToString     
    }
}
