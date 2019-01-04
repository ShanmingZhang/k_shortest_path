//============================================================================
// Name        : K-ShortestPath.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/************************************************************************/
/* $Id: MainP.cpp 65 2010-09-08 06:48:36Z yan.qi.asu $                                                                 */
/************************************************************************/

#include <limits>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "GraphElements.h"
#include "Graph.h"
#include "DijkstraShortestPathAlg.h"
#include "YenTopKShortestPathsAlg.h"

using namespace std;

void testDijkstraGraph(string fileName, int src, int dest) {
	Graph* my_graph_pt = new Graph(fileName);
	DijkstraShortestPathAlg shortest_path_alg(my_graph_pt);
	BasePath* result = shortest_path_alg.get_shortest_path(
			my_graph_pt->get_vertex(src), my_graph_pt->get_vertex(dest));
	result->PrintOut(cout);
}

void testYenAlg(string fileName, int src, int dest) {
	Graph my_graph(fileName);

	YenTopKShortestPathsAlg yenAlg(my_graph, my_graph.get_vertex(src),
			my_graph.get_vertex(dest));

	int i = 0;
	while (yenAlg.has_next()) {
		++i;
		cout << " The " << i << " th shortest path." << endl;
		yenAlg.next()->PrintOut(cout);
	}
}

int main(...)
{
	cout << "Welcome to the real world!" << endl;

	testDijkstraGraph("data/test_6_2", 0, 5);
	cout << " ----------------  " << endl;
	testYenAlg("data/test_6_2", 0, 5);
}
