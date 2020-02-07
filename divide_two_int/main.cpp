//
//  main.cpp
//  divide_two_int
//
//  Created by pzambad on 7/13/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long quot = 0;
        int bit_op = 0;
        int sign = (dividend > 0) ^ (divisor > 0);
        
        if (dividend < 0) {
            dividend = 0 - dividend;
        }
        if (divisor < 0) {
            divisor = 0 - divisor;
        }
        
        while (dividend >= divisor) {
            while (dividend > (divisor << (bit_op+1))) {
                bit_op++;
            }
            quot += 1 << bit_op;
            dividend -= (divisor << bit_op);
            bit_op = 0;
        }
        return sign ? 0 - quot : quot;
    }
};

int main(int argc, const char * argv[]) {
    class Solution A;

    cout << A.divide(-2147483648, -1) << endl;
    
    return 0;
}
