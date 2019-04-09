using System;
using System.Collections.Generic;
using System.Text;
using VertexMap = System.Collections.Generic.Dictionary<int, string>;


namespace P4
{
    class MainClass
    {
        WordHunt wordHunt;
        VertexMap vertexLabels;
        GraphUtility graphUtility;
        public static void Main(string[] args)
        {
            string filename = "";
            if (args.Length == 1)
            {
                filename = args[0];
                MainClass main = new MainClass();
                main.run(filename, 1, args);
            }
            else if (args.Length == 2)
            {
                filename = args[1];
                MainClass main = new MainClass();
                main.run(filename, 2, args);
            }
            else
            {
                filename = "../../GraphG2.txt";
                MainClass main = new MainClass();
                main.run(filename, 0, args);
            }
            

        } // Main

        public void run(string filename, int operation, string[] args)
        {

            int wordLengthMax = 6;
            int[,] graphRep = new int[0, 0];
            vertexLabels = new Dictionary<int, string>();
            graphUtility = new GraphUtility();
            wordHunt = new WordHunt();
            graphUtility.LoadGraphData(filename, vertexLabels, ref graphRep);

            //graphUtility.DisplayVertexLabels(vertexLabels);
            //Console.WriteLine("====================================");

            //graphUtility.DisplayGraphUsingLabels(vertexLabels, graphRep);
            //Console.WriteLine("====================================");

            //graphUtility.ToString(graphRep);
            //Console.WriteLine("====================================");
            if (operation == 1)
            {
                //Operation #1
                Recursive_Matrix_DFS_WordHunt(graphRep, "A");
                //Operation #2
                Iterative_Matrix_DFS_WordHunt(graphRep);
            }
            else if (operation == 2)
            {
                //Operation #3
               // Recursive_List_DFS_WordHunt(graphRep, "A");
                //Operation #4
                return;
            }
            else
            {                
                wordHunt.DFS_WordHunt(graphRep, wordLengthMax, vertexLabels);         
            }
        }
        public void Recursive_Matrix_DFS_WordHunt(int[,] graphRep, string V)
        {                       
            StringBuilder wordSoFar = new StringBuilder();

            int numberOfVertices = graphRep.GetLength(0);
            Console.WriteLine("Starting search for words that begind with: " + V);
            for (int row = 0; row < numberOfVertices; row++)
            {
                wordHunt.DfsVisitWithStartingCharacter(graphRep, row, 6, wordSoFar, vertexLabels, V);
            }
        } // Iterative_Matrix_DFS_WordHunt
        public void Iterative_Matrix_DFS_WordHunt(int[,] graphRep)
        {
            StringBuilder wordSoFar = new StringBuilder();

            int numberOfVertices = graphRep.GetLength(0);
            foreach(var item in vertexLabels)
            {
                for (int row = 0; row < numberOfVertices; row++)
                {
                    wordHunt.DfsVisitWithStartingCharacter(graphRep, row, 6, wordSoFar, vertexLabels, item.Value);
                }
            }
        } // Iterative_Matrix_DFS_WordHunt
    }
}
