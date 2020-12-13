#pragma once
#include "../../Base_Classes/SearchAlgorithm.h"
class BreadthFirstSearch :
	public SearchAlgorithm
{
public:
	BreadthFirstSearch(char filename[], bool visualize, bool performanceCheck);
	~BreadthFirstSearch();

	void search() override;
};

