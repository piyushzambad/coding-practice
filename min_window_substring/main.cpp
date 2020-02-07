//
//  main.cpp
//  min_window_substring
//
//  Created by pzambad on 6/26/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> umap1;
        
        for (int i = 0; i < t.size(); i++) {
            if(umap1.find(t[i]) == umap1.end()) {
                umap1[t[i]] = 1;
            } else {
                umap1[t[i]] += 1;
            }
        }
        
        int j = 0, count = t.size();
        int minLen = s.size(), minStart = 0, start = 0;
        
        while (j < s.size()) {
            if (umap1.find(s[j]) != umap1.end() && umap1[s[j]] > 0) {
                count--;
            }
            if(umap1.find(s[j]) == umap1.end()) {
                umap1[s[j]] = -1;
            } else {
                umap1[s[j]] -= 1;
            }
            j++;
            
            while (count == 0) {
                if (j - start < minLen) {
                    minStart = start;
                    minLen = j - start;
                }
                
                if(umap1.find(s[start]) == umap1.end()) {
                    umap1[s[start]] = 1;
                } else {
                    umap1[s[start]] += 1;
                }
                
                if (umap1[s[start]] > 0)
                    count++;
                
                start++;
            }
        }
        return s.substr(minStart,minLen);
        /*
        unordered_map<char,int> umap1, umap2;
        int i, j;
        vector<pair<int, int>> res_arr;
        
        for (i = 0; i < t.length(); i++) {
            umap1[t[i]]++;
        }
        
        for(i=0; i<s.length() - t.length();i++) {
            umap2.clear();
            umap2 = umap1;
            
            for(j=i; j<s.length();j++) {
                if (umap2.find(s[j]) != umap2.end()) {
                    umap2[s[j]]--;
                    
                    if (umap2[s[j]] == 0) {
                        umap2.erase(s[j]);
                    }
                    
                    if (umap2.size() == 0) {
                        res_arr.push_back(make_pair(i, j));
                        break;
                    }
                }
            }
        }
        
        j = s.length();
        
        int vec_index = 0, min_index = 0;
        
        for(vector<pair<int, int>>::iterator it = res_arr.begin(); it!=res_arr.end(); it++, vec_index++) {
            cout << "[ " << it->first << ", " << it->second << " ]" << endl;
            
            if (j > (it->second - it->first)) {
                j = (it->second - it->first);
                min_index = vec_index;
            }
        }
        
        return s.substr(res_arr.at(min_index).first, res_arr.at(min_index).second - res_arr.at(min_index).first + 1);
         */
    }
};

int main(int argc, const char * argv[]) {
    string s = "ADOBECODEBANC", t = "ABC";
    class Solution temp;
    
    cout << temp.minWindow(s, t) << endl;
    
    return 0;
}
