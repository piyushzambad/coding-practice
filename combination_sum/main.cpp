//
//  main.cpp
//  combination_sum
//
//  Created by pzambad on 8/4/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> final_res;
    
    void combinationSumUtil(vector<int>& candidates, int target, vector<int> res) {
        if (target == 0) {
            bool dup = false;
            
            sort(res.begin(), res.end());
            for (vector<vector<int>>::iterator it = final_res.begin(); it != final_res.end(); it++) {
                if (res == *it) {
                    dup = true;
                    break;
                }
            }
            
            if (!dup)
                final_res.push_back(res);
        }
        for (int i = 0; (i < candidates.size()); i++) {
            if (candidates[i] <= target) {
                res.push_back(candidates[i]);
                combinationSumUtil(candidates, target-candidates[i], res);
                res.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> res;
        
        combinationSumUtil(candidates, target, res);
        
        sort(final_res.begin(), final_res.end());
        
        return final_res;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> candidates = {2,3,5};
    int target = 8;
    class Solution A;
    vector<vector<int>> res;
    res = A.combinationSum(candidates, target);
    
    for (vector<vector<int>>::iterator it = res.begin(); it != res.end(); it++) {
        for(vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++) {
            cout << *it2 << " ";
        }
        cout << endl;
    }
    return 0;
}
