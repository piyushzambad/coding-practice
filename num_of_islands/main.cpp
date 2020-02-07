//
//  main.cpp
//  num_of_islands
//
//  Created by pzambad on 6/30/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void numIslandsUtil(vector<vector<char>>& grid, int i, int j, vector<vector<char>>::size_type M, vector<char>::size_type N, char& reg) {
        if (i-1 >= 0 && grid[i-1][j] == '1') {
            grid[i-1][j] = reg;
            numIslandsUtil(grid, i-1, j, M, N, reg);
        }
        if (j-1 >= 0 && grid[i][j-1] == '1') {
            grid[i][j-1] = reg;
            numIslandsUtil(grid, i, j-1, M, N, reg);
        }
        if (i+1 < M && grid[i+1][j] == '1') {
            grid[i+1][j] = reg;
            numIslandsUtil(grid, i+1, j, M, N, reg);
        }
        if (j+1 < N && grid[i][j+1] == '1') {
            grid[i][j+1] = reg;
            numIslandsUtil(grid, i, j+1, M, N, reg);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        char reg = '2';
        vector<vector<char>>::size_type M = grid.size();
        vector<char>::size_type N = grid[0].size();
        
        int k, l;
        for (k = 0; k < M; k++) {
            for (l = 0; l < N; l++) {
                if (grid[k][l] == '1') {
                    grid[k][l] = reg;
                    numIslandsUtil(grid, k, l, M, N, reg);
                    reg++;
                }
            }
        }
        
        return reg - '2';
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<char>> islands = {{'1', '1', '1'}, {'0', '1', '0'}, {'1', '1', '1'}};
    class Solution A;
    
    cout << A.numIslands(islands) << endl;
    
    return 0;
}
