#include "node.hpp"

// instance method
node::node(int payload)
{
    this->payload = payload;
}

// add a right child
void node::addRightChild(node* node)
{
    this->rightChild = node;
}

// add a left child
void node::addLeftChild(node* node)
{
    this->leftChild = node;
}

int node::getPayload()
{
    return this->payload;
}