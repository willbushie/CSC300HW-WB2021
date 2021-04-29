#include "Node.hpp"

class LinkedList
{
    private:
        Node* head;
        Node* tail;

    public:
        int count;
        LinkedList();
        void display();
        int getPayloadAt(int index);
        Node* getNode(int index);
        void addEnd(int value);
        int removeEnd();
        void addFront(int value);
        int removeFront();
        int removeAtIndex(int index);
        void addAtIndex(int value, int index);
        void swapNodes(Node* B, Node* A);
        void insertionSortLL();
        void mergeSort(int begin, int end);
        void merge(int begin1, int end1, int begin2, int end2);
};