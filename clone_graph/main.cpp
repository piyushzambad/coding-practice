//
//  main.cpp
//  clone_graph
//
//  Created by pzambad on 6/30/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {}
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

typedef class Node Node;

class Solution {
public:
    Node* cloneGraph(Node* node) {
        Node *res;
        unordered_map<Node*, Node*> umap;
        queue<Node*> que;
        
        que.push(node);
        res = new Node;
        res->val = node->val;
        
        umap[node] = res;
        
        while (!que.empty()) {
            Node* temp = que.front();
            que.pop();
            
            vector<Node *> vec = temp->neighbors;
            vector<Node *>::size_type n = vec.size();
            
            cout << "Neighbors: " << endl;
            for(int i = 0; i < n; i++) {
                if (umap.find(vec[i]) == umap.end()) {
                    Node* temp2 = new Node;
                    temp2->val = vec[i]->val;
                    umap[vec[i]] = temp2;
                    que.push(vec[i]);
                }
                umap[temp]->neighbors.push_back(umap[vec[i]]);
            }
        }
        return res;
    }
    void bfs(Node* node) {
        unordered_map<Node*, bool> visit;
        queue<Node*> que;
        
        que.push(node);
        visit[node] = true;
        
        while(!que.empty()) {
            Node* temp = que.front();
            cout << "Value of node: " << temp->val << endl;
            que.pop();
            
            vector<Node *> vec = temp->neighbors;
            vector<Node *>::size_type n = vec.size();
            
            cout << "Neighbors: " << endl;
            for(int i = 0; i < n; i++) {
                if (!visit[vec[i]]) {
                    visit[vec[i]] = true;
                    que.push(vec[i]);
                }
                cout << vec[i]->val << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, const char * argv[]) {
    Node *A, *B, *C, *D, *F;
    vector<Node*> neigh;

    A = new Node;
    A->val = 1;
    
    B = new Node;
    B->val = 2;
    
    C = new Node;
    C->val = 3;
    
    D = new Node;
    D->val = 4;
    
    A->neighbors.push_back(B);
    A->neighbors.push_back(D);
    
    B->neighbors.push_back(A);
    B->neighbors.push_back(C);
    
    C->neighbors.push_back(B);
    C->neighbors.push_back(D);
    
    D->neighbors.push_back(A);
    D->neighbors.push_back(C);
    
    class Solution E;
    
    cout << "Printing B: " << endl;
    E.bfs(B);
    
    F = E.cloneGraph(A);
    
    cout << "Printing F: " << endl;
    E.bfs(F);
    return 0;
}
