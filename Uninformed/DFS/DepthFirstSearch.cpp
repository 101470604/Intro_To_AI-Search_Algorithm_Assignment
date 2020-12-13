#include "DepthFirstSearch.h"

DepthFirstSearch::DepthFirstSearch(char fileName[], bool visualize, bool performanceCheck) : SearchAlgorithm(fileName, visualize, performanceCheck)
{

}

DepthFirstSearch::~DepthFirstSearch()
{
}

void DepthFirstSearch::search()
{
	if (createVisualisation)
	{
		visualize();
	} 

	// Track how many nodes are looked at by each algorithm
	tilesVisited++;

	// Mark current block as visited
	visited.push_back(currentPosition);
	// IF used instead of IF-ELSE so that each instance of the method call will attempt

	// Try to move in each direction AT LEAST once.
	if (moveIsValid(currentPosition, Direction::up))
	{
		moveUp();
		path.push_back(Direction::up);
		search();
	}

	if (moveIsValid(currentPosition, Direction::left))
	{
		moveLeft();
		path.push_back(Direction::left);
		search();
	}

	if (moveIsValid(currentPosition, Direction::down))
	{
		moveDown();
		path.push_back(Direction::down);
		search();
	}

	if (moveIsValid(currentPosition, Direction::right))
	{
		moveRight();
		path.push_back(Direction::right);
		search();
	}
	// No default needed as one MUST be true to execute this block

	if (!validMoveExists(currentPosition) &&!goalReached())
	{
		moveBackward(path.back());
		
		if (!path.empty()) // Prevents error if starting tile has no valid moves
		{
			path.pop_back();
		}
	}
}

