#pragma once
#include "../../Base_Classes/SearchAlgorithm.h"
class DepthFirstSearch : public SearchAlgorithm
{
private:
	
public:
	DepthFirstSearch(char filename[], bool visualize, bool performanceCheck);
	~DepthFirstSearch();
	void search() override;
};

