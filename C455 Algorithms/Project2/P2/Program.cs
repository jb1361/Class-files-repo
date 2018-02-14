using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P2
{
    class Program
    {
        static void Main(string[] args)
        {
            Program pgm = new Program();
            pgm.run();
        }
        public void run()
        {
            UndirectedGraphLL G; //= new UndirectedGraphLL();
            G = LoadGraphData();
            Console.WriteLine(G);
        }

        void DFS(UndirectedGraphLL G)
        {
           // DFSArray;

            /*
             	for each vertex u ∈ G.V
 	   // WHITE - not discovered
   // GRAY  - discovered and being processed
   // BLACK - discovered and finished
2	   u.color = WHITE
3	   u.Π = NIL
4	time = 0
 	// Perform depth first search
5	for each vertex u ∈ G.V
6	    if u.color == WHITE
7	       DFS-Visit (G, u)
*/


        }

        void DFS_Visit(UndirectedGraphLL G, VertextColor U)
        {

        }
        UndirectedGraphLL LoadGraphData()
        {

            UndirectedGraphLL G = new UndirectedGraphLL();

            //Get Project Path
            string path = Directory.GetParent(Directory.GetCurrentDirectory()).Parent.FullName;
            path = path + "/G1.txt";
            Console.WriteLine(path);
            System.Text.StringBuilder inp = new System.Text.StringBuilder();
            //Read input into stringbuilder.
            using (System.IO.StreamReader file = new System.IO.StreamReader(path))
            {
                while (!file.EndOfStream)
                {
                     inp.Append(file.ReadLine()).Append(",");   
                }          
            }

            //parse read input into regular string.
            string parsed = inp.ToString();
            parsed = parsed.TrimEnd(',');

            //first number is number of vertices so we get that then remove it from the string.
            int v = 0;
            Int32.TryParse(parsed[0].ToString(), out v);
            G.SetNumberOfVertices(v);
            parsed = parsed.Remove(0, 2);

            //get ammount fo numbers.
            int sLen = 0;
            for (int i = 0; i < parsed.Length; i++)
            {
                if (parsed[i] != ',') sLen++;
            }

            //add edges
            int i1 = 0;
            int i2 = 2;
            for (int i = 0; i < sLen/2; i++)
            {
               
                int v1;
                int v2;
                Int32.TryParse(parsed[i1].ToString(), out v1);
                Int32.TryParse(parsed[i2].ToString(), out v2);
                G.AddEdge(v1, v2);
                i1 = i1 + 4;
                i2 = i2 + 4;
                
            }

            return G;
        }
    }
}
