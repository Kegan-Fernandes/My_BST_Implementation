#ifndef BST_h
#define BST_h

#include "Node.h"

class BST
{
    public: 
    Node* root;

    BST();
    //Iterative method for inserting a node intto the binary search tree
    void insert(Node* nodeTOadd);

    //Recursive method to insert a node into the Binary search Tree 

    Node* insertRecursive(Node* r, Node* n);
   

//********************PRINT THE TREE IN PREORDER, INORDER, POSTORDER, AND BREATH FIRST WAY******************
void preOrder(Node* node);
void inOrder(Node* node);
void postOrder(Node* node);

//iteratively doing preorder, inoder and post order
//use stack

void iterPreOrder(Node* node);

// Or we can try and use the root vaiable driectly from the bst class insead of passing a node in the parameter 
void iterPreOrder2();



void iterInorder(Node* node);





//iteratively implementing breathfirst traversal using queue

void BFS(Node* node);

//NOw SEARCH METHOD. RETURN TRUE IF A GIVE NODE VALUE IS FOUND, FALSE OTHERWISE 
// recursive method. from the main, pass in the root node and the value to be searched
bool searchRecursively(Node* node, const int& x);

bool searchIterative(Node* node, int x);


// Function to find the height of a binary or binary search tree. In my implementation, the height 
// of a tree is the most number of edges between the root node and its furthest leaf node
//returns an int value 

int FindHeight(Node* node);

// Function to check if the tree is balanced or not 
// using a helper function aswell
int BalancedCheckHelper(Node* node);
bool BalancedCheck(Node* node);

//Function to check if the tree is a binary search tree
// return type is a boolean
//need a helper funciton 

bool isBSThelper(Node* node, int min, int max);

bool isBST(Node* node);


};




#endif