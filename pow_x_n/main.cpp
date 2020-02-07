//
//  main.cpp
//  pow_x_n
//
//  Created by pzambad on 7/13/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;
        if (n < 0) {
            n = -n;
            x = 1/x;
        }
        
        return (n%2 == 0) ? myPow(x*x, n/2) : x*myPow(x*x, n/2);
    }
};

int main(int argc, const char * argv[]) {
    class Solution A;
    cout << A.myPow(2.0, 15) << endl;
    return 0;
}
