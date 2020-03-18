using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading.Tasks;
using Disk_Program.Models;

namespace Disk_Program
{
    public class DiskParser
    {
        private List<string> VolumeData;
        private List<DiskFile> DiskFiles;
        private bool ReadingFromFile { get; set; } = false;
        public bool DataRead { get; set; }
        public bool ReadVolumeFromFile(string filePath)
        {
            ReadingFromFile = true;
            VolumeData = new List<string>();
            DiskFiles = new List<DiskFile>();
            try
            {
                string[] lines = File.ReadAllLines(filePath);

                foreach (var line in lines)
                {
                    VolumeData.Add(line);
                }
                
                DataRead = true;
            }
            catch (Exception e)
            {
                Console.WriteLine("File Does Not Exist");
                return false;
            }
            ReadFiles();
            return true;
        }

        public void ReadDiskFromStandardInput()
        {
            VolumeData = new List<string>();
            DiskFiles = new List<DiskFile>();
            while (true)
            {
                var line = Console.ReadLine();
                if (line == null) break;
                VolumeData.Add(line);
            }
            DataRead = true;
            ReadFiles();
        }

        public bool CheckMalformedDisk()
        {
            var valid = true;
            VolumeData.ForEach(l =>
            {
                if (l.Length != 67 && l.Substring(0,2) != "XX")
                {
                    Console.WriteLine("Segment is Malformed.: " + l);
                    valid = false;
                }
            });
            if (VolumeData.Count < 32)
            {
                valid = false;
            }

            return valid;
        }

        private void ReadFiles()
        {
            var header = ParseDiskLine(VolumeData[2]);
            var firstFileIndex = Convert.ToInt32(header[3]);
            var fileData = ParseDiskLine(VolumeData[firstFileIndex + 2]);
            TraverseDiskFiles(fileData);
        }

        private void TraverseDiskFiles(List<string> record)
        {
            var nextFile = Convert.ToInt32(record[1], 16);
            if (record[0] != "0")
                ReadFileNameAndData(record);
            if (nextFile != 0)
            {
                TraverseDiskFiles(ParseDiskLine(VolumeData[nextFile + 2]));
            }
        }

        private List<string> ParseDiskLine(string header)
        {
            var line = header.Substring(3);
            var lineType = line.Substring(0, 1);
            line = line.Substring(1);
            int i = 0;
            var list =  line.GroupBy(_ => i++ / 2).Select(g => String.Join("", g)).ToList();
            list.Insert(0, lineType);
            return list;
        }
        
        private string TraverseFileData(string fileData, int fileDataIndex)
        {
            var hexData = ParseDiskLine(VolumeData[fileDataIndex + 2]);
            var nextIndex = Convert.ToInt32(hexData[1], 16);
            foreach (var character in hexData.Skip(2))
            {
                fileData += ConvertHex(character);
            }
            if(nextIndex != 0)
                fileData = TraverseFileData(fileData, nextIndex);
            return fileData;
        }

        private void ReadFileNameAndData(List<string> hexString)
        {
            if (hexString[0] == "3")
            {
                var nextFileDataIndex = -1;
                if (hexString[2] != "00")
                {
                    nextFileDataIndex = Convert.ToInt32(hexString[2], 16);
                }

                var readingFileName = true;
                var fileName = "";
                var fileData = "";
                
                foreach (var character in hexString.Skip(3))
                {
                    if (character != "00")
                    {
                        if (readingFileName)
                            fileName += ConvertHex(character);
                        else
                            fileData += ConvertHex(character);
                    }
                    else
                        readingFileName = false;
                }
                if(nextFileDataIndex != -1)
                    fileData = TraverseFileData(fileData, nextFileDataIndex);
                DiskFiles.Add(new DiskFile {FileName = fileName, FileData = fileData});
            }
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
            catch (Exception ex) {  }

            return string.Empty;
        }
        
        
        public List<string> GetFileList() => DiskFiles.Select(f => f.FileName).ToList();
        public void PrintFileContents(string fileName)
        {
            bool fileFound = false;
            DiskFiles.ForEach(f => {
                if (String.Equals(f.FileName, fileName, StringComparison.CurrentCultureIgnoreCase))
                {
                    Console.WriteLine($"{f.FileName} - {f.FileData}");
                    fileFound = true;
                }
            });
            if(!fileFound)
                Console.WriteLine("File does not exist");
        }
        public void PrintDisk() => VolumeData.ForEach(Console.WriteLine);
        public void PrintDiskContents()
        {
            var i = 0;
            VolumeData.ForEach(l =>
            {
                if (i != 0)
                {
                    Console.WriteLine(l.Substring(3));
                }
                i++;
            });
        }
    }
}