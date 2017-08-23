using System.Threading.Tasks;
using System.Diagnostics;
using System;

class Program
{
    static void Main(string[] args)
    {
        Console.Write("Cores: ");
        int cores = Convert.ToInt32(Console.ReadLine());
        double[] result = new double[cores];
        var watch = Stopwatch.StartNew();
        double sum = 0;
        Parallel.For(0, cores, (i) =>                                                   // Asynchronous execution
        {
            sum += Integrate(x => Math.Sin(x), 10000000, (i * Math.PI) / cores, ((i + 1) * Math.PI) / cores);
            Console.WriteLine("Area {0} : Sum {1}", i, sum);
        });
        Console.WriteLine("Parallel Elapsed time: {0} ", watch.ElapsedMilliseconds);
        long parallelTime = watch.ElapsedMilliseconds;

        watch = Stopwatch.StartNew();
        sum = 0;
        for (int i = 0; i < cores; i++)                                                // Synchronous execution
        {
            sum += Integrate(x => Math.Sin(x), 10000000, (i * Math.PI) / cores, ((i + 1) * Math.PI) / cores);
            Console.WriteLine("Area {0} : Sum {1}", i, sum);
        };
        Console.WriteLine("Serial Elapsed time: {0} ", watch.ElapsedMilliseconds);
        Console.WriteLine("Serial/Parallel time: {0} ", (double)watch.ElapsedMilliseconds / parallelTime);
    }

    public static double Integrate(Func<double, double> f, int n, double a, double b)
    {
        double deltax = (b - a) / n;
        double result = f(a) / 2 + f(a + deltax * n) / 2;
        for (int i = 1; i < n; i++)
        {
            result += f(deltax * i + a);
        }
        return result * deltax;
    }
}