#include "Card.hpp"

class Node
{
    private:
        Card* payload;
        Node* nextNode;
        
    
    public:
        Node(Card* card);
        void setNextNode(Node* n);
        Node* getNextNode();
        Card* getPayload();
};