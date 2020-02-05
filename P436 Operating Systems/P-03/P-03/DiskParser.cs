using System;
using System.Collections.Generic;

namespace P_03
{
    public class DiskParser
    {
        private List<string> _data;

        public void ReadDisk()
        {
            _data = new List<string>();
            var i = 0;
            while (true)
            {
                var line = Console.ReadLine();
                if (line != null && line.Length == 0) break;
                _data.Add(line);
            }
        }

        public void PrintDiskContents()
        {
            var i = 0;
            _data.ForEach(l =>
            {
                if (i != 0)
                {
                    Console.WriteLine(l.Substring(3));
                }
                i++;
            });
        }
        public void PrintDisk()
        {
            _data.ForEach(l => Console.WriteLine(l));
        }
    }
}