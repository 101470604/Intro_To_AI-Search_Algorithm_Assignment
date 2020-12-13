#pragma once
#include "../../Base_Classes/InformedSearch.h"
class GreedyBestFirstSearch :
	public InformedSearch
{
public:
	GreedyBestFirstSearch(char fileName[], bool visualize, bool performanceCheck);
	~GreedyBestFirstSearch();

	void search() override;
};

