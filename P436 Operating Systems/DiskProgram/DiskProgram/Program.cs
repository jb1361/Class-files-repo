using System;
using P_08;

namespace P_08
{
   internal class Program
    {
        private static string version = "1.1";
        
        static void Main(string[] args)
        {
            if (args.Length == 0)
            {
                PrintHelp();
                return;
            }
            DiskParser parser = new DiskParser();
            int i = 0;
            string fileToPrint = "";
            foreach (var arg in args)
            {
                try
                {
                    if (arg == "-f")
                    {
                        parser.ReadVolumeFromFile(args[i + 1]);
                    }
                    if (arg == "-type")
                    {
                        fileToPrint = args[i + 1];
                    }
                    i++;
                }
                catch (IndexOutOfRangeException e)
                {
                    Console.WriteLine("No file Provided.");
                }
            }
            foreach (var arg in args)
            {
                ParseArgument(arg, parser);
            }
            if(fileToPrint != "") 
                PrintFileContent(parser, fileToPrint);
        }

        private static void PrintFiles(DiskParser parser)
        {
            if (!parser.DataRead)
            {
                parser.ReadDiskFromStandardInput();
            }
            Console.WriteLine("\n\nFiles");
            parser.PrintFileList();
        }
        
        private static void PrintFileContent(DiskParser parser, string fileName)
        {
            if (!parser.DataRead)
            {
                parser.ReadDiskFromStandardInput();
            }
            parser.PrintFileContents(fileName);
        }

        static void ParseArgument(string argument, DiskParser parser)
        {
            switch (argument)
            {
                case "-dir":
                    PrintFiles(parser);
                    break;
                case "-v":
                    PrintVersion();
                    break;
                case "-V":
                    PrintVersion();
                    break;
                case "-h":
                    PrintHelp();
                    break;
                case "-H":
                    PrintHelp();
                    break;
                case "-?":
                    PrintHelp();
                    break;
            }
        }

        private static void PrintVersion() => Console.WriteLine($"Version {version}");
        private static void PrintHelp() => Console.WriteLine("Arguments\n" +
                                                             "-v | -V : Prints the Version\n" +
                                                             "-h | -H | -? : Prints available arguments\n" +
                                                             "-type : Prints the file contents\n" +
                                                             "-f [file path] : Specifies file to read, uses stdIn otherwise\n" +
                                                             "-dir : Prints file list\n");
    }
}