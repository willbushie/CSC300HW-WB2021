#include "Disk.hpp"
#include <stdlib.h>

Disk::Disk(int size)
{
    this->size = size;
    this->nextDisk = NULL;
}
        
int Disk::getSize()
{
    return this->size;
}

Disk* Disk::getNextDisk()
{
    return this->nextDisk;
}
        
void Disk::setNextDisk(Disk* n)
{
    this->nextDisk = n;
}

std::string Disk::toString()
{
    //return a string that has a number of = that is twice the size
    std::string answer = "";
    for(int i = 0; i < this->size; i++)
    {
        answer += "==";
    }
    // find the length of answer and find the location to place the 
    int answerLen = answer.length();
    // place a tower character in the middle of the answer and update it
    answerLen /= 2;
    // walk through the answer string and place the character in the correct place and output a final string
    std::string finalAnswer;
    for (int count = 0; count <= answer.length(); count++)
    {
        // place the tower character inside the string
        if (count == answerLen)
        {
            finalAnswer += "+";
        }
        else
        {
            finalAnswer += "=";
        }
    }
    return finalAnswer;
}