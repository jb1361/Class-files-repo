using System;
using System.CommandLine;
using System.CommandLine.Invocation;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Threading.Tasks;

namespace Disk_Program
{
    internal static class Run
    {
        public static async Task<int> Main(params string[] args)
        {
            RootCommand rootCommand = new RootCommand("Reads, formats, and writes to a Flat disk file.");
            
            var versionOption = new Option<bool>(new [] { "-v", "-V", "--version" }, "Show version information");
            rootCommand.AddOption(versionOption);
            
            Option fileOption = new Option(new [] { "-f", "--f" }, "Provide input file") { Argument = new Argument<string>()};
            rootCommand.AddOption(fileOption);
            
            Option dirOption = new Option<bool>(new [] { "-dir", "--dir" }, "Prints all file on disk");
            rootCommand.AddOption(dirOption);
            
            
            rootCommand.Handler =
                CommandHandler.Create<string, bool, bool>(HandleArguments);
            
            if (args.Length == 0)
                args = new [] {"--help"};
            return await rootCommand.InvokeAsync(args);
        }

        private static void HandleArguments(string f, bool version, bool dir)
        {
            DiskProgram program = new DiskProgram();
            if (version) PrintVersion();
            if (f != null)
            {
                program.ReadFile(f);
            }

            if (dir && program.ContinueRunning)
            {
                program.PrintFiles();
            }    
        
        }
        
        private static void PrintVersion() => Console.WriteLine(Assembly.GetEntryAssembly()?.GetName().Version);

    }
}