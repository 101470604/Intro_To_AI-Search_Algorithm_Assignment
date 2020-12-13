#include "InformedSearch.h"
#include <limits>


InformedSearch::InformedSearch(char fileName[], bool visualize, bool performanceCheck) : SearchAlgorithm(fileName, visualize, performanceCheck)
{
	
}


InformedSearch::~InformedSearch()
{
}

int InformedSearch::getCost(Direction direction)
{
	int result;
	switch (direction)
	{
	case Direction::up:
		moveUp();
		result = getDistanceFromGoal(currentPosition);
		moveDown();
		break;
	case Direction::down:
		moveDown();
		result = getDistanceFromGoal(currentPosition);
		moveUp();
		break;
	case Direction::left:
		moveLeft();
		result = getDistanceFromGoal(currentPosition);
		moveRight();
		break;
	case Direction::right:
		moveRight();
		result = getDistanceFromGoal(currentPosition);
		moveLeft();
		break;
	default:
		break;
	}

	return result; // Result returned at end so move can be reversed
}

/*
	Greedy BFS is informed, meaning each vertice in the graph has a weight. The weight of each vertice is
	calculated using the euclidian formula for getting the distance between two points in a cartesian plane.
*/
int InformedSearch::getDistanceFromGoal(Tile tile)
{
	int xPair, yPair;

	xPair = pow((goalX - tile.x), 2);
	yPair = pow((goalY - tile.y), 2);

	return sqrt((xPair + yPair));
}