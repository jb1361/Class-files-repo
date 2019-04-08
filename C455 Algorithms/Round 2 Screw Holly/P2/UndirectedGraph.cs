using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P1
{
    class UndirectedGraph
    {
        UndirectedGraphAdjList g2 = new UndirectedGraphAdjList();
        UndirectedGraphAdjMatrix g1 = new UndirectedGraphAdjMatrix();

        public class Edge
        // Note:
        // This class is finished for you
        // No work required here
        {
            // Edge is finite set of integer
            //   exemplar e
            //   constraint |e| = 2

            public int v1;
            public int v2;

            public Edge()
            // updates self
            // ensures self = {0,0}
            {
                v1 = 0;
                v2 = 0;
            } // Edge

            public Edge(int v1, int v2)
            // updates self
            // ensures self = {v1,v2}
            {
                this.v1 = v1;
                this.v2 = v2;
            } // Edge

            public void clear()
            // clears self
            {
                v1 = 0;
                v2 = 0;
            } // clear
            public override string ToString()
            {
                StringBuilder sb = new StringBuilder("{" + v1 + "," + v2 + "}");
                return sb.ToString();
            } // ToString
        } // Edge

        public void SetNumberOfVertices(int n)
        {
            g1.SetNumberOfVertices(n);
            g2.SetNumberOfVertices(n);
        }
        public void AddEdge(int x,int y)
        {
            g1.AddEdge(x, y);

        }
        public void RemoveEdge(int v1,int v2)
        {
            g1.RemoveEdge(v1, v2);
        }
        public int RemoveAnyIncidentEdge(int v1)
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
        public int Degree(int v1)
        {
            return g1.Degree(v1);
        }
        public bool IsEdge(int v1,int v2)
        {
            return g1.IsEdge(v1, v2);
        }
        public Edge RemoveAnyEdge()
        {
            UndirectedGraphAdjMatrix.Edge e = g1.RemoveAnyEdge();
            Edge ee = new Edge(e.v1, e.v2);
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
