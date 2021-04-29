#include "Node.hpp"
#include <stdlib.h>

Node::Node(int payload)
{
    this->payload = payload;
    this->nextNode = NULL;
    this->prevNode = NULL;
}

void Node::setPayload(int passedPayload)
{
    this->payload = passedPayload;
}

Node* Node::getPrevNode()
{
    return this->prevNode;
}

void Node::setNextNode(Node* n)
{
    this->nextNode = n;
}

void Node::setPrevNode(Node* n)
{
    this->prevNode = n;
}

Node* Node::getNextNode()
{
    return this->nextNode;
}
        
int Node::getPayload()
{
    return this->payload;
}