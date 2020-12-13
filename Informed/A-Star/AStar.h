#pragma once
#include "../../Base_Classes/InformedSearch.h"
class AStar :
	public InformedSearch
{
protected:
	Tile getLowestCostTile(list<Tile> flist);

public:
	AStar(char filename[], bool visualize, bool performanceCheck);
	~AStar();

	void search() override;
};

