//
//  main.cpp
//  BT_serialize_deserialize
//
//  Created by pzambad on 7/19/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
    string serializeUtil(TreeNode* root, string& res) {
        if (root == NULL) {
            return res + "N ";
        }
        
        res += to_string(root->val) + " ";
        res = serializeUtil(root->left, res);
        res = serializeUtil(root->right, res);
        
        return res;
    }
    
    TreeNode* deserializeUtil(TreeNode* root, string data, int& index) {
        bool sign = false;
        if (index >= data.size() - 1) {
            return NULL;
        } else if (data[index] == 'N') {
            return NULL;
        } else if (data[index] == '-') {
            sign = true;
            index+=1;
        }
        
        string::size_type nxt_num = data.find(" ", index);
        cout << index << " " << nxt_num << endl;
        int num = 0;
        for (int i = index; i<nxt_num; i++) {
            num += (data[i] - '0')*pow(10,nxt_num-i-1);
        }
        root = new TreeNode(num * (sign ? -1 : 1));
        index = nxt_num+1;
        root->left = deserializeUtil(root->left, data, index);
        nxt_num = data.find(" ", index);
        index = nxt_num+1;
        root->right = deserializeUtil(root->right, data, index);
        
        return root;
    }
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stack<TreeNode*> st;
        string res = "";
        if (root == NULL) {
            return "N";
        } else {
            st.push(root);
        }
        
        while (!st.empty()) {
            TreeNode* temp = st.top();
            st.pop();

            if (temp != NULL) {
                res += to_string(temp->val) + " ";

                st.push(temp->right);
                st.push(temp->left);
            } else {
                res += "N ";
            }
        }
        
        return res;
        //return serializeUtil(root, res);
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        int index = 0;
        /*bool sign = false;
        
        while (index < data.size() - 1) {
            TreeNode* temp;
            sign = false;
            
            if (data[index] == 'N') {
                temp = NULL;
            } else if (data[index] == '-') {
                sign = true;
                index+=1;
            }
            
            string::size_type nxt_num = data.find(" ", index);
            //cout << index << " " << nxt_num << endl;
            int num = 0;
            for (int i = index; i<nxt_num; i++) {
                num += (data[i] - '0')*pow(10,nxt_num-i-1);
            }
            
            temp = new TreeNode(num * (sign ? -1 : 1));
            index = nxt_num+1;

        }*/

        root = deserializeUtil(root, data, index);
        
        return root;
    }
};


int main(int argc, const char * argv[]) {
    TreeNode *A, *B;
    A = new TreeNode(1);
    A->left = new TreeNode(9);
    A->right = new TreeNode(2);
    A->left->left = new TreeNode(8);
    A->left->right = new TreeNode(10);
    
    string data, data1;
    class Codec C;
    data = C.serialize(A);
    
    cout << data << endl;
    
    //B = C.deserialize(data);
    //data1 = C.serialize(B);
    
    //cout << data1 << endl;

    return 0;
}
