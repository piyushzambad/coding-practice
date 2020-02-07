//
//  main.cpp
//  ll_reorder_list
//
//  Created by pzambad on 6/30/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}ListNode;


class Solution {
public:
    void reorderList(ListNode* head) {
 
         ListNode *l1, *l2;
        
         if (head == NULL || head->next == NULL) {
             return;
         }
        
         //Split, n1,n2,n3,n4,n5
         l1 = head;//l1=n1
         l2 = head->next;//l2=n2
        
         //
         while (l2 && l2->next) {//n2,n3; n4,n5
             l1 = l1->next;//n2; n3
             l2 = l2->next->next;//n4; NULL
         }
        
         l2 = l1->next; // n4->n5->NULL
         l1->next = NULL;//n3->NULL
        
         l1 = head;//n1->n2->n3->NULL
        
         //Reverse l2
         //N4->N5->NULL
         ListNode *prev=NULL, *next,  *curr = l2;
        
         while (curr) {
             next = curr->next;//N5; NULL
             curr->next = prev;//N4->NULL; N5->N4
             prev = curr;//N4; N5
             curr = next;//N5; NULL
         }
         //N5->N4->NULL
         l2 = prev;
        
         //Merge
         // l1 = N1 N2 N3; l2 = N5, N4
         while (/*l1 && */l2) {
             next = l1->next;//N2; N3
             l1->next = l2;//N1->N5; N2->N4
             prev = l2->next;//N4; NULL
             l2->next = next;//N5->N2; N4->N3
            
             l1 = next;        //N2; N3
             l2 = prev;        //N4; NULL
         }
        
         //N1->N5->N2->N4->N3->NULL
        
        
        
        /*vector<ListNode*> A;
        ListNode *temp;
        
        temp = head;
        
        while (temp != NULL) {
            A.push_back(temp);
            temp = temp->next;
        }
        vector<ListNode>::size_type n = A.size();
        int i;

        for (i = 0; i < n/2; i++) {
            A[i]->next = A[n-i-1];
            A[n-i-1]->next = A[i+1];
        }
        
        A[i]->next = NULL;*/
    }
};

int main(int argc, const char * argv[]) {
    ListNode *A;
    A = new ListNode(1);
    A->next = new ListNode(2);
    A->next->next = new ListNode(3);
    A->next->next->next = new ListNode(4);
    A->next->next->next->next = new ListNode(5);
    
    class Solution B;
    
    B.reorderList(A);
    
    while (A != NULL) {
        cout << A->val << " ";
        A = A->next;
    }
    cout << endl;
    
    return 0;
}
