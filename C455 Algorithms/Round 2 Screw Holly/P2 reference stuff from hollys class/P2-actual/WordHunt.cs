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
            if(wordSoFar.Length == wordLengthMax)
            {
                string output = wordSoFar.ToString();
                Console.WriteLine(output);
            }          
            else if (wordSoFar.Length < wordLengthMax)
            {
                foreach (var item in vertexLabels)
                {
                    if(item.Key == u)
                    {
                        string x = item.Value;
                        wordSoFar.Append(x);
                    }                   
                }              
                for (int col = 0; col < graphRep.GetLength(0); col++)
                {
                    if (graphRep[u, col] == 1)
                    {
                        DfsVisit(graphRep, col, wordLengthMax, wordSoFar, vertexLabels);                       
                    }
                }
                wordSoFar.Length++;
            }
        } // DfsVisit


        public void DFS_WordHunt(int[,] graphRep, int wordLengthMax, VertexMap vertexLabels)
        {
            StringBuilder wordSoFar = new StringBuilder();

            int numberOfVertices = graphRep.GetLength(0);

            for (int row = 0; row < numberOfVertices; row++)
            {
                DfsVisit(graphRep, row, wordLengthMax, wordSoFar, vertexLabels);
            }
        } // DFS_WordHunt
    }
}
