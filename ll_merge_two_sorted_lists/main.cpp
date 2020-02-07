//
//  main.cpp
//  ll_merge_two_sorted_lists
//
//  Created by pzambad on 6/29/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}ListNode;


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0), *result = &dummy;
        while (l1 || l2) {
            if ((l1 ? l1->val : INT_MAX) < (l2 ? l2->val : INT_MAX)) {
                result->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                result->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            result = result->next;
        }
        return dummy.next;
    }
};

int main(int argc, const char * argv[]) {
    ListNode *l1, *l2, *res;
    
    l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    
    l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    
    class Solution A;
    
    res = A.mergeTwoLists(l1, l2);
    
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    
    return 0;
}
