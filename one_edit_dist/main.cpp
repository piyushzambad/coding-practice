//
//  main.cpp
//  one_edit_dist
//
//  Created by pzambad on 6/26/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool check_for_delete(string s, string t) {
        int i = 0, flag = 0;
        
        while (i < t.length()) {
            if (flag == 2) {
                return false;
            }
            else if ((flag == 0 && s[i] != t[i]) || (flag > 0 && s[i+1] != t[i])) {
                flag++;
            } else {
                i++;
            }
        }
        return (flag == 0) || (flag == 1 && s[i] == t[i-1]);
    }
    
    bool check_for_replace(string s, string t) {
        int i = 0, flag = 0;
        
        while (i < s.length()) {
            if (s[i] != t[i]) {
                flag++;
            }
            i++;
        }
        return flag == 1;
    }
    
    bool isOneEditDistance(string s, string t) {
        int size_s = s.size(), size_t = t.size();
        
        if (size_s == size_t+1) {
            return check_for_delete(s, t);
        } else if (size_s == size_t-1) {
            return check_for_delete(t, s);
        } else if (size_s == size_t) {
            return check_for_replace(s, t);
        } else {
            return false;
        }
    }
};

int main(int argc, const char * argv[]) {
    string s = "cab", t = "ad";
    class Solution A;
    cout << A.isOneEditDistance(s, t) << endl;
    
    return 0;
}
