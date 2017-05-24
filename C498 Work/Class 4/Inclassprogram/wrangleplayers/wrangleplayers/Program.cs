using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace wrangleplayers
{
    class Program
    {

        public List<string> listA = new List<string>();
        public List<string> listB = new List<string>();
        public List<string> listC = new List<string>();
        public List<string> listD = new List<string>();

        static void Main(string[] args)
        {
            Program pgm = new Program();
            pgm.Start();
        }

        public void Start()
        {
            int playerCount = -1;
            String youngestPlayer;
            String CountrWithMostPlayers;

            String location = @"C:\Users\justi\Desktop\C498 Work\Class 4\players.csv";
            var players = File.OpenRead(location);
            var sr = new StreamReader(players);
            //  List<string> listA = new List<string>();
            // List<string> listB = new List<string>();
            //  List<string> listC = new List<string>();
            //  List<string> listD = new List<string>();
            while (!sr.EndOfStream)
            {

                var line = sr.ReadLine();
                var values = line.Split(',');
                Console.Out.WriteLine(line);
                playerCount++;
                listA.Add(values[0]);
                listB.Add(values[1]);
                listC.Add(values[2]);
                listD.Add(values[3]);
            }

            Console.Out.WriteLine("=========================================");
            Console.Out.WriteLine("Number of Players: " + playerCount);
            Console.Out.WriteLine("=========================================");
            FindYoungestPlayer();
            findCountrywithMostPlayers();
        }

        public void FindYoungestPlayer()
        {
            String[] year = new String[listD.Count];
            String[] month = new String[listD.Count];
            String[] day = new String[listD.Count];




            //get highest year and put into int array
            for (int i = 1; i < listD.Count; i++)
            {
                var values = listD[i].Split('-');
                year[i] = values[0];
                month[i] = values[1];
                day[i] = values[2];
            }

            int[] Iyear = new int[listD.Count];
            int[] Imonth = new int[listD.Count];
            int[] Iday = new int[listD.Count];
            for (int i = 0; i < year.Length; i++)
            {
                Iyear[i] = Convert.ToInt32(year[i]);
                Imonth[i] = Convert.ToInt32(month[i]);
                Iday[i] = Convert.ToInt32(day[i]);
            }

            int highestYear = 0;
            for (int i = 0; i < Iyear.Length; i++)
            {
                if (Iyear[i] > highestYear)
                {
                    highestYear = Iyear[i];
                }
            }
          //  Console.Out.WriteLine(highestYear.ToString());

            List<int> indexof1985s = new List<int>();
            for(int i = 0; i < Iyear.Length; i++)
            {
                if(Iyear[i] == highestYear)
                {
                    indexof1985s.Add(i);
                }
            }
           
            ////////////////find the lowest month of players born in 1985 
            int lowestmonth = 0;
            for(int i = 0; i < Imonth.Length; i++)
            {
                for(int j = 0; j < indexof1985s.Count; j++)
                {
                    if(indexof1985s[j] == i)
                    {
                        if(Imonth[i] > lowestmonth)
                        {
                           
                            lowestmonth = Imonth[i];
                        }
                    }
                }
            }
           // Console.Out.WriteLine(lowestmonth);

            List<int> indexof1985sand1stmonth = new List<int>();
            for (int i = 0; i < Imonth.Length; i++)
            {
                for (int j = 0; j < indexof1985s.Count; j++)
                {
                    if (indexof1985s[j] == i && Imonth[i] == lowestmonth)
                    {
                        indexof1985sand1stmonth.Add(i);
                    }
                }
            }
         //   Console.Out.WriteLine(indexof1985sand1stmonth[0]);
            Console.Out.WriteLine("Youngest Player: " + listA[indexof1985sand1stmonth[0]]);
            Console.Out.WriteLine("DOB: " + listD[indexof1985sand1stmonth[0]]);
            Console.Out.WriteLine("===============================");
        }//findyoungestplayer
      
        public void findCountrywithMostPlayers()
        {
           

            List<String> difCountries = new List<String>();
            

            for (int i = 1; i < listC.Count; i++)
            {
                if (!difCountries.Contains(listC[i]))
                {
                    difCountries.Add(listC[i]);
                }
                
            }


            List<String>[] countries = new List<String>[difCountries.Count];
            for (int i = 0; i < difCountries.Count; i++)
            {
                countries[i] = new List<string>();
            }


            for (int i = 0; i < difCountries.Count; i++)
            {
                for (int j = 0; j < listC.Count; j++)
                {
                    if(difCountries[i] == listC[j])
                    {
                        countries[i].Add(listC[j]);
                    }

                }

            }
            int mostplayersindex = 0;
            int mostplayers = 0;
             for (int i = 0; i < countries.Length; i++)
              {
                if(countries[i].Count > mostplayers)
                {
                    mostplayers = countries[i].Count;
                    mostplayersindex = i;
                }
              }

            String MostPlayersInCountry = difCountries[mostplayersindex];
            Console.Out.WriteLine("Country With the most Players: " + MostPlayersInCountry + ", Number: " + mostplayers);
           



        }//findcountryplayers



    }//class
}//namespace

