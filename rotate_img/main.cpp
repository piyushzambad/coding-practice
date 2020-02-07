//
//  main.cpp
//  rotate_img
//
//  Created by pzambad on 8/11/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        if (N == 0)
            return;
        
        for(int i = 0; i <= N/2-1; i++) {
            for(int j = i; j < N-i-1; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[N-j-1][i];
                matrix[N-j-1][i] = matrix[N-i-1][N-j-1];
                matrix[N-i-1][N-j-1] = matrix[j][N-i-1];
                matrix[j][N-i-1] = temp;
            }
        }
    }
};


int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    class Solution A;
    A.rotate(matrix);
    
    for(int i =0; i<matrix.size(); i++) {
        for(int j = 0; j<matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
