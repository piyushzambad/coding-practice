//
//  main.cpp
//  remove_invalid_paranthesis
//
//  Created by pzambad on 7/6/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
private:
    bool isValidParantheses(string s) {
        string::size_type n = s.size();
        int open_b = 0, close_b = 0;
        
        for(int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == ')') {
                if (s[i] == '(') {
                    open_b++;
                } else {
                    close_b++;
                }
                if (close_b > open_b) {
                    return false;
                }
            } else {
                continue;
            }
        }
        return (open_b == close_b);
    }
    
    bool isAllchar(string s) {
        for (int i = 0; i < s.size(); i++) {
            if ((s[i] == ')') || (s[i] == '(') ) {
                return false;
            }
        }
        return true;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        queue<string> que;
        set<string> set_str;
        
        bool path = false;
        
        que.push(s);
        set_str.insert(s);

        while (!que.empty()) {
            queue<string>::size_type n = que.size();
            for (int i = 0; i < n; i++) {
                string temp = que.front();
                que.pop();
                
                if (isValidParantheses(temp)) {
                    res.push_back(temp);
                    path = true;
                    if (isAllchar(temp))
                        break;
                }
                
                for (int i = 0; i < temp.size(); i++) {
                    if (s[i] == '(' || s[i] == ')') {
                        string temp2 = temp.substr(0,i) + temp.substr(i+1);
                        if (set_str.find(temp2) == set_str.end()) {
                            que.push(temp2);
                            set_str.insert(temp2);
                        }
                    }
                }
            }
            if (path)
                break;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    string s = "(((k()((";
    class Solution A;
    vector<string> res;
    
    res = A.removeInvalidParentheses(s);
    
    for (int i = 0; i<res.size(); i++) {
        cout << res[i] << endl;
    }
    
    return 0;
}
