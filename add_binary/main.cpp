//
//  main.cpp
//  add_binary
//
//  Created by pzambad on 6/23/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void mySumBin(char a, char b, char c, char& sum, char& carry) {
        sum = (((a-'0') + (b-'0') + (c-'0'))%2) + '0';
        carry = (((a-'0') + (b-'0') + (c-'0'))/2) + '0';
    }
    
    string addBinary(string a, string b) {
        string temp_a = a, temp_b = b;

        unsigned long strSz = a.size() > b.size() ? a.size() : b.size();
        string result(strSz+1, '0');
        char sum, carry;
        
        int i;
        
        if (a.size() > b.size()) {
            for (i=0; i < a.size() - b.size(); i++) {
                temp_b.insert(0, "0");
            }
        } else {
            for (i=0; i < b.size() - a.size(); i++) {
                temp_a.insert(0, "0");
            }
        }
        
        for (i=strSz-1; i>=0; i--) {
            mySumBin(temp_a[i], temp_b[i], result[i+1], sum, carry);
            result[i+1] = sum;
            result[i] = carry;
        }
        size_t startpos = result.find_first_not_of("0");
        
        if (string::npos != startpos) {
            return result.substr(startpos);
        }
        
        return "0";
    }
};

int main(int argc, const char * argv[]) {
    string a = "11", b = "1", res;
    
    class Solution AB;
    res = AB.addBinary(a, b);
    
    cout << res << endl;
    return 0;
}
