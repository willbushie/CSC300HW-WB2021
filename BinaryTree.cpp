#include "BinaryTree.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

BinaryTree::BinaryTree()
{
    this->isEmpty = true;
    this->leftChild = NULL;
    this->rightChild = NULL;
    this->count = 0;
}

BinaryTree::BinaryTree(int payload)
{
    BinaryTree(); //initially create an empty tree

    //make it not empty
    this->isEmpty = false;
    this->payload = payload;
    this->count = 1;
}

// left self right
void BinaryTree::visitInOrder()
{
    if(!this->isEmpty)
    {
        if(this->leftChild)
        {
            this->leftChild->visitInOrder();
        }
        cout << this->payload << " ";
        if(this->rightChild)
        {
            this->rightChild->visitInOrder();
        }
    }
}

// self left right 
void BinaryTree::visitPreOrder()
{
    if(!this->isEmpty)
    {
        cout << this->payload << " ";
        if (this->leftChild)
        {
            this->leftChild->visitPreOrder();
        }
        if (this->rightChild)
        {
            this->rightChild->visitPreOrder();
        }
    }
}

// left right self
void BinaryTree::visitPostOrder()
{
    if(!this->isEmpty)
    { 
        if (this->leftChild)
        {
            this->leftChild->visitPreOrder();
        }
        if (this->rightChild)
        {
            this->rightChild->visitPreOrder();
        }
        cout << this->payload << " ";
    }
}


int BinaryTree::getCount()
{
    return this->count;
}

int BinaryTree::getPayload()
{
    return this->payload;
}

void BinaryTree::add(int payload)
{
    this->count++;
    if(this->isEmpty)
    {
        this->payload = payload;
        this->isEmpty = false;
    }
    else if(payload <= this->payload) //we need to add to the left
    {
        if(this->leftChild) //do I already have a left child?
        {
            //ask the left child to add the value
            this->leftChild->add(payload);
        }
        else
        {
            //create a left child with this payload
            this->leftChild = new BinaryTree(payload);
        }  
    }
    else //we need to add to the right
    {
        if(this->rightChild)
        {
            this->rightChild->add(payload);
        }
        else
        {
            this->rightChild = new BinaryTree(payload);
        } 
    }
}