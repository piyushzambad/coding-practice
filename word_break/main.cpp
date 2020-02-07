//
//  main.cpp
//  word_break
//
//  Created by pzambad on 7/14/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool dict_has_str(vector<string>& wordDict, string s) {
        for(vector<string>::iterator it = wordDict.begin(); it!= wordDict.end(); it++) {
            if (*it == s) {
                return true;
            }
        }
        return false;
    }
    bool wordBreakUtil(string s, vector<string>& wordDict, int low, vector<char>& mem) {
        int res = false;
        if (low >= s.size()) {
            return true;
        }
        
        if(mem[low]!= -1) {
            return mem[low];
        }
        
        for (int i = low; i < s.size(); i++) {
            if (dict_has_str(wordDict, s.substr(low, i-low+1))) {
                res |= wordBreakUtil(s, wordDict, i+1, mem);
            }
            if (res)
                return true;
        }

        mem[low] = 0;
        return res;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<char> mem(s.size(),-1);
        return wordBreakUtil(s, wordDict, 0, mem);
    }
};

int main(int argc, const char * argv[]) {
    vector<string> dict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    class Solution A;
    
    cout << A.wordBreak(s, dict) << endl;
    return 0;
}
