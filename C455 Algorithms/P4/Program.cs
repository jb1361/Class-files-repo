using System;
using System.Collections.Generic;
using VertexMap = System.Collections.Generic.Dictionary<int, string>;


namespace P4
{
    // Initial build and run
    //   As the project stands just after downloading and unzipping, it will build and run
    //   It will load GraphG1.txt and display its contents using GraphUtility operations
    //   It works on an adjacency matrix graph representation

    // To do:
    //   Implement DFS_WordHunt and DfsVisit found in WordHunt.cs
    //
    // Testing:
    // (1) Test with GraphG1.txt found in the P4 folder
    //     The "words" output by your implementation do not have to be in the
    //     same order as the "words" found in GraphG1-SolutionOutput.txt, but 
    //     you do have to output all the same "words"
    // (2) Create a .txt input file based on the graph found in WordHunt.jpg
    //     Test with this data file
    //     I'll be testing with wordLengthMax = 3 and = 5


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
