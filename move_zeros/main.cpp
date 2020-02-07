//
//  main.cpp
//  move_zeros
//
//  Created by pzambad on 6/27/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        
        for (i = 0; i < nums.size()-1; i++) {
            if (nums[i] != 0) {
                j++;
            } else if (nums[i] == 0 && nums[i+1]!=0) {
                swap(nums[i+1], nums[j]);
                j++;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> A{1,2,3,0,0,3,1,2};
    class Solution B;
    B.moveZeroes(A);
    
    for(int i:A) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
