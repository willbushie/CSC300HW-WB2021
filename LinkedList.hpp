#include "Node.hpp"

class LinkedList
{
    private:
        Node* head;
        Node* tail;
        int count;

    public:
        LinkedList();
        void display();
        void addEnd(int value);
        int removeEnd();
        void addFront(int value);
        int removeFront();
        int removeAtIndex(int index);
        void addAtIndex(int value, int index);
        void swapNodes(Node* B, Node* A);
        void insertionSortLL();
};