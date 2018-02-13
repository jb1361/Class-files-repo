using System;
using System.Text;
using System.Collections.Generic;
namespace P2
{
    public class UndirectedGraphLL
    {
        public class Edge
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

            public void Clear()
            // clears self
            {
                v1 = 0;
                v2 = 0;
            } // Clear

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

        private List<Edge> graphRep;
        private int numberOfVertices;

        private void PutVerticesInOrder(ref int v1, ref int v2)
        {
            if (v1 > v2)
            {
                int temp = v1;
                v1 = v2;
                v2 = temp;
            } // end if
        } // PutVerticesInOrder

        public UndirectedGraphLL()
        // updates self
        // ensures self.vertices = {}  and  self.edges = { }
        {
            graphRep = new List<Edge>();
            numberOfVertices = 0;
        } // UndirectedGraph

        public void Clear()
        // clears self
        {
            graphRep = new List<Edge>();
            numberOfVertices = 0;
        } // Clear

        public void SetNumberOfVertices(int nv)
        // updates self
        // requires self.vertices = {}  and nv > 0
        // ensures self.vertices = {v: integer where (0 <= v < nv) (v)} and
        //         self.edges = {}
        {
            numberOfVertices = nv;
        } // SetNumberOfVertices

        public void AddEdge(int v1, int v2)
        // updates self
        // requires v1 is in self.vertices  and
        //          v2 is in self.vertices and
        //          {v1, v2} is not in self.edges
        // ensures self.vertices = #self.vertices  and
        //         self.edges = #self.edges union {{v1, v2}}
        {
            PutVerticesInOrder(ref v1, ref v2);
            graphRep.Add(new Edge(v1, v2));
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
            PutVerticesInOrder(ref v1, ref v2);
            int k = 0;
            while (!((graphRep[k].v1 == v1) && (graphRep[k].v2 == v2)))
            {
                k++;
            } // end while
            graphRep.RemoveAt(k);
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
            int v2;
            int k = 0;
            while ((graphRep[k].v1 != v1) && (graphRep[k].v2 != v1))
            {
                k++;
            } // end while

            if (graphRep[k].v1 == v1)
            {
                v2 = graphRep[k].v2;
            }
            else
            {
                v2 = graphRep[k].v1;
            } // end if
            graphRep.RemoveAt(k);
            return v2;
        } // RemoveAnyIncidentEdge

        public Edge RemoveAnyEdge()
        // updates self
        // requires self.edges /= {}
        // ensures self.vertices = #self.vertices  and
        //         RemoveAnyEdge is in #self.edges  and
        //         self.edges = #self.edges - {RemoveAnyEdge}
        {
            Edge e = graphRep[0];
            graphRep.RemoveAt(0);
            return e;
        } // RemoveAnyEdge

        public int NumberOfVertices()
        // restores self
        // requires true
        // ensures NumberOfVertices = |self.vertices|
        {
            return numberOfVertices;
        } // NumberOfVertices

        public int NumberOfEdges()
        // restores self
        // requires true
        // ensures NumberOfEdges = |self.edges|
        {
            return graphRep.Count;
        } // NumberOfEdges

        public int Degree(int v)
        // restores self
        // requires true
        // ensures Degree = |{v2: integer where ({v, v2} is in self.edges) (v2)}|
        {
            int count = 0;
            foreach (Edge e in graphRep)
            {
                if ((e.v1 == v || e.v2 == v))
                {
                    count++;
                } // end if
            } // end foreach
            return count;
        } // Degree

        public bool IsEdge(int v1, int v2)
        // restores self
        // requires true
        // ensures IsEdge = {v1, v2} is in self.edges
        {
            int k = 0, z = graphRep.Count;
            PutVerticesInOrder(ref v1, ref v2);
            while ((k < z) && ((graphRep[k].v1 != v1) || (graphRep[k].v2 != v2))) {
                k++;
            } // end while
            return (k < z);
        } // IsEdge

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder("({");

            for (int v = 0; v < numberOfVertices; v++)
            {
                sb.Append(v);
                if ((v + 1) < numberOfVertices)
                {
                    sb.Append(",");
                } // end if
            } // end for
            sb.Append("},{");

            int edgeCount = graphRep.Count;
            foreach (Edge e in graphRep)
            {

                sb.Append("{" + e.v1 + "," + e.v2 + "}");
                edgeCount--;
                if (edgeCount > 0)
                {
                    sb.Append(",");
                } // end if
            } // end foreach
            sb.Append("})");

            return sb.ToString();
        } // ToString

    }
}
