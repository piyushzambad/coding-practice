//
//  main.cpp
//  trapping_rain_water
//
//  Created by pzambad on 7/27/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size(), 0);
        vector<int> right(height.size(), 0);
        int ans = 0;
        
        left[0] = height[0];
        for(int i = 1; i < height.size(); i++) {
            left[i] = max(left[i-1], height[i]);
        }
        
        right[height.size()-1] = height[height.size()-1];
        for(int i = height.size() - 2; i >= 0; i--) {
            right[i] = max(right[i+1], height[i]);
        }

        for(int i = 0; i < height.size(); i++) {
            ans += min(left[i], right[i]) - height[i];
        }

        return ans;
        /*
        int res = 0, temp = 0, i = 0, j = 0;
        
        for (i = 0; i < height.size() - 1; i=j) {
            temp = 0;
            for (j = i+1; j < height.size(); j++) {
                if (height[j] < height[i]) {
                    temp += height[i] - height[j];
                } else {
                    break;
                }
            }
            if (j != height.size()) {
                res += temp;
                cout << "i = " << i << " j = "  << j << " temp = " << temp << " res = " << res << endl;
            } else {
                j = i+1;
            }
        }
        return res;
         */
    }
};

int main(int argc, const char * argv[]) {
    vector<int> height = {4,2,3};
    class Solution A;
    
    std::cout << A.trap(height) << endl;
    
    return 0;
}
