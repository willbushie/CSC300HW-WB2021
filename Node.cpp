#include "Node.hpp"
#include <stdlib.h>

Node::Node(Card* card)
{
    this->payload = card;
    this->nextNode = NULL;
}

void Node::setNextNode(Node* n)
{
    this->nextNode = n;
}

Node* Node::getNextNode()
{
    return this->nextNode;
}
        
Card* Node::getPayload()
{
    return this->payload;
}