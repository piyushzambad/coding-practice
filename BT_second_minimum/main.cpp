//
//  main.cpp
//  BT_second_minimum
//
//  Created by pzambad on 8/4/19.
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
    void findSecondMinimumValueUtil(TreeNode* root, int& second_min) {
        if (root == NULL || root->right == NULL)
            return;
        
        if (root->right->val != root->left->val) {
            second_min = min(second_min, max(root->right->val, root->left->val));
            findSecondMinimumValueUtil(root->right->val < root->left->val ? root->right : root->left, second_min);
        }
        else {
            findSecondMinimumValueUtil(root->right, second_min);
            findSecondMinimumValueUtil(root->left, second_min);
        }
    }
    
public:
    int findSecondMinimumValue(TreeNode* root) {
        int second_min = INT_MAX;
        if (root == NULL || root->right == NULL || root->right->val == root->left->val)
            return -1;
        
        second_min = max(root->right->val, root->left->val);
        
        findSecondMinimumValueUtil(root->right->val < root->left->val ? root->right : root->left, second_min);
        
        return second_min;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
