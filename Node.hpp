class Node
{
    private:
        Node* nextNode;
        Node* prevNode;
        
    
    public:
        int payload;
        Node(int payload);
        void setNextNode(Node* n);
        Node* getNextNode();
        int getPayload();
        void setPrevNode(Node* n);
        Node* getPrevNode();
        void setPayload(int passedPayload);
};
