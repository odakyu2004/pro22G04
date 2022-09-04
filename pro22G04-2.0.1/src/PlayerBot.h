/* PlayerBot.h
 * Copyright (C), 2022, S3-04班
 */

#ifndef _SRC_PLAYERBOT_H_
#define _SRC_PLAYERBOT_H_
#include <string>
#include <queue>

using namespace std;

class Tile;
class Dungeon;

class PlayerBot {
private:
	string answer;
	Tile * currentLocation;
	Tile * start;
	Tile * goal;
	Tile * pro;
public:
	PlayerBot();
	virtual ~PlayerBot();
	int goal2;
	int proc2;
	int number;
	int branch;   	
	
	string * getAnswer(void ) { return & answer; }
	void setCurrentLocation(Tile * tile) { this->currentLocation = tile; }
	Tile * getCurrentLocation(void ) { return currentLocation; }

	bool findGoal(Tile * curretntLocation);
	void saveAnswer(void );
	void setStart(Tile * tile) {this->start=tile;}
	Tile * getStart(void) {return start;}
	void setGoal(Tile * tile) {this->goal=tile;}
	Tile * getGoal(void) {return goal;}	
};

#endif /* _SRC_PLAYERBOT_H_ */
