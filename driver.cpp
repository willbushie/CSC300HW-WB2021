#include <iostream>
#include "Game.hpp"

using namespace std;

int main(int argc, char** argv)
{
    Disk* d1 = new Disk(1);
    Disk* d2 = new Disk(2);
    Disk* d3 = new Disk(3);

    Tower* t = new Tower();
    t->push(d3);
    t->push(d2);
    t->push(d1);
    //t->display();

    Game* newGame = new Game(t);
    newGame->display();

    return 0;

}