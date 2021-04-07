// CSC300 - HW#12 - Binary Search Tree Analysis - William Bushie - 4/8/2021
#include "tree.hpp"
#include <iostream>

// main method
int main(int argc, char const *argv[])
{
    // creation of the nodes
    node* n1 = new node(1);
    node* n2 = new node(0);
    node* n3 = new node(8);
    node* n4 = new node(2);
    node* n5 = new node(4);
    node* n6 = new node(7);
    node* n7 = new node(12);
    node* n8 = new node(9);

    // creation of the tree & adding of the nodes
    tree* t1 = new tree();
    t1->addNode(n1);
    t1->addNode(n2);
    t1->addNode(n3);
    t1->addNode(n4);
    t1->addNode(n5);
    t1->addNode(n6);
    t1->addNode(n7);
    t1->addNode(n8);

    std::cout << "In Order:" << std::endl;
    t1->visitInOrder(t1->root);
    std::cout << "Pre Order:" << std::endl;
    t1->visitPreOrder(t1->root);
    std::cout << "Post Order:" << std::endl;
    t1->visitPostOrder(t1->root);

    return 0;
}
