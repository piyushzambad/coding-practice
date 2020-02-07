//
//  main.cpp
//  length_Of_Longest_Substring_K_Distinct
//
//  Created by pzambad on 10/6/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        if (k==0)
            return 0;
        
        int final_len = 0, final_start = 0, flag = 0;
        int start = 0, end = 0, count = 0;
        unordered_map<char, int> umap;
        
        while (end < s.size()) {
            flag = 0;
            if (umap.find(s[end]) == umap.end()) {
                count++;
            }
            umap[s[end]]++;
            while((count > k || (end == s.size() - 1)) && (start < s.size())) {
                if (end-start+((end == s.size() - 1) && (count <= k)) > final_len) {
                    final_len = end-start+((end == s.size() - 1) && (count <= k));
                    final_start = start;
                }
                
                umap[s[start]]--;
                
                if (umap[s[start]] == 0) {
                    umap.erase(s[start]);
                    count--;
                }
                start++;
            }
            end++;
        }
        cout << s.substr(final_start, final_len) << endl;
        
        return final_len;
    }
};

int main(int argc, const char * argv[]) {
    string s = "aba";
    int k = 1;
    class Solution A;
    
    cout << A.lengthOfLongestSubstringKDistinct(s, k) << endl;
    
    return 0;
}
