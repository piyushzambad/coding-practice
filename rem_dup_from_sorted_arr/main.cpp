//
//  main.cpp
//  rem_dup_from_sorted_arr
//
//  Created by pzambad on 6/23/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, j;
        j = 1;
        for (i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                continue;
            }
            nums[j] = nums[i];
            j += 1;
        }
        return j;
    }
};

int main(int argc, const char * argv[]) {
    class Solution A;
    int arr[] = {0,0,1,1,1,2,2,3,3,4}, N;
    vector<int> vec (arr, arr + sizeof(arr)/sizeof(arr[0]));
    
    N = A.removeDuplicates(vec);
    
    cout << "Size of vector after removing duplicates: " << N << endl;
    
    cout << "Elements in vector:" << endl;
    
    for (int i = 0; i < N; i++) {
        cout << vec[i] << " ";
    }
    
    cout << endl;
    return 0;
}
