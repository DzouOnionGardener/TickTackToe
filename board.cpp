//
// Created by dzou on 8/27/17.
//
#include <iostream>
#include <algorithm>
#include "board.h"
using namespace std;

bool board::BoardGameOver = false;

board::board() {
    XSum = 0;
    YSum = 0;
    for(int i = 0; i < dimension; i++){
        for (int j = 0; j < dimension; j++){
            GameBoard[i][j] = NULL;
        }
    }
}
void board::generateField() {
    cout << "LOADING NEW BOARd" << endl;
    for(int i = 0; i< dimension; i++){
        for(int j = 0; j < dimension; j++){
            GameBoard[i][j] = '-';
        }
    }
    printState();
}

void board::printState() {
    for(int i = 0; i < dimension; i++){
        for (int j = 0; j < dimension; j++){
            cout << "\t" << GameBoard[i][j];
            if (j == dimension - 1){
                cout << endl;
            }
        }
    }
    cout << endl;
}

board::~board() {
    cout << "DELETING BOARD " << endl;
    //zero out the sums
    XSum = 0;
    YSum = 0;
    delete[] GameBoard;
}

void board::insertMove(int x, int y, char playerCharacter) {
    if((GameBoard[x][y] != 'X') && (GameBoard[x][y] != 'O')){
        GameBoard[x][y] = playerCharacter;
    }
    BoardGameOver = connectThree();
    cout << endl;
    printState();
}

bool board::connectThree() {
    //check if board is full
    bool draw = false;
    draw = checkFullBoard();
    if(draw){
        winningCharacter = 'D';
        cout << "DRAW" << endl;
        return true;
    }

    if((GameBoard[0][0] == GameBoard[0][1]) && (GameBoard[0][1] == GameBoard[0][2])){
        if((GameBoard[0][0] == 'X') || (GameBoard[0][0] == 'O')){
            winningCharacter = GameBoard[0][0];
            return true;
        }
    }
    if((GameBoard[1][0] == GameBoard[1][1]) && (GameBoard[1][1] == GameBoard[1][2])){
        if((GameBoard[1][0] == 'X') || (GameBoard[1][0] == 'O')){
            winningCharacter = GameBoard[1][0];
            return true;
        }
    } if((GameBoard[2][0] == GameBoard[2][1]) && (GameBoard[2][1] == GameBoard[2][2])){
        if((GameBoard[2][0] == 'X') || (GameBoard[2][0] == 'O')){
            winningCharacter = GameBoard[2][0];
            return true;
        }
    }
    ///horizontal check ^
    if((GameBoard[0][0] == GameBoard[1][0]) && (GameBoard[1][0] == GameBoard[2][0])){
        if((GameBoard[0][0] == 'X') || (GameBoard[0][0] == 'O')){
            winningCharacter = GameBoard[0][0];
            return true;
        }
    } if((GameBoard[0][1] == GameBoard[1][1]) && (GameBoard[1][1] == GameBoard[2][1])){
        if((GameBoard[0][1] == 'X') || (GameBoard[0][1] == 'O')){
            winningCharacter = GameBoard[0][1];
            return true;
        }
    } if((GameBoard[0][2] == GameBoard[1][2]) && (GameBoard[1][2] == GameBoard[2][2])){
        if((GameBoard[0][2] == 'X') || (GameBoard[0][2] == 'O')){
            winningCharacter = GameBoard[0][2];
            return true;
        }
    }
    ///verticle check ^
    if((GameBoard[0][0] == GameBoard[1][1]) && (GameBoard[1][1] == GameBoard[2][2])){
        if((GameBoard[0][0] == 'X') || (GameBoard[0][0] == 'O')){
            winningCharacter = GameBoard[0][0];
            return true;
        }
    } if((GameBoard[0][2] == GameBoard[1][1]) && (GameBoard[1][1] == GameBoard[2][0])){
        if((GameBoard[0][2] == 'X') || (GameBoard[0][2] == 'O')){
            winningCharacter = GameBoard[0][2];
            return true;
        }
    }
}

bool board::checkFullBoard() {
    //checks if there are empty cells
    bool emptyCell = false;
    for(int i = 0; ((emptyCell == false) && (i < dimension)); ++i){
        for(int j = 0; ((emptyCell== false) && (j < dimension)); ++j){
            if (GameBoard[i][j] == '-'){
                emptyCell = true;
                break;
            }
        }
        if (emptyCell){
            cout << "empty cell found \n";
            break;
        }
    }
    return emptyCell;
}

int board::awardPoints(bool end) {
    if(end){
        if(winningCharacter == playerCharacter){
            return 200;
        }
    }
    return (-200);
}