#include "GhostAI.h"

AI::~AI(){}

std::pair<int, int> AI::AIPackage(TileMap* map, int const & currentX, int const & currentY, int const & targetX, int const & targetY, int const & ghostType, int const & ghostDirection, int const & mode) {

	rowMove[0] = -1, rowMove[1] = 0, rowMove[2] = 0, rowMove[3] = 1;
	colMove[0] = 0, colMove[1] = -1, colMove[2] = 1, colMove[3] = 0;

	gPath.clear();

	cX = currentX;
	cY = currentY;

	//Gives the option to change AI package mid game
	if (ghostType != 0) {
		gType = ghostType;
	}

	// Determines which ghost package will be used Blinky = 1, Pinky = 2, Inky = 3, Clyde = 4 and all other numbers
	switch (gType) {
	case 1:
		Blinky(map, targetX, targetY, ghostDirection, mode);
		break;
	case 2:
		Pinky(map, targetX, targetY, ghostDirection, mode);
		break;
	case 3:
		Inky(map, targetX, targetY, ghostDirection, mode);
		break;
	case 4:
		Clyde(map, targetX, targetY, ghostDirection, mode);
		break;
	default:
		std::cout << "Incorrect Ghost Types, using Clyde Instead..." << std::endl;
		Clyde(map, targetX, targetY, ghostDirection, mode);
		break;
	}

	return target;
}

//! Blinky will always target the player, and will find the shortest path to the players current tile
void AI::Blinky(TileMap * map, int const& targetX, int const& targetY, int const & gDir, int const & mode) {

	switch (mode) {
	case 1:
		tX = targetX;
		tY = targetY;
		break;
	case 2:
		tX = map->getCols()-3;	//Targets the top right corner;
		tY = 2;
		break;
	case 3:
		tX = map->getCols()-3;	//Targets the top right corner;
		tY = 2;
		break;
	case 4:
		tX = 14;
		tY = 12;
		break;
	}
	

	shortestPath(map);

	target.first = gPath[1].x;
	target.second = gPath[1].y;
}	

//! Pinky will target the tiles in front of the player in an attempt to ambush them.
void AI::Pinky(TileMap * map, int const& targetX, int const& targetY, int const & pDir, int const& mode) {

}		

//! Inky will look to cut off the players escape by targeting the tile behind the player
void AI::Inky(TileMap * map, int const& targetX, int const& targetY, int const & pDir, int const& mode) {

}		

//! Clyde will chase the player, until he gets to close and goes back to his corner of the map...
void AI::Clyde(TileMap * map, int const& targetX, int const& targetY, int const & pDir, int const& mode) {

}

void AI::shortestPath(TileMap * map) {

	//Graph is un-weighted

	//std::cout << "HERE Init" << std::endl;

	std::queue<Node> bfsQ;		//BFS Queue
	std::set<Node> visited;		//A set of visited Nodes
	Node srcN = { cX, cY };		//Source Node
	Node destN = { tX, tY };	//Destination Node

	int heuristic = sqrt(pow((cX - tX), 2) + pow((cY - tY), 2));	//Euclidean distance from source to target
	
	bfsQ.push(srcN);

	visited.insert(srcN);

	//std::cout << "HERE After Definition " << srcN.x << " " << srcN.y << " | " << destN.x << " " << destN.y << std::endl;

	//Loop until bfsQ is empty
	while (!bfsQ.empty()) {

		//std::cout << "HERE Search Loop" << std::endl;

		//Pop front node
		Node curr = bfsQ.front();	//Get first item in Queue
		bfsQ.pop();

		int i = curr.x;
		int j = curr.y;

		//If the current node is the target node
		if (i == destN.x && j == destN.y) {
			//std::cout << "HERE Print" << std::endl;
			getPath({ curr });
			return;
		}

		//Test the four traversal options (Up, Down, Left, Right)
		for (int k = 0; k < 4; k++) {
			
			//std::cout << "HERE Tile Test" << std::endl;
			
			int x = i + rowMove[k];
			int y = j + colMove[k];

			//std::cout << x << " " << y << std::endl;

			if (validPos(x, y, map)) {
				
				//std::cout << "Valid Check" << std::endl;

				int newH = sqrt(pow((x - tX), 2) + pow((y - tY), 2));
				
				Node next = { x, y, {curr} };

				if (!visited.count(next)) {

					bfsQ.push(next);
					visited.insert(next);
					heuristic = newH;
				}
			}
		}

	}

}

void AI::getPath(std::vector<Node> path) {
	if (path.size() == 0) {
		return;
	}

	getPath(path[0].parent);
	gPath.push_back(Node{path[0].x, path[0].y});
	return;
}

bool AI::validPos(int const & i, int const & j, TileMap * map) {
	
	int n = map->getMapVal(i, j);

	if (n != 7 && n != 16 && n != 15) {
		return false;
	}

	return (j >= 0 && j < map->getRows()) && (i >= 0 && i < map->getCols());
}