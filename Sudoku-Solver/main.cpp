#include <stdio.h>
#include <iostream>

#define MAX_ROWS 9
#define MAX_COLS 9
#define MAX_CELLS (MAX_COLS*MAX_ROWS)
#define MIN_VALUE 1
#define MAX_VALUE 9

using namespace std;

class Game {};
class cell{};

int main()
{
    Game* myGame = new Game();

    return 0;
}
class Game {
public:
    Game(){
        cout << "constructor" << endl;
    }
};
