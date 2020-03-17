using System;
using P_03;

namespace P_05
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
            foreach (var arg in args)
            {
                try
                {
                    if (arg == "-f")
                    {
                        parser.ReadDiskFromFile(args[i + 1]);
                    }

                    i++;
                }
                catch (IndexOutOfRangeException e)
                {
                    Console.WriteLine("No file Provided.");
                }
            }

            if (parser.DataRead)
            {
                if (!parser.CheckMalformedDisk())
                {
                    Console.WriteLine("Disk is Malformed.");
                    return;
                }
            }

            foreach (var arg in args)
            {
                ParseArgument(arg, parser);
            }
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
                                                             "-f [file path] : Specifies file to read, uses stdIn otherwise\n" +
                                                             "-dir : Prints file list\n");
    }
}