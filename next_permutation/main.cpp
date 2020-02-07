//
//  main.cpp
//  next_permutation
//
//  Created by pzambad on 6/23/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        unsigned long i, j, k;
        
        //from right to left, find the first number (j) which not increase in a ascending order
        for (i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                j = i;
                break;
            }
        }
        
        //1. We cannot find the number, all the numbers increasing in a ascending order. This means this permutation is the last permutation, we need to rotate back to the first permutation
        //2. We can find the number, then the next step, we will start from right most to leftward, try to find the first number which is larger than found from above. Then swap the 2 numbers
        if (i < 0) {
            reverse(nums.begin(), nums.end());
        } else {
            for (i = nums.size() - 1; i > 0; i--) {
                if (nums[i] > nums[j]) {
                    swap(nums[i], nums[j]);
                    break;
                }
            }
        }
        
        //reverse from j+1 to n
        i = j+1;
        k = nums.size() - 1;

        while (i < k) {
            swap(nums[i], nums[k]);
            i++;
            k--;
        }
    }
};

int main(int argc, const char * argv[]) {
    int arr[] = {1,3,2};
    vector<int> A (arr, arr + sizeof(arr)/sizeof(arr[0]));
    class Solution soln;
    
    soln.nextPermutation(A);
    
    for (vector<int>::iterator it = A.begin(); it != A.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    return 0;
}
