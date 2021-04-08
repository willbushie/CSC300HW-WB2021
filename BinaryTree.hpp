class BinaryTree
{
    private:
        int payload;
        bool isEmpty;
        BinaryTree* leftChild;
        BinaryTree* rightChild;
        int count;

    public:
        BinaryTree(); //creates an empty tree
        BinaryTree(int payload);
        void visitInOrder();
        void visitPreOrder();
        void visitPostOrder();
        int getPayload();
        void add(int payload);
        int getCount();
};