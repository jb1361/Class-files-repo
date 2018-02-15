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

        int time;
        DFSRecord[] dfsarray;
        UndirectedGraphLL G = new UndirectedGraphLL();

        public void run()
        {         
            Console.WriteLine("----------------------------");
            Console.WriteLine("Graph g1 after initialization:");
            Console.WriteLine(G);

            Console.WriteLine();
            LoadGraphData();
            Console.WriteLine(G);
            DFS(G);
            foreach (var item in dfsarray)
            {
                Console.WriteLine(item);
            }
            Console.WriteLine(G);
        }

              
        void DFS(UndirectedGraphLL G)
        {            
            dfsarray = new DFSRecord[G.NumberOfVertices()];
            for (int i = 0; i < dfsarray.Length; i++)
            {
                dfsarray[i] = new DFSRecord(i);
            }
            time = 0;
            foreach (var u in dfsarray)
            {
               
                if (u.color == VertextColor.white)
                {   
                    DFS_Visit(G, u);
                }  
            }                            
        }

        void DFS_Visit(UndirectedGraphLL G, DFSRecord u)
        {           
            time = time + 1;
            u.discoveryTime = time;
            u.color = VertextColor.gray;          
            foreach (var v in dfsarray)
            {
                if (G.IsEdge(u.vertice, v.vertice))                
                {
                    G.RemoveEdge(u.vertice, v.vertice);
                    if (v.color == VertextColor.white)
                    {                        
                        v.predecessor = u.vertice;
                        DFS_Visit(G, v);
                    }
                    G.AddEdge(u.vertice, v.vertice);
                }                
            }               
                u.color = VertextColor.black;
                time = time + 1;
                u.finishingTime = time;           
        }
        public void LoadGraphData()
        {
            //Get Project Path
            string path = Directory.GetParent(Directory.GetCurrentDirectory()).Parent.FullName;
            path = path + "/G1.txt";         
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
        }
    }
}
