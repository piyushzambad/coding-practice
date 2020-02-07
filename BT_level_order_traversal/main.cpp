//
//  main.cpp
//  BT_level_order_traversal
//
//  Created by pzambad on 8/3/19.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        TreeNode* temp;
        vector<int> temp2;

        que.push(root);
        
        while (!que.empty()) {
            temp2.clear();
            int N = que.size();
            for(int i = 0; i < N; i++) {
                temp = que.front();
                que.pop();
                
                temp2.push_back(temp->val);
                if (temp->left)
                    que.push(temp->left);
                if (temp->right)
                    que.push(temp->right);
            }
            res.push_back(temp2);
        }
        
        return res;
    }
};

int main(int argc, const char * argv[]) {
    TreeNode *root;
    root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    vector<vector<int>> res;
    class Solution A;
    res = A.levelOrder(root);
    
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
