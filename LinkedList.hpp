#include "Node.hpp"

class LinkedList
{
    private:
        Node* head;
        Node* tail;
    
    protected:
        Node* getNodeAtIndex(int index);
        int count;

    public:
        LinkedList();
        void display();
        void addEnd(Card* value);
        Card* removeEnd();
        void addFront(Card* value);
        Card* removeFront();
        Card* removeAtIndex(int index);
        void addAtIndex(Card* value, int index);
        void insertionSort();
};