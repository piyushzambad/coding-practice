//
//  main.cpp
//  most_common_word
//
//  Created by pzambad on 8/11/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    bool find_in_banned(vector<string> banned, string str) {
        for (int i = 0; i<banned.size(); i++) {
            if (banned[i] == str) {
                return true;
            }
        }
        return false;
    }

public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string res;
        unordered_map<string, int> umap;
        int max = 0;
        string::size_type pos = 0, pre_pos = 0;
        
        for (int i = 0; i < paragraph.size(); i++) {
            if (isalpha(paragraph[i])) {
                paragraph[i] = tolower(paragraph[i]);
            } else {
                paragraph[i] = ' ';
            }
            
        }
        while (pos != string::npos && pre_pos != string::npos) {
            pos = paragraph.find(" ", pre_pos);
            
            string data;

            data = paragraph.substr(pre_pos, pos-pre_pos);

            cout << pos << " " << data << endl;
            umap[data]++;
            pre_pos = paragraph.find_first_not_of(" ", pos+1);
        }
        
        for (unordered_map<string, int>::iterator it = umap.begin(); it != umap.end(); it++) {
            if (it->second > max && !find_in_banned(banned, it->first)) {
                res = it->first;
                max = it->second;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned = {"hit"};

    class Solution A;
    
    cout << A.mostCommonWord(paragraph, banned) << endl;
    return 0;
}
