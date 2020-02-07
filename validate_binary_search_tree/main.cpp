//
//  main.cpp
//  validate_binary_search_tree
//
//  Created by pzambad on 6/30/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

class Solution {
public:
    int max(TreeNode* node) {
        while (node->right) {
            node = node->right;
        }
        return node->val;
    }
    
    int min (TreeNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node->val;
    }
    
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        
        return isValidBST(root->left) && ((root->left ? root->val > max(root->left) : true) && (root->right ? root->val < min(root->right) : true)) && isValidBST(root->right);
    }
};

int main(int argc, const char * argv[]) {
    TreeNode *A;
    A = new TreeNode(5);
    A->left = new TreeNode(1);
    A->right = new TreeNode(7);
    A->right->left = new TreeNode(6);
    A->right->right = new TreeNode(8);
    
    class Solution B;
    
    cout << "Valid tree? : " << B.isValidBST(A) << endl;
    
    return 0;
}
