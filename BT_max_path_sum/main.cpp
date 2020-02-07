//
//  main.cpp
//  BT_max_path_sum
//
//  Created by pzambad on 6/30/19.
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
public:
    int maxPathSumUtil(TreeNode* node, int& g_max) {
        if (node == NULL) {
            return 0;
        }
        
        int ls = maxPathSumUtil(node->left, g_max);
        int rs = maxPathSumUtil(node->right, g_max);
        
        if (ls < 0)
            ls = 0;
        if (rs < 0)
            rs = 0;
        
        g_max = max(g_max, ls+rs+node->val);
        
        return node->val + max(ls,rs);
    }
    
    int maxPathSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int g_max = INT_MIN;
        maxPathSumUtil(root, g_max);
        return g_max;
    }
};

int main(int argc, const char * argv[]) {
    struct TreeNode *A;
    A = new TreeNode(-10);
    A->left = new TreeNode(9);
    A->right = new TreeNode(20);
    A->right->left = new TreeNode(15);
    A->right->right = new TreeNode(7);
    
    class Solution B;
    
    cout << B.maxPathSum(A) << endl;
    
    return 0;
}
