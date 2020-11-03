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
//    void printTree(struct Node* root,int n, int start, bool isChild) {
//        if (isChild) {
//            for (int i = start; i < n; i++) {
//                if (i == n - 1) {
//                    std::cout<<"|\n";
//                }
//                std::cout<<" ";
//            }
//        }
//        for (int i = start; i < n; i++) {
//            if (i == n/2) {
//                std::cout<<root->value<<std::endl;
//            }
//            std::cout<<" ";
//        }
//        if (root->right != NULL) {
//            printTree(root->right,n/2,n/2, true);
//        }
//        if (root->left != NULL) {
//            printTree(root->left, n/2, 0, true);
//        }
//        /*
//         desired output:
//
//                root
//               /    \
//            node    node
//           /    \   /   \
//
//         in order to do this we need to find width of the tree first
//         */
//    }
};

int main() {
    Node* root = new Node(1);
    root->right = new Node(3);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int width = root->widthOfTree(root);
//    root->printTree(root, width, 0, false);
    return 0;
}
