#include <iostream>
#include <bitset>
#include <array>
#include <string>

#define TILE_NUM 3
#define WIDTH 10
#define HEIGHT 10

struct {
	std::bitset<TILE_NUM> upChoice = 0b111;
	std::bitset<TILE_NUM> leftChoice = 0b111;
	std::bitset<TILE_NUM> downChoice = 0b111;
	std::bitset<TILE_NUM> rightChoice = 0b111;

	std::bitset<TILE_NUM> possibilities = 0b111;

	std::string text;
} Tile;

std::array<std::bitset<TILE_NUM>, TILE_NUM> upTable {{0b011, 0b111, 0b110}};
std::array<std::bitset<TILE_NUM>, TILE_NUM> leftTable {{0b011, 0b111, 0b110}};
std::array<std::bitset<TILE_NUM>, TILE_NUM> downTable {{0b011, 0b111, 0b110}};
std::array<std::bitset<TILE_NUM>, TILE_NUM> rightTable {{0b011, 0b111, 0b110}};

std::array<std::string, TILE_NUM> textTable {{"G", "B", "S"}};

int main(){


	return 0;
}
