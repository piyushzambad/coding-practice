//
//  main.cpp
//  permutations
//
//  Created by pzambad on 7/4/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void permuteUtil(vector<int>& nums, int begin, vector<vector<int>> &result) {
        if (begin >= nums.size()) {
            result.push_back(nums);
            return;
        }
        
        for (int i = begin; i < nums.size(); i++) {
            if ((i != begin)) {
                bool cont = false;
                for(int j = begin; j < i; j++) {
                    if (nums[i] == nums[j]) {
                        cont = true;
                        break;
                    }
                }
                if (cont) {
                    continue;
                }
            }
            swap(nums[i], nums[begin]);
            permuteUtil(nums, begin+1, result);
            swap(nums[i], nums[begin]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permuteUtil(nums, 0, res);
        
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> A = {3,1,3,1,3};
    class Solution B;
    vector<vector<int>> res;
    
    res = B.permute(A);
    
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
