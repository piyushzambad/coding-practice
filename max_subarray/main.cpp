//
//  main.cpp
//  max_subarray
//
//  Created by pzambad on 8/6/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int *dp;
        int _max = 0;
        dp = new int[nums.size()];
        
        dp[nums.size()-1] = nums[nums.size()-1];
        _max = dp[nums.size()-1];
        for(int i = nums.size() - 2; i>=0; i--) {
            dp[i] = max(nums[i], nums[i]+dp[i+1]);
            _max = max(_max, dp[i]);
        }
        
        return _max;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    class Solution A;
    
    cout << A.maxSubArray(nums) << endl;
    return 0;
}
