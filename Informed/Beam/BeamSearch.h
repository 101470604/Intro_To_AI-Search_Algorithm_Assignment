#pragma once
#include "../../Base_Classes/InformedSearch.h"
class BeamSearch :
	public InformedSearch
{

protected:
	void prune(list<Tile> &flist, int beamWidth);
public:
	BeamSearch(char filename[], bool visualize, bool performanceCheck);
	~BeamSearch();

	void search() override;
};

