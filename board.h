//
// Created by dzou on 8/27/17.
//

#ifndef TICKTACKTOE_BOARD_H
#define TICKTACKTOE_BOARD_H

#define player_sumX 6
#define player_sumY 6

class board {
private:
    static int const dimension = 3;
public:
    int XSum;
    int YSum;
    char GameBoard[dimension][dimension];
    char playerCharacter;
    static bool BoardGameOver;
    char winningCharacter;
    ///
    board();
    ~board();
    void generateField();
    void printState();
    bool connectThree();
    int awardPoints(bool end);
    bool checkFullBoard();
    void insertMove(int x, int y, char playerCharacter);
};

#endif //TICKTACKTOE_BOARD_H
