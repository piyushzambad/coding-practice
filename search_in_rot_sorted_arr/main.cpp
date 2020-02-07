//
//  main.cpp
//  search_in_rot_sorted_arr
//
//  Created by pzambad on 7/13/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int findPivot (vector<int>& nums, int i, int j) {
        if (i > j) {
            return -1;
        }
        int mid = i + ((j-i) / 2);
        
        if (nums.size() == 1) {
            return i;
        }

        if (nums[mid] > nums[mid+1]) {
            return mid+1;
        }
        
        if (nums[mid] > nums[0]) {
            return findPivot(nums, mid+1, j);
        } else {
            return findPivot(nums, i, mid);
        }
    }
    
    int bst (vector<int>& nums, int target, int i, int j) {
        if (i > j) {
            return -1;
        }
        if (i == j) {
            return (nums[i] == target) ? i : -1;
        }
        int mid = i + ((j-i) / 2);
        
        if (nums[mid] == target) {
            return mid;
        } else if (target > nums[mid]) {
            return bst(nums, target, mid+1, j);
        } else {
            return bst(nums, target, i, mid);
        }
    }
public:
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums, 0, nums.size() - 1);
        
        int index;
        if (target >= nums[0]) {
            if (pivot == -1) {
                pivot = nums.size();
            }
            index = bst(nums, target, 0, pivot - 1);
        } else {
            if (pivot == -1) {
                pivot = 0;
            }
            index = bst(nums, target, pivot, nums.size() - 1);
        }

        return index;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,3};
    class Solution A;
    
    cout << A.search(nums, 0) << endl;
    
    return 0;
}
