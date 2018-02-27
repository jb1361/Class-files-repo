using System;
using System.Collections.Generic;

/*
 * Name: 
 */

// Note: the name "VertexMap" is used in some of the operation headers below
using VertexMap = System.Collections.Generic.Dictionary<int, string>;

namespace P3
{
    public class GraphUtility
    {
        public GraphUtility()
        {
        }

        // -----------------------------------------------------------------------

        public void LoadGraphData(String filename, VertexMap vertexLabels, UndirectedGraphLL g)
        // Loads the graph data from filename into vertexLabels and g
        {
            System.IO.StreamReader file = new System.IO.StreamReader(filename);
            int x;
            Int32.TryParse(file.ReadLine(),out x);           
            for (int i = 0; i < x; i++)
            {
                vertexLabels.Add(i, file.ReadLine());
            }
            int largest = 0;
            while (!file.EndOfStream)
            {
                int v1; 
                int v2;
                Int32.TryParse(file.ReadLine(), out v1);
                Int32.TryParse(file.ReadLine(), out v2);
                g.AddEdge(v1, v2);
                if (v1 > largest) largest = v1;
                if (v2 > largest) largest = v2;
            }
            file.Close();          
            g.SetNumberOfVertices(largest+1);
        } // loadGraphData

        // -----------------------------------------------------------------------

        public void DisplayVertexLabels(VertexMap vertexLabels)
        // ensures vertexLabels = #vertexLabels
        // Uses Console.Write and .Writeline to display contents of vertexLabels
        // in the format shown in the sample output
        // Sample output is at the bottom of Program.cs
        {
            foreach (var item in vertexLabels)
            {
                Console.WriteLine("Key = " + item.Key + ", Value = " + item.Value);
            }         
        } // DisplayVertexLabels

        // -----------------------------------------------------------------------

        public void DisplayGraphUsingLabels(VertexMap vertexLabels, UndirectedGraphLL g)
        // ensures vertexLabels = #vertexLabels and g = #g
        // Uses Console.Write and .Writeline to display contents of g
        // in the format shown in the sample output
        // Sample output is at the bottom of Program.cs
        {
            // Finish me
        } // DisplayGraphUsingLabels

    }
}

