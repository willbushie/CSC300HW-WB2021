#include "LinkedList.hpp"

class Stack : LinkedList
{
    public:
        void push(Card* value);
        Card* pop();
        Card* peek();
        void show();
        bool isEmpty();
        int getLength();
};