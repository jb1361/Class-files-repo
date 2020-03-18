using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using System.CommandLine;
using System.CommandLine.Invocation;
using System.IO;
using System.Linq;
using System.Reflection;

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
      
    }
}