//
// Created by dzou on 8/27/17.
//
#include <iostream>
#include "Game.h"
#include "board.h"

using namespace std;

int game::round = 0;
long long game::GameScore = 0;
long long game::AI_Score = 0;
///
void game::printScore() {
    cout << currentScore;
}
///
long long game::getGameScore() {
    return GameScore;
}
int game::getRoundNumber() {
    return round;
}
long long game::getScore() {
    return currentScore;
}
///

game::~game(){
    cout << "GAME OVER" << endl;
    delete this;
}

bool game::gameState(bool boardState) {
    if (boardState){ //if boardstate == true
        gameOver = true;
        return true;
    }
    return false;
}

game::game(){
    ;
    ///do this
}