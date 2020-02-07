//
//  main.cpp
//  container_with_most_water
//
//  Created by pzambad on 8/10/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int i = 0, j = height.size() - 1;
        
        while (i < j) {
            ans = max(ans, min(height[i],height[j]) * (j - i));
            
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    class Solution A;
    
    cout << A.maxArea(heights) << endl;
    return 0;
}
