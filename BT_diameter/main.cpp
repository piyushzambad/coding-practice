//
//  main.cpp
//  BT_diameter
//
//  Created by pzambad on 7/2/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        return 1 + max(height(root->left), height(root->right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        int ld = diameterOfBinaryTree(root->left);
        int rd = diameterOfBinaryTree(root->right);
        
        return max(ld, max(rd, 1+lh+rh));
    }
};

int main(int argc, const char * argv[]) {
    TreeNode *A;
    A = new TreeNode(1);
    A->left = new TreeNode(2);
    A->left->left = new TreeNode(4);
    A->left->right = new TreeNode(5);
    A->right = new TreeNode(3);
    
    class Solution B;
    
    cout << B.diameterOfBinaryTree(A) << endl;

    return 0;
}
