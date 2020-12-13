#include "BreadthFirstSearch.h"

BreadthFirstSearch::BreadthFirstSearch(char fileName[], bool visualize, bool performanceCheck) : SearchAlgorithm(fileName, visualize, performanceCheck)
{
	
}


BreadthFirstSearch::~BreadthFirstSearch()
{
	
}

void BreadthFirstSearch::search()
{
	visited.push_back(currentPosition);

	for (auto iter = visited.begin(); iter != visited.end() && !goalReached(); ++iter)
	{
		currentPosition = *iter;
		
		if (createVisualisation)
		{
			visualize();
		}

		if (validMoveExists(currentPosition))
		{
			Coordinate parent;// Old tile will be new tiles parent
			parent.x = currentPosition.x;
			parent.y = currentPosition.y;
			for (int i = 0; i < 4; i++) // Moves once in every direction from parent node
			{
				if (moveIsValid(currentPosition, (Direction)i)) // Try each direction
				{
					// Get the adjacent node
					moveForward((Direction)i); 

					// Mark the adjacent node as visited
					currentPosition.parent = parent;
					visited.push_back(currentPosition); 
					
					// Reset to check other adjacent nodes
					moveBackward((Direction)i);
				}
			}
		}
		// Track how many nodes are looked at by each algorithm
		tilesVisited++;
	}
	createPath(); // Path not yet populated by method
}

