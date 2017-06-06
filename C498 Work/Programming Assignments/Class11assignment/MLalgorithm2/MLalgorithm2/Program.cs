using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
    {
  
      private void start()
        {
        readFile();
        assignClusters();
        }
    //change this to an array list that way each index will equal the cluster or make a random way to assign cluster to each value
    public List<string> listA = new List<string>();
    public List<string> listB = new List<string>();
    public List<string> listC = new List<string>();
    public List<string> listD = new List<string>();
    public List<string> listE = new List<string>();
    
    public void readFile()
    {
        
        String location = @"C:\Users\justi\Desktop\Class files repo\Class-files-repo\C498 Work\Class11\irisdata.csv";
        var data = File.OpenRead(location);
        var sr = new StreamReader(data);
        while (!sr.EndOfStream)
        {

            var line = sr.ReadLine();
            var values = line.Split(',');
            Console.Out.WriteLine("Line: " + line);
            listA.Add(values[0]);
            listB.Add(values[1]);
            listC.Add(values[2]);
            listD.Add(values[3]);
            listE.Add(values[4]);
        }

    }


    public void assignClusters()
    {
     //   for(int i = 0; i < listA.Count(); i++)
     //   {

    //    }

    }


    public static void Main(string[] args)
    {
        new Program().start();
    }

}

