#include "Tower.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

Tower::Tower()
{
    this->top = NULL;
    this->count = 0;
}

Disk* Tower::pop()
{
    //remove the top element and return it or just return NULL if there is no top
    if(this->count == 0)
    {
        return NULL;
    }
    else
    {
        Disk* disk2Return = this->top;
        this->top = disk2Return->getNextDisk();
        disk2Return->setNextDisk(NULL);
        this->count--;
        return disk2Return;
    }
}

Disk* Tower::peek()
{
    //returns without removing the top element or just return NULL if there is no top

}

void Tower::display()
{
    //cout on each disks toString for the entire tower
    Disk* currDisk = this->top;
    
    // print the top of the tower, the top spaces, no towers
    cout << "" << endl;
    cout << "+" << endl;
    cout << "+" << endl;

    // format accordinly should the tower have less than three disks
    if (this->count == 0) // 0 disks
    {
        cout << "+" << endl;
        cout << "+" << endl;
        cout << "+" << endl;
    }
    else if (this->count == 1) // 1 disk
    {
        cout << "+" << endl;
        cout << "+" << endl;
        while(currDisk)
        {
            // check disk string size with the largest disk to find the correct spacing
            string spacing = "";

            cout << " " + currDisk->toString() << endl;
            // advance currDisk if possible
            currDisk = currDisk->getNextDisk();
        }
    }
    else if (this->count == 2) // 2 disks
    {
        cout << "+" << endl;
        while(currDisk)
        {
            // check disk string size with the largest disk to find the correct spacing
            string spacing = "";

            cout << " " + currDisk->toString() << endl;
            // advance currDisk if possible
            currDisk = currDisk->getNextDisk();
        }

    }
    else // 3 disks
    {
        while(currDisk)
        {
            // check disk string size with the largest disk to find the correct spacing
            string spacing = "";

            cout << " " + currDisk->toString() << endl;
            // advance currDisk if possible
            currDisk = currDisk->getNextDisk();
        }

    }
}   

void Tower::push(Disk* d)
{
    //add an element to the top of the stack
    //don't implement tower of hanoi rules yet
    d->setNextDisk(this->top);
    this->top = d;
    this->count++;
}