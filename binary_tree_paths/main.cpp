//
//  main.cpp
//  binary_tree_paths
//
//  Created by pzambad on 6/30/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        queue<string> temp_res;
        queue<TreeNode*> que;
        vector<string> res;
        
        que.push(root);
        temp_res.push(to_string(root->val));
        
        while (!que.empty()) {
            TreeNode* temp = que.front();
            que.pop();
            
            string str;
            bool rem = false;
            
            if (temp->left) {
                str = temp_res.front();
                temp_res.push(str + "->" + to_string(temp->left->val));
                rem = true;
                
                que.push(temp->left);
            }
            if (temp->right) {
                str = temp_res.front();
                temp_res.push(str + "->" + to_string(temp->right->val));
                rem = true;
                
                que.push(temp->right);
            }
            if (rem)
                temp_res.pop();
            else {
                res.push_back(temp_res.front());
                temp_res.pop();
            }
        }
        
        return res;
    }
};

int main(int argc, const char * argv[]) {
    TreeNode *A;
    A = new TreeNode(1);
    A->left = new TreeNode(2);
    A->right = new TreeNode(3);
    A->right->right = new TreeNode(4);
    
    
    class Solution B;
    vector<string> res;
    
    res = B.binaryTreePaths(A);
    
    vector<string>::size_type n = res.size();
    
    for(int i=0; i<n; i++) {
        cout << res[i] << endl;
    }
    
    return 0;
}
