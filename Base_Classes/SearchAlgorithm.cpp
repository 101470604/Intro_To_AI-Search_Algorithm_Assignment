#include "SearchAlgorithm.h"

#include "SearchAlgorithm.h"



/* CONSTRUCTOR */
SearchAlgorithm::SearchAlgorithm(char filename[], bool fvisualize, bool fperformanceCheck)
{
	createVisualisation = fvisualize;
	performanceCheck = fperformanceCheck;
	readInFile(filename); // Read in & generate the grid
	currentPosition.x = startX;
	currentPosition.y = startY;

	if (performanceCheck)
	{
		start = std::chrono::system_clock::now();
	}
	
}

/* DESTRUCTOR */
SearchAlgorithm::~SearchAlgorithm()
{
}

bool SearchAlgorithm::isWall(Tile tile)
{
	for (int i = 0; i < wallCount; i++)
	{
		int x_min, x_max, y_min, y_max;

		x_min = wallData[i][0]; // Starting X
		x_max = x_min + wallData[i][2]; // Starting Y
		y_min = wallData[i][1]; // Starting X + Wall Width
		y_max = y_min + wallData[i][3]; // Starting Y + Wall Height

		if (tile.x >= x_min && tile.x < x_max)
		{
			if (tile.y >= y_min && tile.y < y_max)
			{
				return true;
			}
		}
	}
	return false;
}

bool SearchAlgorithm::goalReached()
{
	if (currentPosition.x == goalX && currentPosition.y == goalY)
	{
		return true;
	}
	return false;
}

bool SearchAlgorithm::validMoveExists(Tile tile)
{
	if (moveIsValid(tile, Direction::up) ||
		moveIsValid(tile, Direction::left) ||
		moveIsValid(tile, Direction::down) ||
		moveIsValid(tile, Direction::right))
	{
		return true;
	}
	return false;
}

bool SearchAlgorithm::moveIsValid(Tile fTile, Direction direction)
{
	Tile tile = fTile;
	switch (direction)
	{
	case Direction::up:
		tile.y--;
		break;
	case Direction::down:
		tile.y++;
		break;
	case Direction::left:
		tile.x--;
		break;
	case Direction::right:
		tile.x++;
		break;
	default:
		return false; // Function should never execute if one of the above conditions isn't met
	}

	//	if (!goalReached())
	//	{
	if (tile.x >= 0 && tile.x < gridWidth)
	{
		if (tile.y >= 0 && tile.y < gridHeight)
		{
			if (!isWall(tile) && !hasBeenVisited(tile))
			{
				return true;
			}
		}
	}
	//	}
	return false;
}

bool SearchAlgorithm::hasBeenVisited(Tile tile)
{
	for (auto iter = visited.begin(); iter != visited.end(); iter++)
	{
		if (iter->x == tile.x && iter->y == tile.y)
		{
			return true;
		}
	}
	return false;
}

void SearchAlgorithm::visualize()
{
	string result;
	Tile tmp;
	for (int i = 0; i < gridWidth; i++)
	{
		result += "___";
	}
	result += "\n";


	for (tmp.y = 0; tmp.y < gridHeight; tmp.y++)
	{
		result += "|";
		for (tmp.x = 0; tmp.x < gridWidth; tmp.x++)
		{
			if (tmp.x == currentPosition.x && tmp.y == currentPosition.y)
				result += " P ";
			else if (isWall(tmp))
				result += " X ";
			else if (tmp.x == goalX && tmp.y == goalY)
				result += " G ";
			else if (hasBeenVisited(tmp))
				result += " * ";
			else
				result += "   ";
		}
		result += "|";
		result += "\n";
	}
	for (int i = 0; i < gridWidth; i++)
	{
		result += "___";
	}
	
	cout << "\r" << result << endl;
	
}

void SearchAlgorithm::moveForward(Direction direction)
{
	switch (direction)
	{
	case 0: moveUp();
		break;
	case 1: moveDown();
		break;
	case 2: moveLeft();
		break;
	case 3: moveRight();
		break;
	}
}

void SearchAlgorithm::moveBackward(Direction direction)
{
	switch (direction)
	{
	case 0: moveDown();
		break;
	case 1: moveUp();
		break;
	case 2: moveRight();
		break;
	case 3: moveLeft();
		break;
	}
}

void SearchAlgorithm::moveUp()
{
	currentPosition.y--;
}

void SearchAlgorithm::moveDown()
{
	currentPosition.y++;
}

void SearchAlgorithm::moveLeft()
{
	currentPosition.x--;
}

void SearchAlgorithm::moveRight()
{
	currentPosition.x++;
}

void SearchAlgorithm::search()
{
}


// Finds the text file with the specified name & location 
// & creates the grid from the data parsed in the file.
void SearchAlgorithm::readInFile(char filename[])
{
	// instead of parsing punctuation, correct file format is assumed & punctuation is
	// dumped into text string
	string text, sFilename; // used exclusively in getline methods
	ifstream gridFile;
	char character; // Junk text is funneled in here 
	wallCount = 0;

	sFilename = "test.txt";
	// Open the file, perform a check to see if it worked 
	// USE IN LIVE ENVIRONMENT
	 gridFile.open(sFilename);

	// USE FOR DEBUGGGING
	// gridFile.open("test.txt", ios::in);

	if (gridFile.is_open())
	{
		// Get the number of lines to define the vector 
		while (getline(gridFile, text))	
		{
			cout << text << endl;
			wallCount++;
		}
		gridFile.close();

		wallCount -= 3; // Walls are listed from the fourth line of the file onward
		
		if (wallCount >= 0)
		{
			
			// Make room in vector for as many lines in the file as needed
			wallData.resize(wallCount);

			for (int i = 0; i < wallCount; i++) // Make space in underlying vectors as well
			{
				wallData[i].resize(4);
			}

			// Reopen the file to scan from begginning
			gridFile.open(sFilename, ios::in);

			gridFile >> character >> gridHeight >> character >> gridWidth >> character; // Set the size of the grid
			gridFile >> character >> startX >> character >> startY >> character; // Set the start position
			gridFile >> character >> goalX >> character >> goalY; // Set the coordinates

			string line;
			getline(gridFile, line); // Skip the rest of the line, we  only need one goal for now

			for (int i = 0; i < wallCount; i++)
			{
				gridFile >> character >> wallData[i][0] >> character >> wallData[i][1] >> character >> wallData[i][2] >> character >> wallData[i][3] >> character;
			}

			/* PRINT OUT EVERYTHING FOR VALIDATION
			cout << "Width: " << gridWidth << endl;
			cout << "Height: " << gridHeight << endl;
			cout << "X: " << startX << endl;
			cout << "Y: " << startY << endl;
			cout << "Goal X: " << goalX << endl;
			cout << "Goal Y: " << goalY << endl;

			for (int i = 0; i < wallCount; i++)
			{
				cout << "Wall " << i << " X: " << wallData[i][0] << endl;
				cout << "Wall " << i << " Y: " << wallData[i][1] << endl;
				cout << "Wall " << i << " Width: " << wallData[i][2] << endl;
				cout << "Wall " << i << " Height: " << wallData[i][3] << endl;
			}
			*/
			gridFile.close();
		}
		else
		{
			cout << "Error: Invalid File Format" << endl;
		}
	}
	else {
		cout << "Error: File was unable to be opened" << endl;
	}
}

void SearchAlgorithm::printPath()
{
	cout << tilesVisited << endl;

	if (performanceCheck)
	{
		// Output the time taken to execute the search
		// Copied from https://stackoverflow.com/questions/11062804/measuring-the-runtime-of-a-c-code 
		end = std::chrono::system_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		cout << "Time elapsed: " << elapsed.count() << "ms" << endl;

	}

	
	if (path.empty())
	{
		cout << "No path found";
	}
	else
	{
		cout << "> ";

		for (auto iter = path.begin(); iter != path.end(); iter++)
		{
			Direction val = *iter;
			switch (val)
			{
			case Direction::up:
				cout << "up; ";
				break;
			case Direction::down:
				cout << "down; ";
				break;
			case Direction::left:
				cout << "left; ";
				break;
			case Direction::right:
				cout << "right; ";
				break;
			}

		}

	}
	
	cout << endl << endl;

}

// Works backwards from goal tile to start by following the trail of parent nodes
void SearchAlgorithm::createPath()
{
	while (currentPosition.x != startX || currentPosition.y != startY) // Exit once back at the start
	{
		Coordinate parent;
		parent = currentPosition.parent;

		// CHECK IF MOVE WAS UP
		if (parent.y == currentPosition.y + 1) // - 1 as parent moved + 1 to get to current position
		{
			path.push_front(Direction::up);
		}
		else if (parent.y == currentPosition.y - 1) // cheeck if move was DOWN
		{
			path.push_front(Direction::down);
		}
		else if (parent.x == currentPosition.x + 1) // check if move was LEFT
		{
			path.push_front(Direction::left);
		}
		else if (parent.x == currentPosition.x - 1)// check if move was RIGHT
		{
			path.push_front(Direction::right);
		}

		// Get the parent node for the next operation
		for (auto iter = visited.begin(); iter != visited.end(); iter++)
		{
			if (iter->x == parent.x && iter->y == parent.y)
			{
				currentPosition = *iter;
			}
		}
	} // End of while loop

}


bool Tile::operator<(const Tile & rhs) const
{
	return (this->cost < rhs.cost);
}
