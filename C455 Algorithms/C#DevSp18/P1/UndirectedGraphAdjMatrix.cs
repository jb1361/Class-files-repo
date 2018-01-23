using System;
using System.Text;
namespace P1
{
    public class UndirectedGraphAdjMatrix
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



        // UndirectedGraph is modeled by (
        //      vertices: finite set of integer
        //      edges: set of Edge
        //   )
        // exemplar self 


        // Finish me:
        // Place the internal data structure declarations here
        int[] vertices;
        int[] edges;


        public UndirectedGraphAdjMatrix()
        // updates self
        // ensures self.vertices = {}  and  self.edges = { }
        {
           
        } // UndirectedGraphAdjMatrix

        public void clear ()
        // clears self
        {
            // Finish me
        } // clear

        public void SetNumberOfVertices(int nv)
        // updates self
        // requires self.vertices = {}  and nv > 0
        // ensures self.vertices = {v: integer where (0 <= v < nv) (v)} and
        //         self.edges = {}
        {
            // Finish me
        } // SetNumberOfVertices

        public void AddEdge(int v1, int v2)
        // updates self
        // requires v1 is in self.vertices  and
        //          v2 is in self.vertices and
        //          {v1, v2} is not in self.edges
        // ensures self.vertices = #self.vertices  and
        //         self.edges = #self.edges union {{v1, v2}}
        {
            // Finish me
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
            // Finish me
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
            // Finish me

            // Note: the following return is incorrect, and must be fixed
            // It is here so that the compiler will not barf because
            // of no return statement being present
            return 0;
        } // NumberOfVertices

        public int NumberOfEdges()
        // restores self
        // requires true
        // ensures NumberOfEdges = |self.edges|
        {
            // Finish me

            // Note: the following return is incorrect, and must be fixed
            // It is here so that the compiler will not barf because
            // of no return statement being present
            return 0;
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
            // Finish me

            // Note: the following return is incorrect, and must be fixed
            // It is here so that the compiler will not barf because
            // of no return statement being present
            return false;
        } // IsEdge

        public override string ToString()
        {
            // Finish me

            StringBuilder sb = new StringBuilder(" ... Finish Me ...");
            return sb.ToString();
        } // ToString

    }
}
