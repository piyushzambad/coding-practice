//
//  main.cpp
//  roman_to_int
//
//  Created by pzambad on 6/22/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int i, ans = 0;
        unordered_map<char, int> roman_to_int(        {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}});
        for (i=0; i<s.length(); i++) {
            if (i < s.length() - 1 && s[i] == 'I' && s[i+1] == 'V') {
                i+=1;
                ans += roman_to_int[s[i]] - roman_to_int[s[i-1]];
            } else if (i < s.length() - 1 && s[i] == 'I' && s[i+1] == 'X') {
                i+=1;
                ans += roman_to_int[s[i]] - roman_to_int[s[i-1]];
            } else if (i < s.length() - 1 && s[i] == 'X' && s[i+1] == 'L') {
                i+=1;
                ans += roman_to_int[s[i]] - roman_to_int[s[i-1]];
            } else if (i < s.length() - 1 && s[i] == 'X' && s[i+1] == 'C') {
                i+=1;
                ans += roman_to_int[s[i]] - roman_to_int[s[i-1]];
            } else if (i < s.length() - 1 && s[i] == 'C' && s[i+1] == 'D') {
                i+=1;
                ans += roman_to_int[s[i]] - roman_to_int[s[i-1]];
            } else if (i < s.length() - 1 && s[i] == 'C' && s[i+1] == 'M') {
                i+=1;
                ans += roman_to_int[s[i]] - roman_to_int[s[i-1]];
            } else {
                ans += roman_to_int[s[i]];
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    class Solution roman_to_integer;
    
    cout << roman_to_integer.romanToInt("IVV") << endl;
    
    return 0;
}
