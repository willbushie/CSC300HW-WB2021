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

// method to add an element to the front of the linked list
void LinkedList::addFront(int value)
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
        // store current head as updatedHeadNextNode
        Node* updatedHeadNextNode = this->head;
        // add head to the new head
        this->head = n;
        // set the new nextNode of the new head
        this->head->setNextNode(updatedHeadNextNode);
    }
    this->count++; 
}

// method to remove an element from the front of the list
int LinkedList::removeFront()
{
    if(this->count > 0) 
    {
        Node* n = this->head; 
        int value = n->getPayload(); 
        if(this->count == 1) 
        {
            this->head = NULL;
            this->tail = NULL;
            
        }
        else
        {
            // assign the new head of the list
            Node* currNode = this->head->getNextNode();
            this->head = currNode;
        }
        this->count--;
        delete(n); //if we didn't do this, we technically have a memory leak
        return value; 
    }
}


// method to add an element to the end of the linked list
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

// method to remove the end element of the linked list
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

// method to display the linked list & its contents
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
