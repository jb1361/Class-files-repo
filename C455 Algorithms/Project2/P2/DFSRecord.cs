using System;
using System.Text;

namespace P2
{
    public class DFSRecord
    {
        // DFSRecord - based on the attributes that Cormen associates
        //             with each vertex in Chapter 22.3's DFS algorithm
        // The attributes in 22.3 are: color, d, f, pi
        // In the record below:
        //    color = color
        //        d = discoveryTime
        //        f = finishingTime
        //       pi = predecessor

        // DFSRecord is modeled by (
        //      color: finite set of {while, gray, black}
        //      discoveryTime: int
        //      finishingTime: int
        //      predecessor: int
        //   )
        // exemplar self 

        public VertextColor color;
        public int discoveryTime;
        public int finishingTime;
        public int predecessor;
        private const int NIL = -1;

        public DFSRecord()
        // updates self
        // ensures self = (white, 0, 0, NIL)
        {
            color = VertextColor.white;
            discoveryTime = 0;
            finishingTime = 0;
            predecessor = NIL;
        }

        public void Clear()
        // updates self
        // ensures self = (white, 0, 0, NIL)
        {
            color = VertextColor.white;
            discoveryTime = 0;
            finishingTime = 0;
            predecessor = NIL;
        } // clear

        public override string ToString()
        {
            StringBuilder predecessorString = new StringBuilder((predecessor == NIL) ? "NIL" : "" + predecessor);
            
            StringBuilder sb = 
                new StringBuilder("(" + color + "," + 
                                  discoveryTime + "," + 
                                  finishingTime + "," + 
                                  predecessorString.ToString() 
                                  + ")");
            return sb.ToString();
        } // ToString
    }
}
