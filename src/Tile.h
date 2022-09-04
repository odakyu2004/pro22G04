/* Tile.h
 *
 * Copyright (C), 2022, S3-04班
 */

#ifndef _SRC_TILE_H_
#define _SRC_TILE_H_

class PlayerBot;

class Tile {
private:
	Tile * north;
	Tile * south;
	Tile * east;
	Tile * west;
	Tile * warp;
	PlayerBot * bot;
	Tile * flag;
public:
	Tile();
	virtual ~Tile();
	int proc;
	void setNorth(Tile * north) { this->north = north; }
	Tile * getNorth(void ) { return north; }
	void setSouth(Tile * south) { this->south = south; }
	Tile * getSouth(void ) { return south; }
	void setEast(Tile * east) { this->east = east; }
	Tile * getEast(void ) { return east; }
	void setWest(Tile * west) { this->west = west; }
	Tile * getWest(void ) { return west; }
	void setWarp(Tile * warp) { this->warp = warp; }
	Tile * getWarp(void ) { return warp; }
	void setPlayerBot(PlayerBot * bot) { this->bot = bot; }
	PlayerBot * getPlayerBot(void ) { return bot; }
	void setFlag(Tile * flag){this->flag = flag;}
	Tile * getFlag(void) {return flag;}
};

#endif /* _SRC_TILE_H_ */
