#pragma once
#include "SearchAlgorithm.h"
class InformedSearch :
	public SearchAlgorithm
{
protected:
	int getCost(Direction direction);
	int getDistanceFromGoal(Tile tile);
	int shortestDistance, currentCost;
public:
	InformedSearch(char filename[], bool visualize, bool performanceCheck);
	~InformedSearch();
};

