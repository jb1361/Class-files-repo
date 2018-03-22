using System;
using System.Collections.Generic;
using VertexMap = System.Collections.Generic.Dictionary<int, string>;


namespace P4
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int wordLengthMax = 3;
            //String filename = "../../WordHunt.txt";
            String filename = "../../GraphG1.txt";
            int[,] graphRep = new int[0, 0];
            VertexMap vertexLabels = new Dictionary<int, string>();
            GraphUtility graphUtility = new GraphUtility();
            WordHunt wordHunt = new WordHunt();

            graphUtility.LoadGraphData(filename, vertexLabels, ref graphRep);

            graphUtility.DisplayVertexLabels(vertexLabels);
            Console.WriteLine("====================================");

            graphUtility.DisplayGraphUsingLabels(vertexLabels, graphRep);
            Console.WriteLine("====================================");

            graphUtility.ToString(graphRep);
            Console.WriteLine("====================================");
            wordHunt.DFS_WordHunt(graphRep, wordLengthMax, vertexLabels);

        } // Main
    }
}
