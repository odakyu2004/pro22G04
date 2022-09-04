/* main.cpp
 * Copyright (C), 2022, S3-04班
 */
#include <iostream>
#include "Tile.h"
#include "Dungeon.h"
#include "PlayerBot.h"

using namespace std;


int main()
{
	Dungeon d1;

	d1.loadData();

	PlayerBot bot;
	bot.setGoal(d1.getTiles()->back()); //ゴールの位置をセット
	bot.setStart(d1.getTiles()->front()); //スタートの位置をセット
	bot.findGoal(d1.getTile(0)); //最短経路探索
	bot.saveAnswer(); //最短経路の探索結果の保存

	return 0;
}