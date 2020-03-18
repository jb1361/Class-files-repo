using System;
using System.IO;
using NUnit.Framework;
using Disk_Program;

namespace DiskProgramTests
{
    public class Tests
    {
        [SetUp]
        public void Setup()
        {
        }

        [Test]
        public void FileNoFileFound()
        {
            using (var consoleOutput = new ConsoleOutput())
            {
                DiskProgram program = new DiskProgram();
                program.ReadFile("invalidFileLocation");
                Assert.AreEqual("File Does Not Exist\r\n", consoleOutput.GetOuput());
            }
        }
        [Test]
        public void ValidFileRead()
        {
            using (var consoleOutput = new ConsoleOutput())
            {
                DiskProgram program = new DiskProgram();
                program.ReadFile("./TestData/IUS.dat");
                Assert.AreNotEqual("File Does Not Exist\r\n", consoleOutput.GetOuput());
            }
        }
        [Test]
        public void InValidFileRead()
        {
            using (var consoleOutput = new ConsoleOutput())
            {
                DiskProgram program = new DiskProgram();
                program.ReadFile("./TestData/malformed.txt");
                Assert.AreEqual("", consoleOutput.GetOuput());
            }
        }
    }
}