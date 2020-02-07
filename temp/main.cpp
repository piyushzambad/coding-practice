//
//  main.cpp
//  temp
//
//  Created by pzambad on 6/25/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class temp {
public:
    temp() {
        cout << "Constructor called!" << endl;
    }
    
};

int print_hello(int i) {
    if (i == 0) {
        throw logic_error("Throwing exception 0");
    } else {
        throw logic_error("Throwing exception 1");
    }
    return 0;
}

//#define REGISTER_GPROCESS(classname) classname __godiva_##classname;

class Solution {
public:
    bool closedIslandUtil(vector<vector<int>>& grid, int i, int j, int R, int C, vector<vector<bool>>& visited) {
        visited[i][j] = true;
        cout << "Vis " << i << " " << j << endl;
        
        if ((i == 0) || (i == R - 1) || (j == 0) || (j == C - 1)) {
            return false;
        }
        
        int ans = true;
        
        if (!visited[i+1][j] && (grid[i+1][j] == 0)) {
            ans = closedIslandUtil(grid, i+1, j, R, C, visited) && ans;
        }
        
        if (!visited[i-1][j] && (grid[i-1][j] == 0)) {
            ans = closedIslandUtil(grid, i-1, j, R, C, visited) && ans;
        }
        
        if (!visited[i][j+1] && (grid[i][j+1] == 0)) {
            ans = closedIslandUtil(grid, i, j+1, R, C, visited) && ans;
        }
        
        if (!visited[i][j-1] && (grid[i][j-1] == 0)) {
            ans = closedIslandUtil(grid, i, j-1, R, C, visited) && ans;
        }

        return ans;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c, ans = 0;
        
        if (r > 0) {
            c = grid[0].size();
        } else {
            return 0;
        }
        vector<vector<bool>> visited(r, vector<bool>(c,false));
        
        for (int i = 1; i < r-1; i++) {
            for (int j = 1; j < c-1; j++) {
                if (!visited[i][j] && grid[i][j] == 0) {
                    if (closedIslandUtil(grid, i, j, r, c, visited)) {
                        cout << "Success" << i << " " << j << endl;
                        ans++;
                    } else {
                        cout << "Fail: " << i << " " << j << endl;
                    }
                }
            }
        }
        
        return ans;
    }
};
    
int main(int argc, const char * argv[]) {
    vector<vector<int>> grid = {{1,1,1,1,1,1,0,0,0,0},{1,1,1,0,0,1,0,1,0,1},{1,1,1,0,1,1,0,1,1,0}};
    
    /*
    0,0,1,1,0,1,0,0,1,0
    1,1,0,1,1,0,1,1,1,0
    1,0,1,1,1,0,0,1,1,0
    0,1,1,0,0,0,0,1,0,1
    0,0,0,0,0,0,1,1,1,0
    0,1,0,1,0,1,0,1,1,1
    1,0,1,0,1,1,0,0,0,1
    1,1,1,1,1,1,0,0,0,0
    1,1,1,0,0,1,0,1,0,1
    1,1,1,0,1,1,0,1,1,0
    */
    class Solution A;
    
    cout << A.closedIsland(grid) << endl;
    //vec = vector<vector<int>>{{1,2},{3,4}};
    /*
    int j = 0;
    try {
        if (j == 1) {
            print_hello(0);
        } else {
            print_hello(1);
        }
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    */
    //REGISTER_GPROCESS(temp);
    /*
    vector<int> nums = {4,7,1,2,3,10};
    priority_queue<int, vector<int>, greater<int>> min_pq (nums.begin(), nums.end());
    priority_queue<int> max_pq(nums.begin(), nums.end());
    
    int N = nums.size(), k = 2;
    
    for(int i = 0; i < N - k; i++) {
        min_pq.pop();
    }
    
    for(int i = 0; i < k - 1; i++) {
        max_pq.pop();
    }
    
    cout << min_pq.top() << " " << max_pq.top() << endl;
     */
    /*char A[] = "Hello";
    
    strcpy(A, "hel");
    cout << strcmp(A, "Hello") << endl;*/
    /*int i = INT_MIN, j;
    ++i;
    j = -i;
    
    cout << i << " " << j << endl;
*/
    return 0;
}
