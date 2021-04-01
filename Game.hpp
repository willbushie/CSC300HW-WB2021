#include "Tower.hpp"

class Game
{
    private:
        Tower* theTowers[3];
        //int largestDiskSize;

    public:
        int largestDiskSize;
        Game(Tower* theTower); 
        void display(); 
        void nextMove(); // this method will be used to ask the user for the next move
};