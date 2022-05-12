#include <iostream>
#include <bitset>
#include <array>
#include <vector>
#include <string>
#include <list>

#define TILE_NUM 3
#define WIDTH 10
#define HEIGHT 10

struct Tile{
	std::bitset<TILE_NUM> upChoice = 0b111;
	std::bitset<TILE_NUM> leftChoice = 0b111;
	std::bitset<TILE_NUM> downChoice = 0b111;
	std::bitset<TILE_NUM> rightChoice = 0b111;

	std::bitset<TILE_NUM> possibilities = 0b111;

	std::string text;

	int count = TILE_NUM;
};

struct Location{
	int x;
	int y;
};

enum Direction{
	up,
	left,
	down,
	right
};

std::array<Tile, TILE_NUM> tileSet {{{0b011, 0b011, 0b011, 0b011, 0b001, "G", 1},
									 {0b111, 0b111, 0b111, 0b111, 0b010, "B", 1},
									 {0b110, 0b110, 0b110, 0b110, 0b100, "S", 1}}};

std::list<Location> getLowestSet(std::array<std::array<Tile, WIDTH>, HEIGHT> grid){
	std::list<Location> lowestSet;
	int lowestCount = TILE_NUM;
	Tile currentTile;

	for(int i = 0; i < HEIGHT; i++){
		for(int j = 0; j < WIDTH; j++){
			currentTile = grid[i][j];

			if (currentTile.count < lowestCount && currentTile.count > 1){
				lowestSet = {{j, i}};
				lowestCount = currentTile.count;
			}
			else if (currentTile.count == lowestCount){
				lowestSet.push_back({j, i});
			}
		}
	}

	return lowestSet;
}

std::array<std::array<Tile, WIDTH>, HEIGHT> propagate(std::array<std::array<Tile, WIDTH>, HEIGHT> grid,
													  Location location,
													  Direction direction){
//TODO: Implement propagation algorithm
}

int main(){
	std::array<std::array<Tile, WIDTH>, HEIGHT> grid;
	srand(time(0));

	bool exit = false;
	std::list<Location> lowestSet;

	while(!exit){
		lowestSet = getLowestSet(grid);

		if(lowestSet.size() == 0){
			exit = true;
		}
		else{
			int location = rand() % lowestSet.size();
			std::list<Location>::iterator locator = lowestSet.begin();
			std::advance(locator, location);

			int choicePos = rand() % TILE_NUM;
			Location choice = *locator;

			grid[choice.y][choice.x] = tileSet[choicePos];
		}
	}

	return 0;
}
