//
//  main.cpp
//  letter-comb-of-phone-num
//
//  Created by pzambad on 7/4/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
private:
    unordered_map<char, string> num_to_str {{'1', ""},{'2', "abc"},{'3', "def"}, {'4', "ghi"}, {'5',"jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}, {'0', ""}};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string::size_type n = digits.size();
        queue<string> que;
        string temp;
        
        if (n == 0) {
            return res;
        }
        
        que.push("");
        
        int i = 0;
        
        for (i = 0; i < n; i++) {
            temp = num_to_str[digits[i]];
            
            queue<string>::size_type que_sz = que.size();
            
            for (int l = 0; l < que_sz; l++) {
                string temp2 = que.front();
                que.pop();
                
                for(int j = 0; j < temp.size(); j++) {
                    que.push(temp2 + temp[j]);
                }
            }
        }
        
        queue<string>::size_type que_sz = que.size();
        
        for (i = 0; i < que_sz; i++) {
            temp = que.front();
            que.pop();
            res.push_back(temp);
        }
        
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<string> res;
    class Solution A;
    //for (int i = 0; i < 1000; i++) {
    res = A.letterCombinations("234568");
    //}
    
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl << res.size() << endl;
    return 0;
}
