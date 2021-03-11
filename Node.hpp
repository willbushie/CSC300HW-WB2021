class Node
{
    private:
        int payload;
        Node* nextNode;
        Node* prevNode;
        
    
    public:
        Node(int payload);
        void setNextNode(Node* n);
        Node* getNextNode();
        int getPayload();
        void setPrevNode(Node* n);
        Node* getPrevNode();
};
