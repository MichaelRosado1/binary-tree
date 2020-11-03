//
//  main.cpp
//  binary-tree
//
//  Created by Michael Rosado on 11/3/20.
//

#include <iostream>
//Struct for the Node object
struct Node {
    //nodes contain value
    int value;
    //every node can have a left and right child node, or none at all
    struct Node* left;
    struct Node* right;
    
    Node(int input) {
        
        value = input;
        //we have to set left and right nodes to null since we don't know if the given node will have child nodes or not
        left = NULL;
        right = NULL;
    }
};

int main() {
    
    return 0;
}
