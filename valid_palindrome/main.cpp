//
//  main.cpp
//  valid_palindrome
//
//  Created by pzambad on 10/5/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        
        while (i<j) {
            while (!isalnum(s[i]) && (i < j)) {
                i++;
            }
            while (!isalnum(s[j]) && (i < j)) {
                j--;
            }
            
            if (tolower(s[i]) == tolower(s[j])) {
                i++;
                j--;
                continue;
            } else {
                return false;
            }
        }

        return true;

    }

};

int main(int argc, const char * argv[]) {
    string s = "A man, a plan, a canal: Panama";
    class Solution A;
    
    cout << A.isPalindrome(s) << endl;
    return 0;
}
