using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using System.CommandLine;
using System.CommandLine.Invocation;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;

namespace Disk_Program
{
   public class DiskProgram
    {
        private readonly DiskParser _parser;
        public bool ContinueRunning { get; set; }
        public DiskProgram()
        {
            _parser = new DiskParser();;
        }

        public void ReadFile(string filePath)
        {
           ContinueRunning = _parser.ReadVolumeFromFile(filePath);
           ContinueRunning = _parser.CheckMalformedDisk();
        }
        public void PrintFiles()
        {
            if (!_parser.DataRead)
            {
                _parser.ReadDiskFromStandardInput();
            }
            _parser.GetFileList().ForEach(Console.WriteLine);
        }
        
        public void PrintDiskUsage()
        {
            if (!_parser.DataRead)
            {
                _parser.ReadDiskFromStandardInput();
            }

            var totalSpace = _parser.VolumeData.Count * _parser.VolumeData[0].Length;
            var usedSpace = 0;
            _parser.VolumeData.ForEach(v =>
            {
                v.
            });
        }
        
        public void CreateDisk(string name, int size, int length)
        {
            List<string> disk = new List<string>();
            int columnSize = length / 4;
            string space = new String(' ', columnSize - 1);
            string columnRow = $"XX:{space}{1}{space}{2}{space}{3}{space}";
            string headerRow = "XX:0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF".Substring(0, length+3);
            disk.Add(columnRow);
            disk.Add(headerRow);
            string diskHeader = CreateDiskHeader(name, length);
            disk.Add(diskHeader);
            CreateDiskContent(disk, size, length);
            disk.ForEach(r => Console.WriteLine(r));
        }

        private string CreateDiskHeader(string name, int length)
        {
            byte[] ba = Encoding.Default.GetBytes(name);
            var hexString = BitConverter.ToString(ba);
            hexString = hexString.Replace("-", "");
            string header = $"00:0010000{hexString}";
            if (length - header.Length + 3 < 0)
                header = header.Substring(0, length+3);
            else
                header = header + new String('0', length - header.Length + 3);
            return header;
        }

        private void CreateDiskContent(List<string> disk, int size, int length)
        {
            for (int i = 1; i < size; i++)
            {
                string rowIndex = "00" + i.ToString("X");
                rowIndex = rowIndex.Substring(rowIndex.Length - 2);
                string nextIndex = "00";
                if (i != size - 1)
                {
                    nextIndex = nextIndex + (i + 1).ToString("X");
                    nextIndex = nextIndex.Substring(nextIndex.Length - 2);
                }
                string row = $"{rowIndex}:1{nextIndex}{new String('0', length - 3)}";
                disk.Add(row);
            }
        }
      
    }
}