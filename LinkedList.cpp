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

void LinkedList::addFront(int value)
{
    if(this->head)
    {
        //add it to the front
        Node* n = new Node(value);
        n->setNextNode(this->head);
        this->head = n;
         this->count++;
    }
    else
    {
        //we have an empty list, so addFront and addEnd mean the same thing
        this->addEnd(value);
    }
}

int LinkedList::removeFront()
{
    if(this->head)
    {
        Node* currFront = this->head;
        this->head = this->head->getNextNode();
        currFront->setNextNode(NULL);
        int valueToReturn = currFront->getPayload();
        delete(currFront);
        this->count--;
        return valueToReturn;
    }
    
}

void LinkedList::addEnd(int value)
{
    Node* n = new Node(value);
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

int LinkedList::removeEnd()
{
    if(this->count > 0)
    {
        Node* n = this->tail;
        int value = n->getPayload();
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
            cout << currNode->getPayload() << " -> ";
            currNode = currNode->getNextNode();
        }
        cout << currNode->getPayload() << endl;
    }
    
}