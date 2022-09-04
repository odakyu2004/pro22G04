/* Dungeon.h
 *
 * Copyright (C), 2022, S3-04班
 */

#ifndef _SRC_DUNGEON_H_
#define _SRC_DUNGEON_H_

#include <vector>

using namespace std;

class Tile;

class Dungeon {
private:
	vector<Tile *> tiles;
public:
	Dungeon();
	virtual ~Dungeon();
	void loadData(void ); // データを読み込み配列に保存
	vector<Tile *> * getTiles(void ) { return & tiles; } 
	Tile * getTile(int number) { return tiles[number]; } //numberの部屋の状況を返す関数
};

#endif /* _SRC_DUNGEON_H_ */
