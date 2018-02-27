using System;
using System.Collections.Generic;
using VertexMap = System.Collections.Generic.Dictionary<int, string>;

namespace P3
{
    class MainClass 
    {

        public static void Main(string[] args)
        {
            String filename = "../../GraphG1.txt";
            UndirectedGraphLL g1 = new UndirectedGraphLL();
            // Class Dictionary is a C# template 
            // Note: the name "VertexMap" on the line below is defined
            //       at the top of the file in a "using" statement
            VertexMap vertexLabels = new Dictionary<int, string>();
            GraphUtility graphUtility = new GraphUtility();

            graphUtility.LoadGraphData(filename, vertexLabels, g1);

            graphUtility.DisplayVertexLabels(vertexLabels);
            Console.WriteLine("====================================");

            graphUtility.DisplayGraphUsingLabels(vertexLabels, g1);
            Console.WriteLine("====================================");

            Console.WriteLine("g1 = " + g1.ToString());
        }
    }
}

/*
   Here is what your output should look like once you have finished
   the GraphUtility class, based on the input from the GraphG1.txt file
   For a diagram of GraphG1.txt see the file: GraphG1Diagram.png
 
Key = 0, Value = X
Key = 1, Value = C
Key = 2, Value = R
Key = 3, Value = A
Key = 4, Value = T
Key = 5, Value = E
Key = 6, Value = M
Key = 7, Value = F
====================================
({X,C,R,A,T,E,M,F},{{X,C),{X,T),{C,E),{R,A),{R,E),{R,M),{A,M),{A,F),{E,E),{E,M),{M,F)})
====================================
g1 = ({0,1,2,3,4,5,6,7},{{0,1},{0,4},{1,5},{2,3},{2,5},{2,6},{3,6},{3,7},{5,5},{5,6},{6,7}})

Press any key to continue...

 */
