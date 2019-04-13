//Justin Butler

//using System;
//using System.Text;
//using System.Collections.Generic;
//using VertexMap = System.Collections.Generic.Dictionary<int, string>;
#include <Wrapper.h>

class GraphUtility
{
	public:
		GraphUtility() {

		}
		~GraphUtility() {

		}
		//void LoadGraphData(string filename, VertexMap vertexLabels, ref int[, ] graphRep)
		//	// Loads the graph data from fileName into vertexLabels and graphRep
		//{
		//	int numberOfVertices = 0;
		//	string line;

		//	// Read the file and display it line by line.  
		//	System.IO.StreamReader file =
		//		new System.IO.StreamReader(filename);

		//	// Read in the number of vertices in matrix and initialize graphRep
		//	if ((line = file.ReadLine()) != null)
		//	{
		//		// read number of vertices
		//		numberOfVertices = Int32.Parse(line);

		//		// Initialize adjacency matrix
		//		graphRep = new int[numberOfVertices, numberOfVertices];
		//		for (int row = 0; row < numberOfVertices; row++)
		//		{
		//			for (int col = 0; col < numberOfVertices; col++)
		//			{
		//				graphRep[row, col] = 0;
		//			} // end for
		//		} // end for
		//	} // end if

		//	// Load all the vertex labels into vertexLabels
		//	for (int v = 0; v < numberOfVertices; v++)
		//	{
		//		line = file.ReadLine();
		//		vertexLabels.Add(v, line);
		//	} // end for

		//	// Load all the edges into graphRep
		//	while ((line = file.ReadLine()) != null)
		//	{
		//		int sourceVertex, targetVertex;
		//		sourceVertex = Int32.Parse(line);
		//		if ((line = file.ReadLine()) != null)
		//		{
		//			targetVertex = Int32.Parse(line);
		//			// Add edge
		//			graphRep[sourceVertex, targetVertex] = 1;
		//			graphRep[targetVertex, sourceVertex] = 1;
		//		} // end if
		//	} // end while
		//	file.Close();
		//} // loadGraphData

		//public void DisplayVertexLabels(VertexMap vertexLabels)
		//	// ensures vertexLabels = #vertexLabels
		//	// Uses Console.Write and .Writeline to display contents of vertexLabels
		//	// in the format shown in the sample output
		//{
		//	foreach(KeyValuePair<int, string> kvp in vertexLabels)
		//	{
		//		wcout << "Key = {0}, Value = {1}", kvp.Key, kvp.Value);
		//	} // end foreach
		//} // DisplayVertexLabels

		//public void DisplayGraphUsingLabels(VertexMap vertexLabels, int[, ] graphRep)
		//	// ensures vertexLabels = #vertexLabels and graphRep= #graphRep
		//	// Uses Console.Write and .Writeline to display contents of graphRep
		//	// in the format shown in the sample output
		//{
		//	int numberOfVertices = vertexLabels.Count;
		//	wcout << "(");
		//	wcout << "{");
		//	for (int v = 0; v < numberOfVertices; v++)
		//	{
		//		wcout << vertexLabels[v]);
		//		if ((v + 1) < numberOfVertices)
		//		{
		//			wcout << ",");
		//		} // end if
		//	} // end for
		//	wcout << "}");
		//	wcout << ",");
		//	wcout << "{");

		//	int edgeCount = 0;
		//	for (int row = 0; row < numberOfVertices; row++)
		//	{
		//		for (int col = row; col < numberOfVertices; col++)
		//		{
		//			if (graphRep[row, col] == 1)
		//			{
		//				if (edgeCount > 0)
		//				{
		//					wcout << ",");
		//				} // end if
		//				wcout << "{" + vertexLabels[row] + "," + vertexLabels[col] + "}");
		//				edgeCount++;
		//			} // end if
		//		} // end for
		//	} // end for
		//	wcout << "}";
		//	wcout << ")";
		//} // DisplayGraphUsingLabels

		//public void ToString(int[, ] graphRep)
		//	// ensures graphRep= #graphRep and 
		//	//         graphRep is output in adjacency matrix format
		//{
		//	int numberOfVertices = graphRep.GetLength(0);
		//	for (int row = 0; row < numberOfVertices; row++)
		//	{
		//		for (int col = 0; col < numberOfVertices; col++)
		//		{
		//			wcout << ("{0,-2}", graphRep[row, col]);
		//		} // end for
		//		wcout << '\n';
		//	} // end for           
		//} // ToString
};