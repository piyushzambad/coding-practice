//
//  main.cpp
//  word_ladder
//
//  Created by pzambad on 8/3/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;


class Solution {
private:
    unordered_set<string> dict;

    int distn(string str1, string str2) {
        int len = 0;
        for (int i = 0; i < str1.size(); i++) {
            len += str1[i] != str2[i];
        }
        return len;
    }
    
    int dfs(string beginWord, string endWord, vector<string> wordList, unordered_set<string> visited) {
        int _min = INT_MAX/2, len = 0;
        if (beginWord == endWord) {
            for (unordered_set<string>::iterator it = visited.begin(); it != visited.end(); it++) {
                cout << *it << "-->";
            }
            cout << endl;
            return 0;
        }
        
        for (int i = 0; i < wordList.size(); i++) {
            if ((distn(beginWord, wordList[i]) == 1) && (visited.find(wordList[i]) == visited.end())) {
                visited.insert(wordList[i]);
                len =  1 + dfs(wordList[i], endWord, wordList, visited);
                _min = min(_min, len);
                visited.erase(wordList[i]);
            }
        }
        return _min;
    }
    
    bool
    find_path_util(unordered_map<string, bool>& dict, string start, string end, vector<string>& res) {
        if (start == end) {
            //res.push(start);
            return true;
        }
       
        for (unordered_map<string, bool>::iterator it = dict.begin(); it != dict.end(); it++) {
            if (it->second == true) {
                continue;
            }
           
            if (distn(start, it->first) == 1) {
                cout << it->first << endl;
                res.push_back(it->first);
                dict[it->first] = true;
               
                if (!find_path_util(dict, it->first, end, res)) {
                    cout << "Rem" << it->first << endl;
                    dict[it->first] = false;
                    res.pop_back();
                } else {
                    return true;
                }
            }
        }
        return false;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = 0;
        unordered_set<string> visited;
        
        for (int i = 0; i < wordList.size(); i++) {
            dict.insert(wordList[i]);
        }

        len = 1 + dfs(beginWord, endWord, wordList, visited);
        return len == (INT_MAX / 2 + 1) ? 0 : len;
    }
    
    vector<string>
    find_path(vector<string> arr, string start, string end) {
        unordered_map<string, bool> dict;
        vector<string> res, res1;

        for (auto sz = 0; sz < arr.size(); sz++) {
            dict[arr[sz]] = false;
        }
        // [CAT, COT, DOT, DOG], "CAT" -> "DOG"
        dict[start] = true;
        res.push_back(start);
       
        if (find_path_util(dict, start, end, res)) {
            return res;
        } else {
            return res1;
        }
    }
};

int main(int argc, const char * argv[]) {
    string beginWord = "bot", endWord = "cog";
    vector<string> wordList = {"hot","bot", "eot","fot","zog", "zot","sot","cog"};
    class Solution A;
    vector<string> res;
    
    res = A.find_path(wordList, beginWord, endWord);
    
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    
    return 0;
}
