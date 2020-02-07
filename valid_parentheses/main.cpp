//
//  main.cpp
//  valid_parentheses
//
//  Created by pzambad on 8/4/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
private:
    char closing(char c) {
        switch (c) {
            case ')':
                return '(';
            case ']':
                return '[';
            case '}':
                return '{';
            default:
                return 0;
        }
    }
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (int i = 0; i<s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if (st.empty())
                    return false;
                char temp = st.top();
                st.pop();
                if (temp != closing(s[i])) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main(int argc, const char * argv[]) {
    class Solution A;
    
    cout << A.isValid("(]") << endl;
    return 0;
}
