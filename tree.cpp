#include "tree.hpp"
#include <stdlib.h>
#include <iostream>

// instance method
tree::tree()
{
    this->nodeCount = 0;
}

// add an element to the tree
void tree::addNode(node* nodeToAdd)
{
    // check if the node has a root or not
    if (this->root)
    {
        // compare node
        node* nodeToCompare = this->root;
        // placement variable
        bool placed = false;
        while (placed == false)
        {
            // keep track of where the placement should be
            bool left;
            // find the possible placement
            if (nodeToAdd->payload <= nodeToCompare->payload)
            {
                left = true;
            }
            else if (nodeToAdd->payload > nodeToCompare->payload)
            {
                left = false;
            }
            // check if the placement is available & place if it is
            // check the left
            if ((nodeToCompare->leftChild == NULL) && (left == true))
            {
                nodeToCompare->addLeftChild(nodeToAdd);
                this->nodeCount++;
                placed = true;
            }
            // check the right
            else if ((nodeToCompare->rightChild == NULL) && (left == false))
            {
                nodeToCompare->addRightChild(nodeToAdd);
                this->nodeCount++;
                placed = true;
            }
            // if placement is not available, advance nodeToCompare apropriately
            else 
            {
                if (left == true)
                {
                    nodeToCompare = nodeToCompare->leftChild;
                }
                else if (left == false)
                {
                    nodeToCompare = nodeToCompare->rightChild;
                }
            }
        }    
    }
    else
    {
        this->root = nodeToAdd;
        this->nodeCount++;
    }
}

// display in order (left, self, right)
void tree::visitInOrder(node* begin)
{
    // does the node have left child
    if (begin->leftChild)
    {
        visitInOrder(begin->leftChild);
    }
    // display self
    int payloadToPrint = begin->getPayload();
    std::cout << payloadToPrint << std::endl;
    // does the node have a right child
    if (begin->rightChild)
    {
        visitInOrder(begin->rightChild);
    }
}  

// display pre order (self, left, right)
void tree::visitPreOrder(node* begin)
{
    // display self
    std::cout << begin->payload << std::endl;
    // does the node have a left child?
    if (begin->leftChild)
    {
        this->visitPreOrder(begin->leftChild);
    }
    // does the node have a right child?
    if (begin->rightChild)
    {
        this->visitPreOrder(begin->rightChild);
    }
}

// dispaly post order (left, right, self)
void tree::visitPostOrder(node* begin)
{
    // does the node have a left child?
    if (begin->leftChild)
    {
        this->visitPostOrder(begin->leftChild);
    }
    // does the node have a right child?
    if (begin->rightChild)
    {
        this->visitPostOrder(begin->rightChild);
    }
    // display self
    std::cout << begin->payload << std::endl;
}
