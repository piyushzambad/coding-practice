//
//  main.cpp
//  valid_palindrome_iii
//
//  Created by pzambad on 10/6/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool validPalindromeUtil(const string& s, int index1, int index2) {
        int i = index1, j = index2;
        
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0, j = s.size()-1;
        
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                return validPalindromeUtil(s, i+1, j) || validPalindromeUtil(s, i, j-1);
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
