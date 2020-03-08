using System;
using System.Collections.Generic;
using System.Threading;

namespace P_04
{
    class Program
    {
        private static CubbyHole c1;
        private static CubbyHole c2;
        private static string pName;
        private static string c1Name;
        private static string c2Name;
        public static void ProducerProc() {
            Producer p = new Producer(c1, c2, pName);
            p.run();
        }
        public static void ConsumerOneProc() {
            Consumer c = new Consumer(c1, c1Name);
            c.run();
        }
        public static void ConsumerTwoProc() {
            Consumer c = new Consumer(c2, c2Name);
            c.run();
        }
        
        static void Main(string[] args)
        {
            pName = args[0];
            c1Name = args[1];
            c2Name = args[2];
            c1 = new CubbyHole();
            c2 = new CubbyHole();
            Thread producer = new Thread(ProducerProc);
            Thread consumer1 = new Thread(ConsumerOneProc);
            Thread consumer2 = new Thread(ConsumerTwoProc);
            producer.Name = args[0];
            consumer1.Name = args[1];
            consumer2.Name = args[2];
            producer.Start();
            consumer1.Start();
            consumer2.Start();
            producer.Join();
            consumer1.Join();
            consumer2.Join();
            Console.WriteLine("the end");
        }
    }

    class Producer
    {
        private CubbyHole c1;
        private CubbyHole c2;
        private string name;

        public Producer(CubbyHole c1, CubbyHole c2, string name)
        {
            this.c1 = c1;
            this.c2 = c2;
            this.name = name;
        }

        public void run()
        {
            var vowels = new HashSet<char> { 'a', 'e', 'i', 'o', 'u' };
            string line = Console.ReadLine();
            Console.WriteLine($"Thread {name} read: {line}");
            foreach (var character in line)
            {
                if (vowels.Contains(character))
                    c1.Put(character);
                else
                    c2.Put(character);
            }
            c1.Put('.');
            c2.Put('.');
            c1.kill = true;
            c2.kill = true;
        }
    }

    class Consumer
    {
        private CubbyHole c;
        private int received;
        private string characters;
        private string name;
        public Consumer(CubbyHole c, string name)
        {
            this.c = c;
            this.name = name;
            
        }

        public void run()
        {
            while (!c.kill)
            {
                char character = c.Get();
                Console.WriteLine($"Thread {name} received: {character}");
                received++;
                characters += character;
            }
            Console.WriteLine($"Thread {name} Number Received: {received} characters");
            Console.WriteLine($"Thread {name} Characters: {characters}");
        }
    }
    
    class CubbyHole {
        private char contents;
        private bool available;
        public bool kill;

        public char Get() {
            while (!available) {
                Thread.Sleep(0);
            }
            available = false;
            return contents;
        }

        public void Put(char value) {
            while (available) {
                Thread.Sleep(0);
            }
            contents = value;
            available = true;
        }
    }

}