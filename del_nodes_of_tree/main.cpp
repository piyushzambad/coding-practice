//
//  main.cpp
//  del_nodes_of_tree
//
//  Created by pzambad on 7/28/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
private:
    void delNodesUtil(TreeNode*& root, unordered_set<int> to_delete, vector<TreeNode*>& res, int index, TreeNode*& node) {
        if (root == NULL) {
            //index -= 1;
            return;
        }
        
        if (to_delete.find(root->val) == to_delete.end()) {
            node = root;
            if (res.size() == index-1) {
                cout << "index = " << index << endl;
                res.push_back(node);
                //index = res.size()+1;
            }
            delNodesUtil(root->left, to_delete, res, index, node->left);
            delNodesUtil(root->right, to_delete, res, index, node->right);
        } else {
            TreeNode *node1, *node2;
            if (root->left) {
                if (to_delete.find(root->left->val) == to_delete.end()) {
                    delNodesUtil(root->left, to_delete, res, res.size()+1, node1);
                } else {
                    delNodesUtil(root->left, to_delete, res, res.size(), node1);
                }
            }
            //index+=1;
            if (root->right) {
                if (to_delete.find(root->right->val) == to_delete.end()) {
                    delNodesUtil(root->right, to_delete, res, res.size()+1, node2);
                } else {
                    delNodesUtil(root->right, to_delete, res, res.size(), node2);
                }
            }
            delete root;
            root = NULL;
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        int index = 1;
        unordered_set<int> uset;
        TreeNode* node1;
        
        for(int i = 0; i<to_delete.size();i++) {
            uset.insert(to_delete[i]);
        }
        
        delNodesUtil(root, uset, res, index, node1);
        
        return res;
    }
    
    void printTree (TreeNode* root) {
        if (root == NULL) {
            //cout << "null ";
            return;
        }
        
        cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
    }
};

int main(int argc, const char * argv[]) {
    TreeNode* root;
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    class Solution A;
    A.printTree(root);
    cout << endl;
    
    vector<TreeNode*> res;
    vector<int> to_delete = {2,1};
    
    res = A.delNodes(root, to_delete);
    
    //cout << res.size() << endl;
    
    for (int i = 0; i < res.size(); i++) {
        A.printTree(res[i]);
        cout << endl;
    }
    
    return 0;
}
