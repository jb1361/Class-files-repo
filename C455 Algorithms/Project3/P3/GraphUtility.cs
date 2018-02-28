using System;
using System.Collections.Generic;
using System.Text;

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
            Console.WriteLine(g);
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
            StringBuilder sb = new StringBuilder("({");
            foreach (var item in vertexLabels)
            {
                sb.Append(item.Value + ",");
                //sb.Append
               
            }
            sb.Length--;
            sb.Append("},{");           
            int x = g.NumberOfEdges();
            while(x > 0)
            {
                UndirectedGraphLL.Edge edge;
                edge = g.RemoveAnyEdge();
                StringBuilder vert1 = new StringBuilder("{");
                StringBuilder vert2 = new StringBuilder(",");
                foreach (var item in vertexLabels)
                {
                    if (edge.v1 == item.Key) vert1.Append(item.Value);
                    if (edge.v2 == item.Key) vert2.Append(item.Value + "}");
                }
                sb.Append(vert1);
                sb.Append(vert2);
                sb.Append(",");
                g.AddEdge(edge.v1, edge.v2);
                
                x--;
            }
            sb.Length--;
            sb.Append("})");
            Console.WriteLine(sb);
        } // DisplayGraphUsingLabels

    }
}

