#include "Stack.hpp"

void Stack::push(Card* value)
{
    this->addFront(value);
}

void Stack::show()
{
    this->display();
}

bool Stack::isEmpty()
{
    return this->count == 0;
}

int Stack::getLength()
{
    return this->count;
}

Card* Stack::pop()
{
    return this->removeFront();
}

Card* Stack::peek()
{
    return this->getNodeAtIndex(0)->getPayload();
}