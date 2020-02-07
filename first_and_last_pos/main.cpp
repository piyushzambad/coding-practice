//
//  main.cpp
//  first_and_last_pos
//
//  Created by pzambad on 7/13/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int findFirst(vector<int>& nums, int target, int i, int j) {
        if (i>j) {
            return -1;
        }
        
        int mid = i + (j-i)/2;
        
        if (nums[mid] == target) {
            if (mid - 1 >= i) {
                if (nums[mid-1] < target)
                    return mid;
                else
                    return findFirst(nums, target, i, mid-1);
            } else {
                return mid;
            }
        } else if (nums[mid] > target) {
            return findFirst(nums, target, i, mid-1);
        } else {
            return findFirst(nums, target, mid+1, j);
        }
    }
    
    int findLast(vector<int>& nums, int target, int i, int j) {
        if (i>j) {
            return -1;
        }
        int mid = i + (j-i)/2;
        
        if (nums[mid] == target) {
            if (mid + 1 <= j) {
                if (nums[mid+1] > target)
                    return mid;
                else
                    return findLast(nums, target, mid+1, j);
            } else {
                return mid;
            }
        } else if (nums[mid] > target) {
            return findLast(nums, target, i, mid-1);
        } else {
            return findLast(nums, target, mid+1, j);
        }

    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        res[0] = findFirst(nums, target, 0, nums.size() - 1);
        res[1] = findLast(nums, target, 0, nums.size() - 1);
        
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {5,7,7,8,8,10};
    class Solution A;
    vector<int> res;
    
    res = A.searchRange(nums, 6);
    
    cout << "[" << res[0] << "," << res[1] << "]" << endl;
    return 0;
}
