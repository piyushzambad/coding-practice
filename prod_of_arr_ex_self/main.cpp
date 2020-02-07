//
//  main.cpp
//  prod_of_arr_ex_self
//
//  Created by pzambad on 6/27/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(),1);
        int i,j;
        
        for (i = 0; i<nums.size(); i++) {
            for (j=0;j<nums.size();j++) {
                if (i!=j) {
                    result[i] = result[i] * nums[j];
                }
            }
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> A{1,2,3,4}, C;
    class Solution B;
    
    C = B.productExceptSelf(A);
    
    for(int i : C) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
