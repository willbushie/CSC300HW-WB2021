#include "Node.hpp"
#include <stdlib.h>

// method to create a new instance of a node
Node::Node(int payload)
{
    this->payload = payload;
    this->nextNode = NULL;
}

// method to set the nextNode value of an element
void Node::setNextNode(Node* n)
{
    this->nextNode = n;
}

// method to obtain the nextNode value of an element
Node* Node::getNextNode()
{
    return this->nextNode;
}

// method to obtain the payload of an element
int Node::getPayload()
{
    return this->payload;
}
