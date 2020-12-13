#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <cmath>
#include <chrono>

using namespace std;

struct Coordinate {
	int x, y;
};

struct Tile {
	Coordinate parent;
	int x, y;
	int cost;

	bool operator<(const Tile& rhs) const; // Allows for list.sort to correctly order list
};

enum Direction {
	up, down, left, right
};

class SearchAlgorithm
{
protected:
	
	Tile currentPosition;
	int gridWidth, gridHeight, startX, startY, goalX, goalY, wallCount, tilesVisited;
	vector<vector<int>> wallData; 
	std::chrono::time_point<std::chrono::system_clock> start, end; // Holds the start & end time for algorithm execution
	bool createVisualisation, performanceCheck;
	
	list<Tile> visited; // List of visited nodes
	list<Direction> path;

	void readInFile(char filename[]);
	
	bool isWall(Tile tile);
	bool goalReached();
	bool validMoveExists(Tile tile);
	bool moveIsValid(Tile tile, Direction direction);
	bool hasBeenVisited(Tile tile);

	// The move functions are a conveinient way to alter the value of currentPosition
	void visualize();
	void moveForward(Direction direction); // Move in specified direction
	void moveBackward(Direction direction); // Move in opposite of specified direction
	void moveUp(); 
	void moveDown();
	void moveLeft();
	void moveRight();
	void createPath();
	
	virtual void search();

public:
	SearchAlgorithm(char filename[], bool visualize, bool performanceCheck);
	~SearchAlgorithm();
	void printPath();
};

