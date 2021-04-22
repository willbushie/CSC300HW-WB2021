#include "LinkedList.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

LinkedList::LinkedList()
{
    this->head = NULL;
    this->tail = NULL;
    this->count = 0;
}

Node* LinkedList::getNodeAtIndex(int index)
{
    if(index >= 0 && index < this->count)
    {
        //return the node at that position in the list
        Node* currNode = this->head;
        for(int i = 0; i < index; i++)
        {
            currNode = currNode->getNextNode();
        }
        return currNode;
    }
    return NULL; //not a legal index!!!
}

void LinkedList::insertionSort()
{
    //does this list need to potentially be sorted?
    if(this->count > 1)
    {
        Node* theFollowerNode;
        Node* swapNode;
        Node* beforeSwapNode;
        int theFollowerPos;

        for(int currStart = 1; currStart < this->count; currStart++)
        {
            theFollowerPos = currStart;
            theFollowerNode = this->getNodeAtIndex(theFollowerPos);
            while(theFollowerPos > 0 && theFollowerNode->getPayload()->defense < this->getNodeAtIndex(theFollowerPos-1)->getPayload()->defense)
            {
                //we need to do a swap between theFollowerNode and the node before him.
                swapNode = this->getNodeAtIndex(theFollowerPos-1);
                if(this->head == swapNode)
                {
                    swapNode->setNextNode(theFollowerNode->getNextNode());
                    theFollowerNode->setNextNode(head);
                    this->head = theFollowerNode;
                }
                else
                {
                    beforeSwapNode = this->head;
                    while(beforeSwapNode->getNextNode() != swapNode)
                    {
                        beforeSwapNode = beforeSwapNode->getNextNode();
                    }
                    swapNode->setNextNode(theFollowerNode->getNextNode());
                    theFollowerNode->setNextNode(swapNode);
                    beforeSwapNode->setNextNode(theFollowerNode);
                }
                if(this->tail == theFollowerNode) //resets tails if we are swapping away from tail
                {
                    this->tail = swapNode;
                }
                theFollowerPos--;
            }
        } 
    }
}

void LinkedList::addAtIndex(Card* card, int index)
{
    if(index == 0)
    {
        this->addFront(card);
    }
    else if(index == this->count)
    {
        this->addEnd(card);
    }
    else
    {
        Node* dude2Add = new Node(card);
        Node* prevDude = this->head;
        for(int i = 0; i < (index-1); i++)
        {
            prevDude = prevDude->getNextNode();
        }
        dude2Add->setNextNode(prevDude->getNextNode());
        prevDude->setNextNode(dude2Add);
        this->count++;
    }
    
}

Card* LinkedList::removeAtIndex(int index)
{
    if(this->head)
    {
        if(index < 0 || index >= this->count)
        {
            cout << "ArrayIndexOutOfBoundException!!!!" << endl;
        }
        else
        {
            //I actuall have something to remove
            if(index == 0)
            {
                return this->removeFront();
            }
            else if(index == this->count-1)
            {
                return this->removeEnd();
            }
            else
            {
                //we are removing from somewhere in the middle
                Node* prevDude = this->head;
                Node* dude2Remove = this->head;

                //How do I get prevDude and dude2Remove set in a single loop?
                //run dude2Remove to the correct index
                for(int i = 0; i < index; i++)
                {
                    dude2Remove = dude2Remove->getNextNode();
                }

                //now make preDude point to the node right before dude2Remove
                while(prevDude->getNextNode() != dude2Remove)
                {
                    prevDude = prevDude->getNextNode();
                }

                /* Identical result as the while loop above
                //what is another way we could have written the while loop above?
                for(int i = 0; i < index-1; i++)
                {
                    prevDude = prevDude->getNextNode();
                }
                */

               //Now everything is position and we are ready to operate!!!
               prevDude->setNextNode(dude2Remove->getNextNode());
               dude2Remove->setNextNode(NULL);
               Card* value2Return = dude2Remove->getPayload();
               delete(dude2Remove);
               this->count--;
               return value2Return;
            }
            
        }
        
    }
    else
    {
        cout << "Nothing to Remove from the Empty List" << endl;
    }
    
}

void LinkedList::addFront(Card* card)
{
    if(this->head)
    {
        //add it to the front
        Node* n = new Node(card);
        n->setNextNode(this->head);
        this->head = n;
         this->count++;
    }
    else
    {
        //we have an empty list, so addFront and addEnd mean the same thing
        this->addEnd(card);
    }
}

Card* LinkedList::removeFront()
{
    if(this->head)
    {
        Node* currFront = this->head;
        this->head = this->head->getNextNode();
        currFront->setNextNode(NULL);
        Card* valueToReturn = currFront->getPayload();
        delete(currFront);
        this->count--;
        return valueToReturn;
    }
    
}

void LinkedList::addEnd(Card* card)
{
    Node* n = new Node(card);
    if(head == NULL)
    {
        //we have the empty list
        this->head = n;
        this->tail = n;
    }
    else
    {
        //we have a list with at least one element in it, and we know that tail
        //points to the end of that list.
        this->tail->setNextNode(n);
        this->tail = n;
    }
    this->count++;
}

Card* LinkedList::removeEnd()
{
    if(this->count > 0)
    {
        Node* n = this->tail;
        Card* value = n->getPayload();
        if(this->count == 1)
        {
            this->head = NULL;
            this->tail = NULL;
            
        }
        else
        {
            Node* currNode = this->head;
            while(currNode->getNextNode() != this->tail)
            {
                currNode = currNode->getNextNode();
            }
            this->tail = currNode;
            this->tail->setNextNode(NULL);
        }
        this->count--;
        delete(n); //if we didn't do this, we technically have a memory leak
        return value;
    }
    
}
void LinkedList::display()
{
    if(this->count == 0)
    {
        cout << "the empty list" << endl;
    }
    else
    {
        Node* currNode = this->head;
        while(currNode->getNextNode() != NULL)
        {
            currNode->getPayload()->display();
            currNode = currNode->getNextNode();
        }
        currNode->getPayload()->display();
    }   
}
