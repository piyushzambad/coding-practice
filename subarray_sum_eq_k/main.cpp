//
//  main.cpp
//  subarray_sum_eq_k
//
//  Created by pzambad on 10/6/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            int temp_sum = nums[i];
            int j = i+1;
            while(j <= nums.size()) {
                if (temp_sum == k) {
                    count++;
                }
                if (j < nums.size())
                    temp_sum += nums[j];
                j++;
            }
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {28,54,7,-70,22,65,-6};
    int k = 100;
    
    class Solution A;
    
    cout << A.subarraySum(nums, k) << endl;
    return 0;
}
