//
//  main.cpp
//  merge_intervals
//
//  Created by pzambad on 7/13/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int i = 0, j = 0, k = 0;
        
        sort(intervals.begin(), intervals.end());
        
        for (vector<vector<int>>::iterator it = intervals.begin(); it != intervals.end(); it++) {
            cout << "[" << it->at(0) << " " << it->at(1) << "],";
        }
        cout << endl;

        while (j < intervals.size()) {
            vector<int> temp;
            temp.clear();
            while (j+1 < intervals.size() && (intervals[k][1] >= intervals[j+1][0])) {
                if (intervals[k][1] < intervals[j+1][1])
                    k = j+1;
                j++;
            }
            temp.push_back(intervals[i][0]);
            temp.push_back(intervals[k][1] < intervals[j][1] ? intervals[j][1] : intervals[k][1]);
            res.push_back(temp);
            k = j+1;
            i = k;
            j = i;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> intervals = {{1,4}, {0,2}, {3,5}}, res;
    class Solution A;
    
    res = A.merge(intervals);
    
    for (vector<vector<int>>::iterator it = res.begin(); it != res.end(); it++) {
        cout << "[" << it->at(0) << " " << it->at(1) << "],";
    }
    cout << endl;
    
    return 0;
}
