using System;
using System.Text;
using VertexMap = System.Collections.Generic.Dictionary<int, string>;

namespace P4
{
    public class WordHunt
    {
        public WordHunt()
        {           
        }

        public void DfsVisit(int[,] graphRep, int u, int wordLengthMax, StringBuilder wordSoFar, VertexMap vertexLabels)
        {
            
            // With the regular DFS Visit a recursive call is made if the color of the vertex is white
            // Here we have no colors, so what is the base case?

            // We are at the base case when |wordSoFar| == wordLengthMax
            // We are not at the base case when the |wordSoFar| < wordLengthMax

            // When at base case
            //   Output the wordSoFar using WriteLine and ToString on wordSoFar
            //   The output word will have length = wordLengthMax
            if(wordSoFar.Length == wordLengthMax)
            {
                string output = wordSoFar.ToString();
                Console.WriteLine(output);
            }
            else if (wordSoFar.Length < wordLengthMax)
            {
                foreach (var item in graphRep)
                {
                    
                }
            }
            // When not at base case
            //   Use parameter u to obtain the character 'x' in graph that is associated with u
            //   Add character 'x' to the end of wordSoFar
            //   Then make a recursive call with each v that is adjacent to u
            //   After the recursive call returns you must remove 'x' from the end of the wordSoFar

            // To do:
            //    Implement this operation based on Cormen's DFS-Visit and the instructions given above
            //    There is no coloring, no keeping track of discovery time, or finish time, or predecessors

            // Not allowed:
            //    Changing the signature of this operation
            //    Using globally declared variables
            //    Using class-level declared variables

        } // DfsVisit

        public void DFS_WordHunt(int[,] graphRep, int wordLengthMax, VertexMap vertexLabels)
        {
            StringBuilder wordSoFar = new StringBuilder();

            int numberOfVertices = graphRep.GetLength(0);

            // To do:
            // Create for loop that calls DfsVisit with each vertex in the vertex set
            // This will be very similar to Cormen's DFS, except DfsVisit must be called with all vertices
            // And there is no coloring, no keeping track of discovery time, or finish time, or predecessors
            foreach (var item in graphRep)
            {
                DfsVisit(graphRep, numberOfVertices, wordLengthMax, wordSoFar, vertexLabels);
            }

            // Not allowed:
            //    Changing the signature of this operation
            //    Using globally declared variables
            //    Using class-level declared variables
        } // DFS_WordHunt
    }
}
