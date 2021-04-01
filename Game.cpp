#include "Game.hpp"
#include <stdlib.h>
#include <iostream>

//setup our initial 3 towers with the disks on the far left
Game::Game(Tower* tower0)
{
    // place all of the towers into the Tower* array
    this->theTowers[0] = tower0;
    Tower* tower1 = new Tower();
    this->theTowers[1] = tower1;
    Tower* tower2 = new Tower();
    this->theTowers[2] = tower2;
    
    // find the largestDiskSize
    Disk* currDisk = tower0->top;
    while(currDisk)
    {
        this->largestDiskSize = currDisk->getSize();
        currDisk = currDisk->getNextDisk();
    }
    std::cout << this->largestDiskSize << std::endl;
}

// display the 3 towers on the screen, you can do this vertically
void Game::display() 
{
    // display each tower and its disks from the Tower* array from right to left
    theTowers[0]->display();
    theTowers[1]->display();
    theTowers[2]->display();

    // this code will be used to print the towers horizontally to the terminal - not currently working
    /*std::string spacing = "   ";
    // loop to create the final output
        // spacing + top disk/tower + spacing + top disk/tower + spacing + top disk/tower + spacing
        std::string topLayerOutput = "";

        // spacing + middle disk/tower + spacing + middle disk/tower + spacing + middle disk/tower + spacing
        std::string middleLayerOutput = "";

        // spacing + bottom disk/tower + spacing + bottom disk/tower + spacing + bottom disk/tower + spacing
        std::string bottomLayerOutput = "";

    // print final outputs
    std::cout << topLayerOutput << std::endl;
    std::cout << middleLayerOutput << std::endl;
    std::cout << bottomLayerOutput << std::endl;
    */
}

// this method will ask the user for the next move 
void Game::nextMove()
{

}
