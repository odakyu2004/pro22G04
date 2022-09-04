/* Dungeon.cpp
 *
 * Copyright (C), 2022, S3-04班
 */

#include "Dungeon.h"
#include "Tile.h"
#include <iostream>
#include <fstream>

using namespace std;

struct room {
	int south;
	int east;
	int warp;
};

template<typename CharT, typename Traits>
std::basic_ifstream<CharT,Traits>&
operator>>(std::basic_ifstream<CharT,Traits>& is, room& pt) {
	is >> pt.south >> pt.east >> pt.warp;
	return is;
}

Dungeon::Dungeon() {

}

Dungeon::~Dungeon() {
	for(unsigned int i=0; i<tiles.size(); i++) {
		delete tiles[i];
	}
}

/**
 * @fn Dungeon::loadData(void )
 *  データを読み込んで迷宮を再生する
 * @brief 読み込んだデータを一時的に保存し、vectorで数を作った後、一時データから一気に接続状況を作る
 */
void Dungeon::loadData(void )
{
	ifstream ifs("data.txt");
	int width;  // 東西方向の部屋の個数
	int length; // 南北方向の部屋の個数
	ifs >> width; // ファイルから読み込み
	ifs >> length;
	unsigned int size(width * length);
	cout << size << endl;
	// とりあえず、データの保存 N,S,W,E,warpID
	room data[size];
	for(unsigned int i=0; i<size; i++) {
		ifs >> data[i]; // 2行目以降,部屋の接続状況が保存されているので一時的にdataへ
		tiles.push_back(new Tile);
	}
	for(unsigned int i=0; i<size; i++) {
		// 左上から右に移動
		// 南と東の壁の接続状況がわかれば、北と西も自動的にわかる
		// 一方通行はなしと考える
		if (data[i].south == 1) {
			tiles[i]->setSouth(tiles[i+width]);
			tiles[i+width]->setNorth(tiles[i]);
		}
		if (data[i].east == 1) {
			tiles[i]->setEast(tiles[i+1]);
			tiles[i+1]->setWest(tiles[i]);
		}
		if (data[i].warp != -1) {
			tiles[i]->setWarp(tiles[data[i].warp]);
		}
		tiles[i]->setFlag(tiles[i]);
	}
	return;
}
