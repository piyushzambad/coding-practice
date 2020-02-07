//
//  main.cpp
//  alien_dict
//
//  Created by pzambad on 10/13/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<string>::size_type N = words.size();
        string res = "";
        unordered_set<char> uset;
        
        for (int i = 0; i< N; i++) {
            if (uset.find(words[i][0]) == uset.end()) {
                res.push_back(words[i][0]);
                uset.insert(words[i][0]);
            }
        }
        
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
