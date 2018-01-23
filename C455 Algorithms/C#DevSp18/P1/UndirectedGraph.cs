using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P1
{
    class UndirectedGraph
    {
        UndirectedGraphAdjList g1 = new UndirectedGraphAdjList();
        UndirectedGraphAdjMatrix g2 = new UndirectedGraphAdjMatrix();
        
        public class Edge
        {

        }
        
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
            return 0;
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
            return 0;
        }
        public bool IsEdge(int v1,int v2)
        {
            return true;
        }
        public override string ToString()
        {
            return g1.ToString();
        } // ToString

    }
}
