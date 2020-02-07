/*
 * temp.cpp
 *
 *  Created on: Jun 22, 2019
 *      Author: pzambad
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    string temp;
    int **table;
    
public:
    Solution (string s) {
        temp = s;
        table = new int* [s.length()];
        int i, j;
        
        for (i = 0; i < s.length(); i++) {
            table[i] = new int [s.length()];
        }
        
        for (i = 0; i < s.length(); i++) {
            for (j = 0; j < s.length(); j++) {
                table[i][j] = 0;
            }
        }
    }
    
    ~Solution () {
        for (int i = 0; i < this->temp.length(); i++) {
            delete table[i];
        }
        delete table;
    }
    
    string print_string () {
        return this->temp;
    }
    
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int start = 0, end = 0, maxLen = 0;
        
        while (end < s.size()) {
            if (hash.find(s[end]) != hash.end()) {
                start = max(start, hash[s[end]] + 1);
            }
            if (end - start + 1 > maxLen) {
                maxLen = end - start + 1;
            }
            hash[s[end]] = end;
            end++;
        }
        
        return maxLen;
    }
    /*
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int i, j, maxLen, temp_i, temp_j;
        
        for (i = 0; i < s.length(); i++) {
            maxLen = 1;
            hash.clear();
            hash[s[i]] = 1;
            
            this->table[i][i] = maxLen;
            
            for (j = i + 1; j < s.length(); j++) {
                if (hash.find(s[j]) == hash.end()) {
                    maxLen++;
                    hash[s[j]] = 1;
                    this->table[i][j] = maxLen;
                } else {
                    break;
                }
            }
        }
        
        maxLen = this->table[0][0];
        temp_i = 0;
        temp_j = 0;
        
        for (i = 0; i < s.length(); i++) {
            for (j = i; j < s.length(); j++) {
                if (this->table[i][j] >= maxLen) {
                    maxLen = this->table[i][j];
                    temp_i = i;
                    temp_j = j;
                }
            }
        }
        
        cout << "Longest substring is: ";
        for (i = temp_i; i <= temp_j; i++) {
            cout << s[i];
        }
        
        cout << endl;
        
        return maxLen;
    }
    
     int lengthOfLongestSubstring(string s) {
     unordered_map<char, int> hash;
     int i, j, maxLen, ans;
     
     ans = 0;
     for (i = 0; i < s.length(); i++) {
     maxLen = 1;
     hash.clear();
     hash[s[i]] = 1;
     
     for (j = i + 1; j < s.length(); j++) {
     if (hash.find(s[j]) == hash.end()) {
     maxLen++;
     hash[s[j]] = 1;
     } else {
     break;
     }
     }
     if (ans < maxLen) {
     ans = maxLen;
     }
     }
     
     return ans;
     }
     */
};

int main() {
    class Solution soln ("tmmzuxt");
    int ans;
    
    ans = soln.lengthOfLongestSubstring(soln.print_string());
    
    cout << "lengthOfLongestSubstring in " << soln.print_string() << " is " << ans << endl;
    
    return 0;
}

