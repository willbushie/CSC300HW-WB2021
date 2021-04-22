#include "LinkedList.hpp"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>

LinkedList::LinkedList()
{
    this->count = 0;
    this->head = NULL;
    this->tail = NULL;
}

Node* LinkedList::get(int index)
{
    Node* node2Return = this->head;
    for(int i = 0; i < index; i++)
    {
        node2Return = node2Return->getNextNode();
    }
    return node2Return;
}

// thinnk of list like this: A, larger, smaller, B
// this list configuration will be referenced in the method
void LinkedList::swap(int index1, int index2)
{
    // hold indexes for the passed ints
    int smaller = index1;
    int larger = index2;
    // loop to check which index is larger
    if(larger < smaller)
    {
        smaller = index2;
        larger = index1;
    }
    // get the nodes for each of the indexes
    Node* smallerNode = this->get(smaller);
    Node* largerNode = this->get(larger);
    // print out the values index read outs
    printf("smaller: %d, larger: %d\n", smaller, larger);
    // perform the swap
    // update A's next node
    largerNode->getPrevNode()->setNextNode(smallerNode);
    // update B's prev node
    smallerNode->getNextNode()->setPrevNode(largerNode);
    // first operation
    smallerNode->setPrevNode(largerNode->getPrevNode());
    largerNode->setNextNode(largerNode->getPrevNode());
    // second opeartion
    smallerNode->setNextNode(largerNode);
    largerNode->setPrevNode(smallerNode);

    if(smaller == 0)
    {
        this->head = largerNode;
        cout << "set head to larger" << endl;
    }

    if(larger == this->count-1)
    {
        this->tail = smallerNode;
        cout << "set tail to smaller" << endl;
    }
}

void LinkedList::insertionSortOnDefense()
{
    int theFollower;
    for(int currStart = 1; currStart < this->count; currStart++)
    {
        theFollower = currStart;
        while(theFollower > 0 && this->get(theFollower)->getPayload()->getDefense() <
                this->get(theFollower-1)->getPayload()->getDefense())
        {
            //I need to swap
            this->swap(theFollower, theFollower-1);
            theFollower--;
        }
        // print out the currStart #
        //cout << "curr start: " << currStart << endl;
    }
}

void LinkedList::addEnd(Card* c)
{
    Node* n = new Node(c);
    if(this->count == 0)
    {
        this->head = n;
        this->tail = n;
    }
    else
    {
        n->setPrevNode(this->tail);
        this->tail->setNextNode(n);
        this->tail = n;
    }
    this->count++;
}

int LinkedList::getCount()
{
    return this->count;
}

void LinkedList::display()
{
    Node* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        currNode->getPayload()->display();
        currNode = currNode->getNextNode();
    }
}
