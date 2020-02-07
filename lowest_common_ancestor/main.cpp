//
//  main.cpp
//  lowest_common_ancestor
//
//  Created by pzambad on 7/4/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool lowestCommonAncestorUtil(TreeNode* root, TreeNode* search, vector<TreeNode*> &path) {
        if (root == NULL) {
            return false;
        }
        
        path.push_back(root);
        
        if (root->val == search->val) {
            return true;
        }
        
        if (lowestCommonAncestorUtil(root->left, search, path) || lowestCommonAncestorUtil(root->right, search, path)) {
            return true;
        }
        
        path.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        
        if (!lowestCommonAncestorUtil(root, p, path1) || !lowestCommonAncestorUtil(root, q, path2)) {
            return NULL;
        }
        
        vector<TreeNode*>::size_type it = path1.size() < path2.size() ? path1.size() : path2.size();
        
        int i = 0;
        for (i = 0; i < it-1; i++) {
            if (path1[i]->val == path2[i]->val && path1[i+1]->val != path2[i+1]->val) {
                break;
            }
        }
        return path2[i];
    }
};

int main(int argc, const char * argv[]) {
    TreeNode *A, *p, *q, *lca;
    A = new TreeNode(1);
    A->left = new TreeNode(2);
    A->left->left = new TreeNode(4);
    p = A->left->left;
    A->left->right = new TreeNode(5);
    
    A->right = new TreeNode(3);
    A->right->left = new TreeNode(6);
    q = A->left;
    A->right->right = new TreeNode(7);
    
    class Solution B;
    
    lca = B.lowestCommonAncestor(A, p, q);
    
    cout << lca->val << endl;
    
    return 0;
}
