#include "AStar.h"


AStar::AStar(char filename[], bool visualize, bool performanceCheck) : InformedSearch(filename, visualize, performanceCheck)
{
}


AStar::~AStar()
{
}

Tile AStar::getLowestCostTile(list<Tile> flist) 
{
	flist.sort();

	while (hasBeenVisited(flist.front()))
	{
		flist.pop_front();
	}

	return flist.front();
}

void AStar::search()
{
	list <Tile> nodesToVisit;
	visited.push_back(currentPosition);

	while (!goalReached() && validMoveExists(currentPosition))
	{
		if (createVisualisation)
		{
			visualize();
		}

		Coordinate parent;// Old tile will be new tiles parent
		
		parent.x = currentPosition.x;
		parent.y = currentPosition.y;

		for (int i = 0; i < 4; i++)
		{
			if (moveIsValid(currentPosition, (Direction)i))
			{
				// Get the adjacent node
				moveForward((Direction)i);

				// Mark the adjacent node as visited
				currentPosition.parent = parent;
				// Set the cost of the node
				currentPosition.cost = getDistanceFromGoal(currentPosition);

				nodesToVisit.push_back(currentPosition);

				// Reset to check other adjacent nodes
				moveBackward((Direction)i);
			}
		}
		currentPosition = getLowestCostTile(nodesToVisit);

		visited.push_back(currentPosition);

		tilesVisited++; // Track how many nodes 
	}
	
	createPath();
}