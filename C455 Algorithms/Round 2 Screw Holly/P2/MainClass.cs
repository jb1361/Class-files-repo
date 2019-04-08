using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P1
{
    class MainClass
    {
        private static void LoadGraphs(UndirectedGraph<int> g, UndirectedGraph<string> g2)
        /*
         * Create graph found in C455 Instructional Materials webpage named: Four Different Graph Representations
         * At location: http://pages.iu.edu/~jholly/C455/Notes/Chapter22-1/GraphReps.html
         *    G1 = (V, E)
         *    V = {0, 1, 2, 3, 4, 5, 6, 7}
         *    E = {(0, 1), (0, 4), (1, 5), (2, 3), (2, 5), (2, 6), (3, 6), (3, 7), (5, 5), (5, 6), (6, 7)}
         */
        {
            int[] v = new int[8] {0,1,2,3,4,5,6,7};           
            g.SetVertices(v);

            g.AddEdge(0, 1);
            g.AddEdge(0, 4);
            g.AddEdge(1, 5);
            g.AddEdge(2, 3);
            g.AddEdge(2, 5);
            g.AddEdge(2, 6);
            g.AddEdge(3, 6);
            g.AddEdge(3, 7);
            g.AddEdge(5, 5);
            g.AddEdge(5, 6);
            g.AddEdge(6, 7);
            // V = { A,C,D,E,E,I,L,N,O,O,P,R,T}
            // E = { (A, C),(A, D),(A, E),(A, I),(A, N),(C, D), ...}
            string[] sv = new string[13] { "A", "C", "D", "E", "E", "I", "L", "N", "O", "O", "P", "R", "T" };
            g2.SetVertices(sv);
            g2.AddEdge("A", "C");
            g2.AddEdge("A", "D");
            g2.AddEdge("A", "E");
            g2.AddEdge("A", "I");
            g2.AddEdge("A", "N");
            g2.AddEdge("C", "D");

        } // LoadUpGraphG1

        public static void Main(string[] args)
        {
            if (args.Length == 0 || args.Length == 1)
            {
                // Call recursive operation #1 and iterative operation #2 in undirected graph class
            }
            UndirectedGraph<int> g1 = new UndirectedGraph<int>();
            UndirectedGraph<string> g2 = new UndirectedGraph<string>();

            Console.WriteLine("g1 = " + g1.ToString());
            Console.WriteLine("g2 = " + g2.ToString());
            // Must output the following: 
            // g1 = ({},{})

            // ********************
            // Build the graph found in C455 Instructional Materials webpage named: 
            //    Four Different Graph Representations
            // ********************
            LoadGraphs(g1, g2);


            //// ********************
            //// call g1's ToString
            //// ********************
            //Console.WriteLine("g1 = " + g1.ToString());
            //// Must output the following:
            //// g1 = ({0,1,2,3,4,5,6,7},{{0,1},{0,4},{1,5},{2,3},{2,5},{2,6},{3,6},{3,7},{5,5},{5,6},{6,7}})


            //// ********************
            //// call g1's NumberOfVertices
            //// ********************
            //Console.WriteLine("|g1.vertices| = " + g1.NumberOfVertices());
            //// Must output the following:
            //// |g1.vertices| = 8


            //// ********************
            //// call g1's NumberOfEdges
            //// ********************
            //Console.WriteLine("|g1.edges| = " + g1.NumberOfEdges());
            //// Must output the following:
            //// |g1.edges| = 11


            //// ********************
            //// call g1's Degree
            //// ********************
            //int v1 = 5;
            //Console.WriteLine("deg(" + v1 + ") = " + g1.Degree(v1));
            //// Must output the following:
            //// deg(5) = 4


            //// ********************
            //// call g1's IsEdge
            //// ********************
            //v1 = 5;
            //int v2 = 2;
            //Console.WriteLine("{" + v1 + "," + v2 + "} is in g1.edges = " + g1.IsEdge(v1, v2));
            //// Must output the following:
            //// {5,2} is in g1.edges = True


            //// ********************
            //// call g1's IsEdge
            //// ********************
            //v1 = 1;
            //v2 = 7;
            //Console.WriteLine("{" + v1 + "," + v2 + "} is in g1.edges = " + g1.IsEdge(v1, v2));
            //// Must output the following:
            //// {1,7} is in g1.edges = False


            //// ********************
            //// call g1's RemoveEdge
            //// ********************
            //v1 = 2;
            //v2 = 6;
            //Console.WriteLine("g1 = " + g1.ToString());
            //// Must output the following:
            //// g1 = ({0,1,2,3,4,5,6,7},{{0,1},{0,4},{1,5},{2,3},{2,5},{2,6},{3,6},{3,7},{5,5},{5,6},{6,7}})
            //g1.RemoveEdge(v1, v2);

            //Console.WriteLine("g1 = " + g1.ToString());
            //// Must output the following:
            //// g1 = ({0,1,2,3,4,5,6,7},{{0,1},{0,4},{1,5},{2,3},{2,5},{3,6},{3,7},{5,5},{5,6},{6,7}})


            //// ********************
            //// call g1's RemoveAnyIncidentEdge
            //// ********************
            //v1 = 2;
            //// RemoveAnyIncidentEdge, by its own choosing, can remove any of the following edges:
            ////    {2,3}, {2,5}
            //v2 = g1.RemoveAnyIncidentEdge(v1);
            //Console.WriteLine("v2 = " + v2 + "   g1 = " + g1.ToString());
            //// Must output either one of the following:
            //// v2 = 3   g1 = ({0,1,2,3,4,5,6,7},{{0,1},{0,4},{1,5},{2,5},{3,6},{3,7},{5,5},{5,6},{6,7}})
            //// or
            //// v2 = 5   g1 = ({0,1,2,3,4,5,6,7},{{0,1},{0,4},{1,5},{2,3},{3,6},{3,7},{5,5},{5,6},{6,7}})


            //// ********************
            //// call g1's clear
            //// ********************
            //g1.clear();
            //Console.WriteLine("g1 = " + g1.ToString());
            //// Must output the following: 
            //// g1 = ({},{})


            //// ********************
            //// call g1's RemoveAnyEdge
            //// ********************

            //// Because of the call to g1's clear operation (above)
            //// At this point g1 = ({},{})
            //// Add edges: {2,3}, {2,5}, {2,6}
            //g1.SetNumberOfVertices(8);
            //g1.AddEdge(2, 3);
            //g1.AddEdge(2, 5);
            //g1.AddEdge(2, 6);
            //Console.WriteLine("g1 = " + g1.ToString());

            //for (int k = 0, z = g1.NumberOfEdges(); k < z; k++)
            //{
            //    UndirectedGraph<int>.Edge<int> e = g1.RemoveAnyEdge();
            //    Console.WriteLine("edge #" + (k + 1) + " removed is: " + e.ToString());
            //} // end for


            // ********************
            // call g2's ToString
            // ********************
            Console.WriteLine("g2 = " + g2.ToString());
            // Must output the following:
            // g2 = ({0,1,2,3,4,5,6,7},{{0,1},{0,4},{1,5},{2,3},{2,5},{2,6},{3,6},{3,7},{5,5},{5,6},{6,7}})


            // ********************
            // call g2's NumberOfVertices
            // ********************
            Console.WriteLine("|g2.vertices| = " + g2.NumberOfVertices());
            // Must output the following:
            // |g2.vertices| = 8


            // ********************
            // call g2's NumberOfEdges
            // ********************
            Console.WriteLine("|g2.edges| = " + g2.NumberOfEdges());
            // Must output the following:
            // |g2.edges| = 11


            // ********************
            // call g2's Degree
            // ********************
            string v1 = "A";
            Console.WriteLine("deg(" + v1 + ") = " + g2.Degree(v1));
            // Must output the following:
            // deg(5) = 4


            // ********************
            // call g2's IsEdge
            // ********************
            v1 = "B";
            string v2 = "A";
            Console.WriteLine("{" + v1 + "," + v2 + "} is in g2.edges = " + g2.IsEdge(v1, v2));
            // Must output the following:
            // {5,2} is in g2.edges = True


            // ********************
            // call g2's IsEdge
            // ********************
            v1 = "C";
            v2 = "O";
            Console.WriteLine("{" + v1 + "," + v2 + "} is in g2.edges = " + g2.IsEdge(v1, v2));
            // Must output the following:
            // {1,7} is in g2.edges = False


            // ********************
            // call g2's RemoveEdge
            // ********************
            v1 = "A";
            v2 = "B";
            Console.WriteLine("g2 = " + g2.ToString());
            // Must output the following:
            // g2 = ({0,1,2,3,4,5,6,7},{{0,1},{0,4},{1,5},{2,3},{2,5},{2,6},{3,6},{3,7},{5,5},{5,6},{6,7}})
            g2.RemoveEdge(v1, v2);

            Console.WriteLine("g2 = " + g2.ToString());
            // Must output the following:
            // g2 = ({0,1,2,3,4,5,6,7},{{0,1},{0,4},{1,5},{2,3},{2,5},{3,6},{3,7},{5,5},{5,6},{6,7}})


            // ********************
            // call g2's RemoveAnyIncidentEdge
            // ********************
            v1 = "A";
            // RemoveAnyIncidentEdge, by its own choosing, can remove any of the following edges:
            //    {2,3}, {2,5}
            v2 = g2.RemoveAnyIncidentEdge(v1);
            Console.WriteLine("v2 = " + v2 + "   g2 = " + g2.ToString());
            // Must output either one of the following:
            // v2 = 3   g2 = ({0,1,2,3,4,5,6,7},{{0,1},{0,4},{1,5},{2,5},{3,6},{3,7},{5,5},{5,6},{6,7}})
            // or
            // v2 = 5   g2 = ({0,1,2,3,4,5,6,7},{{0,1},{0,4},{1,5},{2,3},{3,6},{3,7},{5,5},{5,6},{6,7}})


            // ********************
            // call g2's clear
            // ********************
            g2.clear();
            Console.WriteLine("g2 = " + g2.ToString());
            // Must output the following: 
            // g2 = ({},{})


            // ********************
            // call g2's RemoveAnyEdge
            // ********************

            // Because of the call to g2's clear operation (above)
            // At this point g2 = ({},{})
            // Add edges: {2,3}, {2,5}, {2,6}
            string[] sv = new string[1] {"Y"};
            g2.SetVertices(sv);
            g2.AddEdge("X", "Y");
            g2.AddEdge("Y", "Z");
            g2.AddEdge("F", "U");
            Console.WriteLine("g2 = " + g2.ToString());

            for (int k = 0, z = g2.NumberOfEdges(); k < z; k++)
            {
                UndirectedGraph<string>.Edge<string> e = g2.RemoveAnyEdge();
                Console.WriteLine("edge #" + (k + 1) + " removed is: " + e.ToString());
            } // end for    
        } // main
    } // MainClass
}
