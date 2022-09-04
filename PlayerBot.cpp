/* PlayerBot.cpp
 *
 * Copyright (C), 2022, S3-04班
 */

#include "PlayerBot.h"
#include "Tile.h"
#include "Dungeon.h"
#include <fstream>
#include <iostream>

using namespace std;

PlayerBot::PlayerBot(void ) {
    this->setCurrentLocation(nullptr);
    goal2=0;
    proc2=1;
	number=1;
	branch=0;   
}

PlayerBot::~PlayerBot() {

}

queue<Tile*>nextque;
queue<int>branchq;

bool PlayerBot::findGoal(Tile * currentLocation)
{
    if(currentLocation == this->getGoal() || goal2 == 1){
        if(goal2 == 0){
            proc2 = currentLocation->proc;
        }

        goal2 = 1;

        if(proc2 == 0){
            return false;
        }
        if(currentLocation == this->getStart()){
            return false;
        }

        if(currentLocation->getWest() != nullptr && currentLocation->getWest()->proc == proc2-1){
            answer+="w";
            cout << "w" ;
            pro=currentLocation->getWest();
        }else if(currentLocation->getNorth() != nullptr && currentLocation->getNorth()->proc == proc2-1){
            answer+="n";
            cout << "n" ;
            pro=currentLocation->getNorth();
        }else if(currentLocation->getEast() != nullptr && currentLocation->getEast()->proc == proc2-1){
            answer+="e";
            cout << "e" ;
            pro=currentLocation->getEast();
        }else if(currentLocation->getSouth() != nullptr && currentLocation->getSouth()->proc == proc2-1){
            answer+="s";
            cout << "s" ;
            pro=currentLocation->getSouth();
        }else if(currentLocation->getWarp() != nullptr && currentLocation->getWarp()->proc == proc2-1){
            pro=currentLocation->getWarp();
        }else{
            cout << "error" << endl;
        }
        proc2--;
        
        findGoal(pro);
    }

    if(proc2 == 0){
        return false;
    }
    currentLocation->setVisit(nullptr);

    if(currentLocation->getWest() != nullptr){
        if(currentLocation->getWest()->getVisit() != nullptr){
            nextque.push(currentLocation->getWest());
            currentLocation->getWest()->setVisit(nullptr);
            currentLocation->getWest()->proc=proc2;
            branch++;
        }
    }
    if(currentLocation->getNorth() != nullptr){
        if(currentLocation->getNorth()->getVisit() != nullptr){
            nextque.push(currentLocation->getNorth());
            currentLocation->getNorth()->setVisit(nullptr);
            currentLocation->getNorth()->proc=proc2;
            branch++;
        }
    }
    if(currentLocation->getEast() != nullptr){
        if(currentLocation->getEast()->getVisit() != nullptr){
            nextque.push(currentLocation->getEast());
            currentLocation->getEast()->setVisit(nullptr);
            currentLocation->getEast()->proc=proc2;
            branch++;
        }
    }
    if(currentLocation->getSouth() != nullptr){
        if(currentLocation->getSouth()->getVisit() != nullptr){
            nextque.push(currentLocation->getSouth());
            currentLocation->getSouth()->setVisit(nullptr);
            currentLocation->getSouth()->proc=proc2;
            branch++;
        }
    }
    if(currentLocation->getWarp() != nullptr){
        if(currentLocation->getWarp()->getVisit() != nullptr){
            nextque.push(currentLocation->getWarp());
            currentLocation->getWarp()->setVisit(nullptr);
            currentLocation->getWarp()->proc=proc2;
            branch++;
        }
    }

    if(number==1){
        proc2++;
        branchq.push(branch);
        branch=0;
    }

    if(branchq.front()==0){
        branchq.push(branch);
        branchq.pop();
        proc2++;
        branch=0;
    }

    branchq.front()--;
  
    Tile * next = nextque.front();
    nextque.pop();
    number++;
    findGoal(next);
    return false;
}

void PlayerBot::saveAnswer(void)
{
	ofstream ofs("answer.txt");
	ofs << answer;

	return;
}
