using System;
using System.Collections;
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
        KMeansCluster();
       // meanOfClusters();
      //  debug();
        }
    //change this to an array list that way each index will equal the cluster or make a random way to assign cluster to each value
    public List<string> listA = new List<string>();
    public List<string> listB = new List<string>();
    public List<string> listC = new List<string>();
    public List<string> listD = new List<string>();
    public List<string> listE = new List<string>();
    public ArrayList cluster1 = new ArrayList();
    public ArrayList cluster2 = new ArrayList();
    public ArrayList cluster3 = new ArrayList();
    public double cluster1Mean = 0;
    public double cluster2Mean = 0;
    public double cluster3Mean = 0;

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
        Random rand = new Random();

        //assign listA
        for (int i = 0; i < listA.Count(); i++)
        {
            int num = rand.Next(0, 3);
            switch (num) { 

                 case 0:
                    cluster1.Add(listA[i]);
                     break;
                case 1:
                    cluster2.Add(listA[i]);
                    break;
                case 2:
                    cluster3.Add(listA[i]);
                    break;
            }
           
        }

        //assign listB
        for (int i = 0; i < listB.Count(); i++)
        {

            int num = rand.Next(0, 3);
            switch (num)
            {

                case 0:
                    cluster1.Add(listB[i]);
                    break;
                case 1:
                    cluster2.Add(listB[i]);
                    break;
                case 2:
                    cluster3.Add(listB[i]);
                    break;
            }

        }
        //assign listC
        for (int i = 0; i < listC.Count(); i++)
        {

            int num = rand.Next(0, 3);
            switch (num)
            {

                case 0:
                    cluster1.Add(listC[i]);
                    break;
                case 1:
                    cluster2.Add(listC[i]);
                    break;
                case 2:
                    cluster3.Add(listC[i]);
                    break;
            }

        }
        //assign listD
        for (int i = 0; i < listD.Count(); i++)
        {
            int num = rand.Next(0, 3);
            switch (num)
            {

                case 0:
                    cluster1.Add(listD[i]);
                    break;
                case 1:
                    cluster2.Add(listD[i]);
                    break;
                case 2:
                    cluster3.Add(listD[i]);
                    break;
            }


        }

    }


    public void meanOfClusters()
    {
        double temp1 = 0;
        double temp2 = 0;
        double temp3 = 0;
        for (int i = 0; i < cluster1.Count; i++)
        {    
            temp1 = temp1 + getValue(cluster1,i);
        } 
        for (int i = 0; i < cluster2.Count; i++)
        {
            temp2 = temp2 + getValue(cluster2, i);
        } 
        for (int i = 0; i < cluster3.Count; i++)
        {
            temp3 = temp2 + getValue(cluster3, i);
        }
       
         cluster1Mean = temp1 / cluster1.Count;
         cluster2Mean = temp2 / cluster2.Count;
         cluster3Mean = temp3 / cluster3.Count;

       // Console.Out.WriteLine("Cluster 1 Mean: " + cluster1Mean);
     //   Console.Out.WriteLine("Cluster 2 Mean: " + cluster2Mean);
     //   Console.Out.WriteLine("Cluster 3 Mean: " + cluster3Mean);
    }

   double getValue(ArrayList list,int i)
    {
        double value = Convert.ToDouble(list[i]);
        return value;
    }


    public void KMeansCluster()
    {
        int iterations = 10000;
        for(int i = 0; i < iterations; i++)
        {
            //Console.Out.WriteLine("Iteration: " + i);
            meanOfClusters();



            //go through cluster 1
            for(int j = 0; j < cluster1.Count;j++)
            {
                int k = getClosestCluster(Convert.ToDouble(cluster1[j]));
                switch (k)
                {
                    
                    case 0:                      
                        break;             
                    case 1:                     
                        double val = Convert.ToDouble(cluster1[j]);
                        cluster2.Add(val);
                        cluster1.RemoveAt(j);             
                        break;
                    case 2:                     
                        double val2 = Convert.ToDouble(cluster1[j]);
                        cluster3.Add(val2);
                        cluster1.RemoveAt(j);
                        break;
                }
            }

            //sort through cluster 2
            for (int l = 0; l < cluster2.Count; l++)
            {
                int k = getClosestCluster(Convert.ToDouble(cluster2[l]));
                switch (k)
                {
                    case 0:
                        double val = Convert.ToDouble(cluster2[l]);
                        cluster1.Add(val);
                        cluster2.RemoveAt(l);
                        break;
                    case 1:                                    
                        break;
                    case 2:
                        double val2 = Convert.ToDouble(cluster2[l]);
                        cluster3.Add(val2);
                        cluster2.RemoveAt(l);
                        break;
                }
            }

            //sort through cluster 3
            for (int m = 0; m < cluster3.Count; m++)
            {
                int k = getClosestCluster(Convert.ToDouble(cluster3[m]));
                switch (k)
                {
                    case 0:
                        double val = Convert.ToDouble(cluster3[m]);
                        cluster1.Add(val);
                        cluster3.RemoveAt(m);
                        break;
                    case 1:
                        double val2 = Convert.ToDouble(cluster3[m]);
                        cluster1.Add(val2);
                        cluster3.RemoveAt(m);
                        break;
                    case 2:                      
                        break;
                }
            }


        }//end of iterations loop

        predict();

    }//end of kmeans

   int getClosestCluster(double val)
    {
        double[] array = new double[3];
        array[0] = Math.Abs(cluster1Mean - val);
        array[1] = Math.Abs(cluster2Mean - val);
        array[2] = Math.Abs(cluster3Mean - val);
        double cluster = array.Min();
        return Array.IndexOf(array,cluster);
    }




   
    public void predict()
    {
        //we are pedicting based of the mean of what each flower is, virginica has the largest average so our largest mean of a cluster is virginica and is applied to each flower.
        Console.Out.WriteLine(cluster1Mean);
        Console.Out.WriteLine(cluster2Mean);
        Console.Out.WriteLine(cluster3Mean);


        //I know theres a way better way to do this but I just figured id keep it simple
        if(cluster1Mean > cluster2Mean && cluster1Mean > cluster3Mean)
        {
            Console.Out.WriteLine("Virginica is cluster 1.");
        }else if(cluster2Mean > cluster1Mean &&  cluster2Mean > cluster3Mean)
        {
            Console.Out.WriteLine("Virginica is cluster 2.");
        }
        else if (cluster3Mean > cluster1Mean && cluster3Mean > cluster2Mean)
        {
            Console.Out.WriteLine("Virginica is cluster 3.");
        }


        if (cluster1Mean < cluster2Mean && cluster1Mean < cluster3Mean)
        {
            Console.Out.WriteLine("Setosa is cluster 1.");
        }
        else if (cluster2Mean < cluster1Mean && cluster2Mean < cluster3Mean)
        {
            Console.Out.WriteLine("Setosa is cluster 2.");
        }
        else if (cluster3Mean < cluster1Mean && cluster3Mean < cluster2Mean)
        {
            Console.Out.WriteLine("Setosa is cluster 3.");
        }


        if (cluster1Mean < cluster2Mean && cluster1Mean > cluster3Mean)
        {
            Console.Out.WriteLine("Versicolor is cluster 1.");
        }
        else if (cluster2Mean < cluster1Mean && cluster2Mean > cluster3Mean)
        {
            Console.Out.WriteLine("Versicolor is cluster 2.");
        }
        else if (cluster3Mean < cluster1Mean && cluster3Mean > cluster2Mean)
        {
            Console.Out.WriteLine("Versicolor is cluster 3.");
        }
         else if (cluster1Mean > cluster2Mean && cluster1Mean < cluster3Mean)
        {
            Console.Out.WriteLine("Versicolor is cluster 1.");
        }
        else if (cluster2Mean < cluster1Mean && cluster2Mean < cluster3Mean)
        {
            Console.Out.WriteLine("Versicolor is cluster 2.");
        }
        else if (cluster3Mean < cluster1Mean && cluster3Mean < cluster2Mean)
        {
            Console.Out.WriteLine("Versicolor is cluster 3.");
        }

    }








    public void debug()
    {
        int totalinclusters = cluster1.Count + cluster2.Count + cluster3.Count;
        int totalinlists = listA.Count() + listB.Count() + listC.Count() + listD.Count();
        Console.Out.WriteLine("Data in clusters: " + totalinclusters);
        Console.Out.WriteLine("Data in Lists: " +totalinlists);
       
     
       //Debugging the clusters
      Console.Out.WriteLine("Cluster1: ");
      for (int i = 0; i < cluster1.Count; i++)
      {
          Console.Out.WriteLine(cluster1[i]);
      }
      Console.Out.WriteLine("Cluster2: ");
      for (int i = 0; i < cluster2.Count; i++)
      {
          Console.Out.WriteLine(cluster2[i]);
      }
      Console.Out.WriteLine("Cluster3: ");
      for (int i = 0; i < cluster3.Count; i++)
      {
          Console.Out.WriteLine(cluster3[i]);
      }
      
    }

    public static void Main(string[] args)
    {
        new Program().start();
    }

}

