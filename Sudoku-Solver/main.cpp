#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>

#define MAX_ROWS 9
#define MAX_COLS 9
#define MAX_CELLS (MAX_COLS*MAX_ROWS)
#define MIN_VALUE 1
#define MAX_VALUE 9

using namespace std;

class Cell{



private:
    int value;
    int illegalValues[MAX_VALUE];

public:
    Cell(){
        initializeAtributtes();
    }

    int getValue() const{
        return this->value;
    }

    bool setValue (int newValue){

        for (int n = 0; n < sizeof(this->illegalValues)/sizeof(*this->illegalValues); ++n) {
            if (newValue == this->illegalValues[n]) {
                return false;
            }
        }

        this->value = newValue;
        return (true);
    }

    void addIllegalNumber(int illegalNumber){
        for (int n = 0; n < sizeof(illegalValues)/sizeof(*illegalValues); ++n) {
            if (illegalValues[n] == 0) {
                illegalValues[n] = illegalNumber;
                break; // Last position
            }
            else if (illegalValues[n] == illegalNumber) break; // number already there

        }

    }

    void initializeAtributtes(){
        this->value = 0;
        for (int n = 0; n < sizeof(this->illegalValues)/sizeof(*this->illegalValues); ++n) {
                this->illegalValues[n] = 0;
            }
    }
};

typedef Cell grid[MAX_CELLS];


class Game {

private:
    grid myGrid;

    bool isLegal(int testValue, int currentCell){

        bool isLegal, okRowsAndCols, okSquare;

        okRowsAndCols = this->areRowsAndColumnssOk(testValue, currentCell);
        okSquare = this->isOkSquare(testValue,currentCell);

        if (okRowsAndCols && okSquare) isLegal = true;


        return (isLegal);

    }

    bool areRowsAndColumnssOk(int testValue, int currentCell){
        bool okFlag = true;

        int toFirstColum    = currentCell / MAX_COLS;
        int columnStart     = currentCell - (toFirstColum*MAX_COLS);

        int toRowStart      = currentCell % MAX_ROWS;
        int rowStart        = currentCell - toRowStart;


        for (int n = 0; n < MAX_ROWS; ++n) {
              if (testValue == myGrid[rowStart + n].getValue()){
                  okFlag = false;
                  break;
              }

        }

        for (int n = 0; n < MAX_COLS; ++n) {
             if (testValue == myGrid[columnStart + (n*MAX_COLS)].getValue()){
                 okFlag = false;
                 break;
             }
        }

        return okFlag;
    }

      bool isOkSquare  (int testValue, int currentCell){

        // move to the top right corner of square [-deltaX, -deltaY]
        int deltaX = currentCell % 3;
        int deltaY = (currentCell / 9) %3;

        int startPosition = (currentCell-deltaX) - deltaY*MAX_COLS;

        // Check values in square

        for (int i = 0; i < sqrt(MAX_VALUE); ++i) {
            for (int j = 0; j < sqrt(MAX_VALUE); ++j) {
                if (myGrid[(startPosition + j) + MAX_COLS*i].getValue() == testValue) return (false);
            }
        }

       return (true);
    }


public:

    Game(){}

    bool hasSolution(){
        return (true);
    }

    bool solveGame(){
        cout << "Solving the game" << endl;


        for (int nCell = 0; nCell < MAX_CELLS; ++nCell) {

            for (int testValue = MIN_VALUE; testValue <= MAX_VALUE; ++testValue) {


                if (isLegal(testValue,nCell)) {
                    if (myGrid[nCell].setValue(testValue)) break;
                }
                else
                    myGrid[nCell].addIllegalNumber(testValue);



                if (testValue == MAX_VALUE){
                    myGrid[nCell].initializeAtributtes(); // reset the illegalValues list
                    myGrid[nCell-1].addIllegalNumber(myGrid[nCell-1].getValue()); // Add previous value as illegal
                    nCell = nCell - 2; // recompute
                }
            }
        // next position
        }



        cout << "¡Solved!" << endl;
        return EXIT_SUCCESS;
    }

    void printGame(){

        for (int nCell = 0; nCell < MAX_CELLS; ++nCell){

            if ((nCell%9)==0)
            {
                cout << endl;

            }

            cout << myGrid[nCell].getValue() << ' ' <<'|' << ' ';

        }

    }

    grid* getGrid(){
        return (&this->myGrid);
    }

    void setGrid(){}


};


int main()
{
    Game myGame;
    if (myGame.hasSolution())
    {
        myGame.solveGame();
        myGame.printGame();
    }


    return EXIT_SUCCESS;
}

