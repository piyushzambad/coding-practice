//
//  main.cpp
//  BT_to_circular_LL
//
//  Created by pzambad on 10/13/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
/*    Node* treeToDoublyList(Node* root) {

        if (root == NULL  || root->left == NULL) {
            return root;
        }
        
        Node* newHead = treeToDoublyList(root->left);
        
        root->left->right = root->left->right ? min (root->left->right) : root;
        root->left->left = 
        
    }*/
};

int main(int argc, const char * argv[]) {
    // insert code here...
    string temp;
    temp = "1\n";
    
    cout << temp.erase(temp.find_last_not_of("\n")+1);
    //std::cout << "Hello, World!\n";
    return 0;
}
