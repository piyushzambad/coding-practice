//
//  main.cpp
//  subsets
//
//  Created by pzambad on 7/6/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp = {};
        vector<int>::size_type N = nums.size();
        
        res.push_back(temp);
        
        for (int i=1; i<pow(2,N); i++) {
            temp.clear();
            int j = i;
            for (int k = 0; k < N; k++) {
                if (j&1) {
                    temp.push_back(nums[k]);
                }
                j = j >> 1;
            }
            res.push_back(temp);
        }
        
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> res;
    vector<int> vec = {1,2,3};
    class Solution A;
    
    res = A.subsets(vec);
    
    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
