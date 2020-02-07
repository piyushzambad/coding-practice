//
//  main.cpp
//  two_sum
//
//  Created by pzambad on 8/3/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> umap;
        
        for (int i = 0; i < nums.size(); i++) {
            if (umap.find(target - nums[i]) != umap.end()) {
                result.push_back(umap[target-nums[i]]);
                result.push_back(i);
                break;
            }
            umap[nums[i]] = i;
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {2, 7, 11, 15}, res;
    int target = 9;
    class Solution A;
    
    res = A.twoSum(nums, target);
    
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    
    return 0;
}
