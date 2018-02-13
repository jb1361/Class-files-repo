using System;
namespace P2
{
    // This enum is based on the colors used by Cormen's DFS algorithm
    // in Chapter 22.3

    // The colors keep track of the state of the vertex:
    // white = unvisited
    // gray  = visited and currently being search
    // black = visited and finished being searched

    public enum VertextColor
    {
        white = 0, 
        gray = 1, 
        black = 2
    }
}
