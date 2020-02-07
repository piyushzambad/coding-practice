//
//  main.cpp
//  unique_candies
//
//  Created by pzambad on 10/11/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int
uniq_candies(vector<int> S) {
    int uniq_candies = 0;
    int N = S.size();
    unordered_set<int> uset;
    
    for (int i = 0; i < N; i++) {
        if (uset.find(S[i]) == uset.end()) {
            uniq_candies++;
            uset.insert(S[i]);
        }
    }
    
    return ((uniq_candies > (N/2)) ? (N/2) : uniq_candies);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
