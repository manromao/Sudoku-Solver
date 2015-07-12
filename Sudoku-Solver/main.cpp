#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MAX_ROWS 9
#define MAX_COLS 9
#define MAX_CELLS (MAX_COLS*MAX_ROWS)
#define MIN_VALUE 1
#define MAX_VALUE 9

using namespace std;

class Cell{

private:
    int value;

public:
    Cell(){
        value = 0;
    }

    int getValue() const{
        return this->value;
    }

    void setValue (int newValue){
        this->value = newValue;
    }

};

typedef Cell grid[MAX_CELLS];


class Game {

private:
    grid myGrid;

    bool isLegal(int testValue, int currentCell){

        bool isLegal = true;

        int toFirstColum    = currentCell/MAX_COLS;
        int columnStart     = currentCell - (toFirstColum*MAX_COLS);

        int toRowStart      = currentCell%MAX_ROWS;
        int rowStart        = currentCell - toRowStart;


        for (int n = 0; n < MAX_ROWS; ++n) {
              if (testValue == myGrid[rowStart + n].getValue()){
                  isLegal = false;
              }

        }

        for (int n = 0; n < MAX_COLS; ++n) {
             if (testValue == myGrid[columnStart + (n*MAX_COLS)].getValue()){
                 isLegal = false;
             }
        }


        return (isLegal);

    }



    bool isOkSquare(){
        return (true);
    }


public:

    Game(){}



    void setGame();

    bool hasSolution(){
        return (true);
    }

    bool solveGame(){
        cout << "Solving the game" << endl;


        for (int nCell = 0; nCell < MAX_CELLS; ++nCell) {
            for (int testValue = MIN_VALUE; testValue <= MAX_VALUE; ++testValue) {


                if (isLegal(testValue,nCell)) {
                    myGrid[nCell].setValue(testValue);
                    break;
                }
                else continue;

                // Insert a value in position
                // check if value is legal in that position (check rows and columns)

                // next value
            }
        // next position
        }



        cout << "¡Solved!" << endl;
        return EXIT_SUCCESS;
    }

    void printGame(){

        for (int nCell = 0; nCell < MAX_CELLS; ++nCell){


            int div =  nCell%9;
            if (div==0)
            {
                cout << endl;
            }

            cout << myGrid[nCell].getValue() << ' ';

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

