//
//  main.cpp
//  merge_sorted_arrays
//
//  Created by pzambad on 10/5/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = m+n-1;
        
        while(k>=0) {
            if (i >= 0 && j >= 0) {
                if (nums1[i] > nums2[j]) {
                    nums1[k] = nums1[i];
                    k--;
                    i--;
                } else {
                    nums1[k] = nums2[j];
                    k--;
                    j--;
                }
            } else if (i >= 0) {
                nums1[k] = nums1[i];
                k--;
                i--;
            } else if (j >= 0) {
                nums1[k] = nums2[j];
                k--;
                j--;
            } else {
                k--;
            }
        }
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1,2,3,0,0,0}, nums2 = {2,5,6};
    int m = 3, n = 3;
    class Solution A;
    
    A.merge(nums1, m, nums2, n);
    
    for(int i = 0; i < m+n; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    return 0;
}
