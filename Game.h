//
// Created by dzou on 8/27/17.
//

#ifndef TICKTACKTOE_GAME_H
#define TICKTACKTOE_GAME_H

class game{
private:
    static int round;
    static long long GameScore;
    long currentScore = 0;
    bool gameOver = false;
    static long long AI_Score;

public:
    int turn = 0;
    void printScore();
    bool gameState(bool boardState);
    long long getScore();
    int getRoundNumber();
    long long getGameScore();

    game();
    ~game();
};


#endif //TICKTACKTOE_GAME_H
