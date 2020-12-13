#include "BeamSearch.h"

// Removes 
void BeamSearch::prune(list<Tile>& flist, int beamWidth)
{
	Tile highest;
	highest.cost = numeric_limits<int>::max();
	list<Tile>::iterator position;

	flist.sort(); // See Tile::operator< in SearchAlgorithm.cpp

	while (flist.size() > beamWidth)
	{
		flist.pop_back(); // Lowest elements will be at the end, get rid of them	
	}
}

BeamSearch::BeamSearch(char filename[], bool visualize, bool performanceCheck) : InformedSearch(filename, visualize, performanceCheck)
{
}


BeamSearch::~BeamSearch()
{
}

/*
	In beam search a list of all possibilities are kept, same as breadth first search.
	HOWEVER only a specified number of the BEST children are kept after each expansion.
	This number is called the beam width
*/
void BeamSearch::search()
{
	list <Tile> bestNodesToVisit; // Holds the BEST grandchild of each child node visited
	Coordinate parent;
	int beamWidth;

	bestNodesToVisit.push_back(currentPosition); // Set the first tile so we have a starting point

	//cout << "Please specify the beam width: " << endl;
	//cin >> beamWidth;
	beamWidth = 9;
	

	while (!goalReached() && !bestNodesToVisit.empty())
	{
		if (createVisualisation)
		{
			visualize();
		}

		currentPosition = bestNodesToVisit.back();
		bestNodesToVisit.pop_back();

		if (!hasBeenVisited(currentPosition))
		{
			// We aren't going to revisit nodes, nodes therefore go to front of list
			visited.push_back(currentPosition); 
			parent.x = currentPosition.x;
			parent.y = currentPosition.y;

			for (int i = 0; i < 4; i++) // Try each direction
			{
				// Checking is done individually so that once the goal state is reached it is
				// appended to visited
				if (moveIsValid(currentPosition, (Direction)i)) 
				{
					currentPosition.cost = getCost((Direction)i);
					moveForward((Direction)i);

					currentPosition.parent = parent; // set the parent so we can trace a path
					bestNodesToVisit.push_back(currentPosition);

					moveBackward((Direction)i);
				}
			}	
			prune(bestNodesToVisit, beamWidth);
			// Track how many nodes are looked at by each algorithm
			tilesVisited++;
		}
	}

	if (goalReached())
	{
		createPath();
	}


}


