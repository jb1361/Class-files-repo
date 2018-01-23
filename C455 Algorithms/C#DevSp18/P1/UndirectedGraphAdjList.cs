using System;
using System.Collections.Generic;
using System.Text;
namespace P1
{
    public class UndirectedGraphAdjList
    {
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

        int[] vertices;
        List<Edge> edges;

        public UndirectedGraphAdjList()
        // updates self
        // ensures self.vertices = {}  and  self.edges = { }
        {
            vertices = new int[0];
            edges = new List<Edge>();
        } // UndirectedGraphAdjList

        public void clear ()
        // clears self
        {
            vertices = new int[0];
            edges.Clear();
        } // clear

        public void SetNumberOfVertices(int nv)
        // updates self
        // requires self.vertices = {}  and nv > 0
        // ensures self.vertices = {v: integer where (0 <= v < nv) (v)} and
        //         self.edges = {}
        {
            vertices = new int[nv];
            for (int i = 0; i < nv; i++) vertices[i] = i;
        } // SetNumberOfVertices

        public void AddEdge(int v1, int v2)
        // updates self
        // requires v1 is in self.vertices  and
        //          v2 is in self.vertices and
        //          {v1, v2} is not in self.edges
        // ensures self.vertices = #self.vertices  and
        //         self.edges = #self.edges union {{v1, v2}}
        {
            Edge newEdge = new Edge(v1, v2);
            edges.Add(newEdge);
        } // AddEdge

        public void RemoveEdge(int v1, int v2)
        // updates self
        // preserves v1, v2
        // requires v1 is in self.vertices and
        //          v2 is in self.vertices and
        //          {v1, v2} is in self.edges
        // ensures self.vertices = #self.vertices  and
        //         self.edges = #self.edges - {{v1, v2}}
        {
           
            Edge removeEdge = new Edge(v1, v2);
            foreach (var edge in edges)
            {
                if (edge.v1 == v1 && edge.v2 == v2) edges.Remove(removeEdge);  
            }
            
        } // RemoveEdge

        public int RemoveAnyIncidentEdge(int v1)
        // updates self
        // preserves v1
        // requires v1 is in self.vertices and
        //          there exists v: integer such that (
        //             {v1, v} is in self.edges)
        // ensures self.vertices = #self.vertices  and
        //         {v1, RemoveAnyIncidentEdge} is in #self.edges and
        //         self.edges = #self.edges - {{v1, RemoveAnyIncidentEdge}}
        {
            // Finish me

            // Note: the following return is incorrect, and must be fixed
            // It is here so that the compiler will not barf because
            // of no return statement being present
            return 0;
        } // RemoveAnyIncidentEdge

        public Edge RemoveAnyEdge()
        // updates self
        // requires self.edges /= {}
        // ensures self.vertices = #self.vertices  and
        //         RemoveAnyEdge is in #self.edges  and
        //         self.edges = #self.edges - {RemoveAnyEdge}
        {
            // Finish me

            // Note: the following return is incorrect, and must be fixed
            // It is here so that the compiler will not barf because
            // of no return statement being present
            return new Edge(0, 0);
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

        public int Degree(int v)
        // restores self
        // requires true
        // ensures Degree = |{v2: integer where ({v, v2} is in self.edges) (v2)}|
        {
            // Finish me

            // Note: the following return is incorrect, and must be fixed
            // It is here so that the compiler will not barf because
            // of no return statement being present
            return 0;
        } // Degree

        public bool IsEdge(int v1, int v2)
        // restores self
        // requires true
        // ensures IsEdge = {v1, v2} is in self.edges
        {
            Edge removeEdge = new Edge(v1, v2);
            foreach (var edge in edges)
            {

                //need to add cases for the reverse since an edge is just two points so it doesnt matter which way it goes.
                Console.WriteLine("=========");
                Console.WriteLine("v1: " + edge.v1);
                Console.WriteLine("v1: " + v1);
                if (edge.v1 == v1) Console.WriteLine("Match");
                Console.WriteLine("v2: " + edge.v2);
                Console.WriteLine("v2: " + v2);
                if (edge.v2 == v2) Console.WriteLine("v2 Match");
                Console.WriteLine("=========");
                Console.WriteLine();
               
                if (edge.v1 == v1 && edge.v2 == v2)
                {
                   
                    
                    return true;
                }
                
            }
            return false;
            // Note: the following return is incorrect, and must be fixed
            // It is here so that the compiler will not barf because
            // of no return statement being present
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
