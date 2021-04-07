#include "node.hpp"

// tree header file
class tree
{
public:
    node* root; 
    int nodeCount;
    tree(); 
    void addNode(node* nodeToAdd);
    void visitInOrder(node* begin);  
    void visitPreOrder(node* begin);
    void visitPostOrder(node* begin);
};
