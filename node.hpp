class node
{
public:
    int payload;
    node* leftChild;
    node* rightChild;
    node(int payload);
    void addRightChild(node* node);
    void addLeftChild(node* node);
    int getPayload();
};
