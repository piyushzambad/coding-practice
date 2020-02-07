//
//  main.cpp
//  three_sum
//
//  Created by pzambad on 6/22/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> umap;

        vector<int> temp;
        
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                break;
            }
            int remaining_sum = 0 - nums[i];
            umap.clear();
            temp.clear();
            if (i == 0 || ((i > 0) && nums[i] != nums[i-1])) {
                for(int j = i+1; j < nums.size(); j++) {
                    if (umap.find(remaining_sum - nums[j]) != umap.end()) {
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(remaining_sum - nums[j]);
                        
                        result.push_back(temp);
                        temp.clear();
                        //break;
                    }
                    umap[nums[j]] = j;
                }
            }
        }
        //result.erase(unique(result.begin(), result.end()), result.end());
        return result;
/*        vector<int> temp;
        
        int i, j, k;
        
        for (i = 0; i< nums.size()-2; i++) {
            for (j = i+1; j < nums.size()-1; j++) {
                for (k = j+1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        //sort(temp.begin(),temp.end());
                        result.push_back(temp);
                        temp.clear();
                    }
                }
            }
        }
        //sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
  */
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    class Solution temp;
    int arr[] = {-1, 0, 1, 2, -1, -4};
    vector<int> t (arr, arr + sizeof(arr)/sizeof(arr[0]));
    sort(t.begin(), t.end());
    
    vector<vector<int>> result;
    
    result = temp.threeSum(t);
    
    for (vector<vector<int>>::iterator it = result.begin(); it != result.end(); it++) {
        for (vector<int>::iterator it1 = it->begin(); it1 != it->end(); it1++) {
            cout << *it1 << " ";
        }
        cout << endl;
    }
    return 0;
}
