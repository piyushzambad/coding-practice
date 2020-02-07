//
//  main.cpp
//  group_anagrams
//
//  Created by pzambad on 6/23/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<string> temp;
        string temp_str;
        
        unordered_map<string, vector<string>> umap;
        
        for (int i = 0; i< strs.size(); i++) {
            temp_str = strs[i];
            sort(temp_str.begin(), temp_str.end());
            umap[temp_str].push_back(strs[i]);
        }
        
        for (unordered_map<string, vector<string>>::iterator it = umap.begin(); it != umap.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<string> str = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result;
    class Solution ga;
    
    result = ga.groupAnagrams(str);
    
    for (vector<vector<string>>::iterator it = result.begin(); it != result.end(); it++) {
        for (vector<string>::iterator it2 = it->begin(); it2 != it->end(); it2++) {
            cout << *it2 << " ";
        }
        cout << endl;
    }
    return 0;
}
