//
//  main.cpp
//  binary-tree
//
//  Created by Michael Rosado on 11/3/20.
//

#include <iostream>
#include <iomanip>
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
    
    int getHeight(struct Node* root) {
        //if node isn't null
        if (root) {
            //left node passed back to function
            int leftTreeHeight = getHeight(root->left);
            //right node passed back to function
            int rightTreeHeight = getHeight(root->right);
            //if the left tree height is greater than right
            if (leftTreeHeight > rightTreeHeight) {
                //add 1
                return leftTreeHeight + 1;
            } else {
                return rightTreeHeight + 1;
            }
        }
        return 0;
    }
    
    //This method will print the binary tree
    void printValues(struct Node* root, int spaces =20) {
        
        if (root != NULL) {
            
            std::cout<<std::setw(spaces)<<root->value;
            if (root->left) {
                std::cout<<std::endl;
                printValues(root->left, spaces - 4);
            }
            if (root->right) {
                std::cout<<std::endl;
                printValues(root->right, spaces + 4);
                
            }
            if (spaces != 20) {
                std::cout<<std::setw(spaces)<<' ';
            }
        }
    }
};

int main() {
    Node* root = new Node(1);
    root->right = new Node(3);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int x = root->getHeight(root);
    std::cout<<x<<" ";
    return 0;
}
