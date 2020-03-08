using System;

namespace P_07
{
    class Program
    {
        static void Main(string[] args)
        {
            DiskWriter writer = new DiskWriter();
            writer.CreateDisk(args[0], Convert.ToInt32(args[1]), Convert.ToInt32(args[2]));
        }
    }
}