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

// sorting method for int linked list (insertionSort)
void LinkedList::insertionSortLL()
{
    Node* currStart = this->head;
    Node* theFollower;
    for (int currPos = 0; currPos < this->count; currPos++)
    {
        theFollower = currStart;
        while (theFollower != this->head && theFollower->getPayload() < theFollower->getPrevNode()->getPayload())
        {
            Node* prevNodeOfPrevNodeOfFollower = NULL;
            swapNodes(theFollower->getPrevNode(), theFollower);
            theFollower = theFollower->getPrevNode();
        }
        currStart = currStart->getNextNode();
    }
}

// sorting method for int linked list (mergeSort)
void LinkedList::mergeSort(int begin, int end)
{
    //we only need to do anything in here, if the list is bigger than a 1 list
    if(begin != end)
    {
        //we DO NOT HAVE A 1 LIST!!!!!
        //so we need to divide our list in half and call mergesort on each half
        int begin1 = begin;
        int end1 = (begin + end) / 2;
        int begin2 = end1 + 1;
        int end2 = end;
        this->mergeSort(begin1, end1);
        this->mergeSort(begin2, end2);
        //now the left half is sorted and the right half is sorted
        //we need to merge them together into a single sorted portion
        //of our list from begin to end 
        this->merge(begin1, end1, begin2, end2);
        //this->display();
    }
}

// merge method used in mergeSort
void LinkedList::merge(int begin1, int end1, int begin2, int end2)
{
    int size = end2 - begin1 + 1;
    int temp[size];
    int pos1 = begin1;
    int pos2 = begin2;
    for(int i = 0; i < size; i++)
    {
        //how do we ask if pos1 points to a legal place on the left half of the list?
        if(pos1 <= end1 && pos2 <= end2)
        {
            if(this->getPayloadAt(pos1) < this->getPayloadAt(pos2))
            {
                temp[i] = this->getPayloadAt(pos1);
                pos1++;
            }
            else
            {
                temp[i] = this->getPayloadAt(pos2);
                pos2++;
            }
        }
        else if(pos1 <= end1)
        {
            temp[i] = this->getPayloadAt(pos1);
            pos1++;
        }
        else
        {
            temp[i] = this->getPayloadAt(pos2);
            pos2++;
        }
    }
    //temp is filled up with our values in the correct order
    //we need to now transfer those value back over to ar overwriting
    //the old contents of ar with the contents of temp between begin1 and end2
    int tempPos = 0;
    for(int i = begin1; i <= end2; i++)
    {
        this->getNode(i)->setPayload(temp[tempPos]);
        tempPos++;
    }
    //now ar is overwritten between begin1 and end2 with the values in order
    //and this call to merge and mergesort can end
}

Node* LinkedList::getNode(int index)
{
    Node* currNode = this->head;
    for (int count = 0; count < this->count-1; count++)
    {
        if (count == index)
        {
            return currNode;
        }
        currNode = currNode->getNextNode();
    }
    // advance and return
    return currNode;
}


// this method flips two nodes in the linked list
// A is the node to move "behind" B
// process: (B, A) -> (A, B)
// if B does not have a previous node, pass null
void LinkedList::swapNodes(Node* B, Node* A)
{
    Node* A_nextNode = A->getNextNode();
    Node* B_nextNode = B->getNextNode();

    if (this->head == B) // if B is head of linked list
    {
        this->head = A;
        A->setNextNode(B);
        B->setNextNode(A_nextNode);
    }    
    else if (this->tail == A) // if A is the tail
    {
        this->tail = B;
        A->setNextNode(B);
        B->setNextNode(A_nextNode);
        if (B->getPrevNode() != NULL)
        {
            B->getPrevNode()->setNextNode(A);
        }
    }
    else // if the nodes passed are in the middle of the list
    {
        A->setNextNode(B);
        B->setNextNode(A_nextNode);
        if (B->getPrevNode() != NULL)
        {
            B->getPrevNode()->setNextNode(A);
        }
    }
}


int LinkedList::getPayloadAt(int index)
{
    // currNode used to keep track of the current node being evaluated
    Node* currNode = this->head;
    // value to store the payload to return the index
    int payloadReturn;
    // loop through the linked list to find the correct value at the index requested
    for (int count = 0; count != index; count++)
    {
        // update payload to return value
        payloadReturn = currNode->getPayload();
        // advance currNode
        currNode = currNode->getNextNode();
    }
    // update payload to return value
    payloadReturn = currNode->getPayload();

    // return the payload
    return payloadReturn;
}


void LinkedList::addAtIndex(int value, int index)
{
    if(index == 0)
    {
        this->addFront(value);
    }
    else if(index == this->count)
    {
        this->addEnd(value);
    }
    else
    {
        Node* dude2Add = new Node(value);
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

int LinkedList::removeAtIndex(int index)
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
               int value2Return = dude2Remove->getPayload();
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