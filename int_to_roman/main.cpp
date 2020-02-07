//
//  main.cpp
//  int_to_roman
//
//  Created by pzambad on 10/20/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>
//#include <sstream>
#include <cstdio>


using namespace std;

unordered_map<char, int> umap = {{'I',1}, {'V',5}, {'X',10}, {'L', 50}, {'C',100}, {'D',500}, {'M', 1000}};

class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        
        if (num >= 1000) {
            res += 'M' + intToRoman(num-1000);
        } else if (num >= 990) {
            res += "XM" + intToRoman(num-990);
        } else if (num >= 950) {
            res += "CM" + intToRoman(num-900);
        } else if (num >= 900) {
            res += "CM" + intToRoman(num-900);
        } else if (num >= 500) {
            res += 'D' + intToRoman(num-500);
        } else if (num >= 490) {
            res += "XD" + intToRoman(num-490);
        } else if (num) {
            
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    const string temp = "/sys/class/cpld-qsfpdd/port-10/module_present";
    const string file_format ="/sys/class/cpld-qsfpdd/port-%d/module_present";
    string temp2;
    //string temp1 = "102";
    //char str[124];
    int x;
    //std::stringstream ss(temp);
    sscanf(temp.c_str(), file_format.c_str(), &x);
    //ss << temp.substr(strlen("/sys/class/cpld-qsfpdd/port-"), temp.find("/module_present")-strlen("/sys/class/cpld-qsfpdd/port-"));
    //ss >> x >> y;
    //sprintf ((temp2.c_str()), temp.c_str(), x);
    cout << x << endl;
    //std::cout << "Hello, World!\n";
    return 0;
}
