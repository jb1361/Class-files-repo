using System;
using System.Linq;

namespace P_03
{
    class Program
    {
        private static string version = "1";
        
        static void Main(string[] args)
        {
            if (args.Length > 1)
            {
                Console.WriteLine("Only one argument allowed");
                return;
            }

            if (args.Length == 1)
            {
                ParseArgument(args[0]);
                return;
            }
            DiskParser parser = new DiskParser();
            parser.ReadDisk();
            Console.WriteLine("\n\nDisk Contents\n");
            parser.PrintDiskContents();
            Console.WriteLine("\n\nDisk Contents With Headers And Indexes\n");
            parser.PrintDisk();
        }

        static void ParseArgument(string argument)
        {
            switch (argument)
            {
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

        private static void PrintVersion() => Console.WriteLine(version);
        private static void PrintHelp() => Console.WriteLine("Arguments\n" +
                                                             "v|V - Prints the Version\n" +
                                                             " h | H | ? - Prints available arguments\n");
    }
}