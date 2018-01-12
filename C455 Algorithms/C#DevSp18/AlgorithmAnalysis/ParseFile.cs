using System;
using System.Collections.Generic;
using System.Linq;



namespace AlgorithmAnalysis
{
    class ParseFile
    {
        public void run()
        {
            string exePath = Environment.CurrentDirectory;
            string filepath = exePath + "\\test.txt";
            Console.WriteLine(filepath);
            string[] text = System.IO.File.ReadAllLines(@filepath);
            foreach (var item in text)
            {
                Console.WriteLine(item);
            }
            Analyze(text);
        }
        
        public void Analyze(string[] algorithm)
        {
           
        }
       
    
      
    }
}
