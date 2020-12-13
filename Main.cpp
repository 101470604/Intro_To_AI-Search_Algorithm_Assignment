// Assignment_1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <string>
#include <iostream>
#include <fstream>

#include "Main.h"
#include "Uninformed/DFS/DepthFirstSearch.h"
#include "Uninformed/BFS/BreadthFirstSearch.h"
#include "Informed/GBFS/GreedyBestFirstSearch.h"
#include "Informed/Beam/BeamSearch.h"
#include "Informed/A-Star/AStar.h"
#include "Base_Classes/InformedSearch.h"
#include "Base_Classes/SearchAlgorithm.h"

using namespace std;


int main(int argc, char *argv[])
{
	string search, filename, argument;
	bool visualize, performancecheck;

	search = (string)argv[1]; 
	search = "A*";
	filename = (string)argv[2];
	visualize = false;
	performancecheck = false;

	if (argc > 3)
	{
		for (int i = 3; i < argc; i++)
		{
			if ((string)argv[i] == "visualize")
			{
				visualize = true;
			}
			
			if ((string)argv[i] == "pcheck")
			{
				performancecheck = true;
			}
		}
	}

	cout << "Filename " <<  filename << endl;
	cout << "Search: " << search << endl;

	if (search == "DFS")
	{
		DepthFirstSearch* dfs = new DepthFirstSearch(argv[0], visualize, performancecheck);
		dfs->search();
		cout << "Depth First Search ";
		dfs->printPath();
	}
	else if (search == "BFS")
	{
		BreadthFirstSearch* bfs = new BreadthFirstSearch(argv[0], visualize, performancecheck);
		bfs->search();
		cout << "Breadth First Search ";
		bfs->printPath();
	}
	else if (search == "GBFS")
	{
		GreedyBestFirstSearch* gbfs = new GreedyBestFirstSearch(argv[0], visualize, performancecheck);
		gbfs->search();
		cout << "Greedy Best First Search ";
		gbfs->printPath();
	}
	else if (search == "A*")
	{
		AStar* AS = new AStar(argv[0], visualize, performancecheck);
		AS->search();
		cout << "A* ";
		AS->printPath();
	}
	else if (search == "BS")
	{
		BeamSearch* beamSearch = new BeamSearch(argv[0], visualize, performancecheck);
		beamSearch->search();
		cout << "Beam Search ";
		beamSearch->printPath();
	}
	else 
	{
		cout << "Invalid method name" << endl;
	}


	


	
	

	

	

	


}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
