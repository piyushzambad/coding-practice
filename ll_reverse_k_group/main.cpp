//
//  main.cpp
//  ll_reverse_k_group
//
//  Created by pzambad on 8/11/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> vec;
        int temp = k;
        
        ListNode *prev = NULL, *curr = head, *next;
        while (curr && temp != 0) {
            prev = NULL;
            while (curr && temp != 0) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                temp--;
            }
            vec.push_back(prev);
            temp = k;
        }
        
        for (int i =0; i < vec.size()-1; i++) {
            ListNode* temp = vec[i];
            
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = vec[i+1];
        }
        return vec[0];
    }
    
    void print(ListNode* head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main(int argc, const char * argv[]) {
    ListNode* head1, *head2;
    head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    
    class Solution A;
    
    A.print(head1);
    
    head2 = A.reverseKGroup(head1, 2);
    
    A.print(head2);

    return 0;
}
