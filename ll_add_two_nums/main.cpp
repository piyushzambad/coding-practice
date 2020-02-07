//
//  main.cpp
//  ll_add_two_nums
//
//  Created by pzambad on 6/29/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
} ListNode;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head, *result = &head;
        uint sum = 0, carry = 0;
        
        while (l1 != NULL || l2 != NULL || carry) {
            sum = (l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0) + carry;
            carry = sum /10;
            sum = sum % 10;
            
            result->next = new ListNode;
            result->next->val = sum;
            result->next->next = NULL;
            
            
            result = result->next;
            
            l2 = l2 ? l2->next : l2;
            l1 = l1 ? l1->next : l1;
        }
        
        return head.next;
    }
};

int main(int argc, const char * argv[]) {
    ListNode *A, *B;
    
    A = new ListNode;
    A->val = 2;
    A->next = new ListNode;
    A->next->val = 4;
    A->next->next = new ListNode;
    A->next->next->val = 3;
    A->next->next->next = NULL;
    
    B = new ListNode;
    B->val = 5;
    B->next = new ListNode;
    B->next->val = 6;
    B->next->next = new ListNode;
    B->next->next->val = 7;
    B->next->next->next = NULL;
    
    class Solution C;
    ListNode *res;
    res = C.addTwoNumbers(A, B);
    
    while (res != NULL) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
