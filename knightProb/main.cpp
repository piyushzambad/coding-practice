//
//  main.cpp
//  knightProb
//
//  Created by pzambad on 7/28/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
private:
    int dir[8][2] = {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    
    double knightProbabilityUtil(int N, int K, int movesLeft, int r, int c) {
        if (r > N-1 || c > N-1 || r < 0 || c < 0) {
            //movesLeft = 0;
            return 0.0;
        }
        
        if (movesLeft == 0) {
            return 1.0;
        }
        
        double prob = 0.0;

        for(int i = 0;i < 8; i++){
            prob += (1.0/8.0) * knightProbabilityUtil(N,K, movesLeft-1,r + dir[i][0],c+dir[i][1]);
        }
        
        return prob;
    }
public:
    double knightProbability(int N, int K, int r, int c) {
        double prob = 0.0;
        int movesLeft = K;

        prob = knightProbabilityUtil(N,K, movesLeft,r,c);
        
        return prob;
    }
};

int main(int argc, const char * argv[]) {
    class Solution A;
    cout << A.knightProbability(3, 2, 0, 0) << endl;
    return 0;
}
