#include "GreedyBestFirstSearch.h"

GreedyBestFirstSearch::GreedyBestFirstSearch(char fileName[], bool visualize, bool performanceCheck) : InformedSearch(fileName, visualize, performanceCheck)
{

}

GreedyBestFirstSearch::~GreedyBestFirstSearch()
{
}



/*
	GBFS works by always picking the CHEAPEST move, and NEVER revising. This means it can get stuck,

*/
void GreedyBestFirstSearch::search()
{
	int lowestCost, currentCost, largeNumber;
	largeNumber = gridWidth * gridHeight; // initial val needs to be larger than grid or it may not move
	Direction nextMove = up;

	while (!goalReached() && validMoveExists(currentPosition))
	{
		if (createVisualisation)
		{
			visualize();
		}

		lowestCost = largeNumber;
		currentCost = 0;

		for (int i = 0; i < 4; i++) // Try each direction
		{

			if (moveIsValid(currentPosition, (Direction)i)) // Dont move through walls or off the grid
			{
				currentCost = getCost((Direction)i);

				if (currentCost < lowestCost) // Choose the move with the lowest cost
				{
					lowestCost = currentCost;
					nextMove = (Direction)i;
				}
			}
		}
		visited.push_back(currentPosition);
		path.push_back(nextMove);
		moveForward(nextMove); 
	//	visualize();
		// Track how many nodes are looked at by each algorithm
		tilesVisited++;
	}

//	visualize();

	if (!goalReached())
	{
		path.clear(); // Empty the path so the print path method prints: "no path found"
	}
}
