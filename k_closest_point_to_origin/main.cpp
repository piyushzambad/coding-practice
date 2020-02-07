//
//  main.cpp
//  k_closest_point_to_origin
//
//  Created by pzambad on 8/11/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, int>> max_pq;
        vector<vector<int>> res;
        
        for (int i = 0; i < points.size(); i++) {
            max_pq.push(make_pair((pow(points[i][0],2) + pow(points[i][1],2)), i));
            
            if (max_pq.size() > K) {
                max_pq.pop();
            }
        }
        
        while (!max_pq.empty()) {
            res.push_back(points[max_pq.top().second]);
            max_pq.pop();
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
    int K = 2;
    
    class Solution A;
    
    vector<vector<int>> res;
    
    res = A.kClosest(points, K);
    
    for (int i = 0; i<res.size();i++) {
        cout << res[i][0] << "," << res[i][1] << endl;
    }
    return 0;
}
