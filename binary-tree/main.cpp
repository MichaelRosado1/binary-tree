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
    /*
     I have to tweak this because it doesn't give the exact width of the tree.
        This will work since I only need it for spacing to print the tree
     */
    int widthOfTree(struct Node* root) {
        //if there isn't a tree or if the the node has no children
        if (root == NULL) {
            return 0;
        }
        else return 1 + widthOfTree(root->right) + widthOfTree(root->left);
        
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
    root->printValues(root);
    return 0;
}
