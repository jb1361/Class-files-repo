using System;
using System.Collections.Generic;
using System.Linq;

namespace P_03
{
    public class DiskParser
    {
        private List<string> Data;
        public bool DataRead { get; set; }
        public void ReadDiskFromFile(string filePath)
        {
            Data = new List<string>();
            try
            {
                string[] lines = System.IO.File.ReadAllLines(filePath);

                foreach (var line in lines)
                {
                    Data.Add(line);
                }

                DataRead = true;
            }
            catch (Exception e)
            {
                Console.WriteLine("File Does Not Exist.");
            }
        }

        public void ReadDiskFromStandardInput()
        {
            Data = new List<string>();
            while (true)
            {
                var line = Console.ReadLine();
                if (line == null) break;
                Data.Add(line);
            }
            DataRead = true;
        }

        public bool CheckMalformedDisk()
        {
            var valid = true;
            Data.ForEach(l =>
            {
                if (l.Length != 67 && l.Substring(0,2) != "XX")
                {
                    Console.WriteLine("Segment is Malformed.: " + l);
                    valid = false;
                }
            });
            if (Data.Count < 32)
            {
                valid = false;
            }

            return valid;
        }

        public void PrintDiskContents()
        {
            var i = 0;
            Data.ForEach(l =>
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
            Data.ForEach(l => Console.WriteLine(l));
        }

        public void PrintFileList()
        {
            var header = ReadDiskLine(Data[2]);
            var firstFileIndex = Convert.ToInt32(header[3]);
            List<string> files = new List<string>();
            var fileData = ReadDiskLine(Data[firstFileIndex + 2]);
            TraverseDiskFiles(files, fileData);
            files.ForEach(f => Console.WriteLine($"-{f}"));
        }

        public void TraverseDiskFiles(List<string> files, List<string> record)
        {
            var nextFile = Convert.ToInt32(record[1], 16);
            // var fileData = Convert.ToInt32(record[2]);
            var fileName = "";
            var fileNameHex = record.GetRange(3, record.Count - 4);
            var hexString = String.Join("", fileNameHex);
            fileName += ConvertHex(hexString);
            files.Add(fileName);
            if (nextFile != 0)
            {
                TraverseDiskFiles(files, ReadDiskLine(Data[nextFile + 2]));
            }
        }

        private List<string> ReadDiskLine(string header)
        {
            var line = header.Substring(3);
            var lineType = line.Substring(0, 1);
            line = line.Substring(1);
            int i = 0;
            var list =  line.GroupBy(_ => i++ / 2).Select(g => String.Join("", g)).ToList();
            list.Insert(0, lineType);
            return list;
        }
        
        public static string ConvertHex(String hexString)
        {
            try
            {
                string ascii = string.Empty;

                for (int i = 0; i < hexString.Length; i += 2)
                {
                    String hs = string.Empty;

                    hs   = hexString.Substring(i,2);
                    uint decval =   Convert.ToUInt32(hs, 16);
                    char character = Convert.ToChar(decval);
                    ascii += character;

                }

                return ascii;
            }
            catch (Exception ex) { Console.WriteLine(ex.Message); }

            return string.Empty;
        }
    }
}