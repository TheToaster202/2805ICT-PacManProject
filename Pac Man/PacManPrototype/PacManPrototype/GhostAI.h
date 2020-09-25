#pragma once

#include "TileMap.h"

#include <queue>
#include <vector>
#include <set>

/// <summary>
/// A class that will decide the next move for a ghost, the class will accept the ghosts current postion and the target tile and will output the tile the ghost will move to.
/// </summary>

struct Node {
	int x, y;

	std::vector<Node> parent;

	bool const operator==(const Node& ob) const {
		return x == ob.x && y == ob.y;
	}

	bool operator<(const Node& ob) const {
		return x < ob.x || (x == ob.x && y < ob.y);
	}

};

class AI{
public:

	AI() : cX(0), cY(0), tX(0), tY(0), gType(0){};
	~AI();

	std::pair<int, int> AIPackage(TileMap* map, int const& currentX, int const& currentY, int const& targetX, int const& targetY, int const & ghostType, int const & playerDirection, int const & ghostDirection);	//! Method that will decide which AI package to run and will return the next postion

private:

	void Blinky(TileMap* map, int const & targetX, int const & targetY, int const & pDir);		//! Blinky's movement algorithm
	void Pinky(TileMap * map, int const& targetX, int const& targetY, int const & pDir);		//! Pinky's movement algorithm
	void Inky(TileMap * map, int const& targetX, int const& targetY, int const & pDir);		//! Inky's movement algorithm
	void Clyde(TileMap * map, int const& targetX, int const& targetY, int const & pDir);		//! Clydes's movement algorithm

	Node shortestPath(TileMap * map);		//! Algorithm to find the shortest path to the target node, using dijkstra's algorithm
	bool validPos(int const & i, int const & j, TileMap * map);
	
	std::pair<int, int> target;

	int cX, cY;	//Current X and Y
	int tX, tY;	//Target X and Y, IE: player postion
	int gType;

	int rowMove[4] = {-1, 0, 0, 1};
	int colMove[4] = {0, -1, 1, 0};
};