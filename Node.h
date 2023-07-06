#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

class Node{
    public:
    int value;
    Node* left;
    Node* right;

    Node();
    Node(int x);

};

#endif