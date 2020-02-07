//
//  main.cpp
//  BT_right-side-view
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;
        
        que.push(root);
        
        while (!que.empty()) {
            queue<TreeNode*>::size_type n = que.size();
            
            for(int i = 1; i <= n; i++) {
                TreeNode *temp = que.front();
                que.pop();
                
                if (i == n) {
                    res.push_back(temp->val);
                }
                
                if (temp->left) {
                    que.push(temp->left);
                }
                if (temp->right) {
                    que.push(temp->right);
                }
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
    A->left->right = new TreeNode(5);
    A->right->right = new TreeNode(4);
    
    class Solution B;
    vector<int> res;
    
    res = B.rightSideView(A);
    
    for(vector<int>::iterator it = res.begin(); it != res.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    return 0;
}
