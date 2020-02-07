//
//  main.cpp
//  temp2
//
//  Created by pzambad on 11/25/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class temp {
public:
    static vector<uint32_t> VEC;
    
    void print_vec(vector<uint32_t> vec = VEC);
    void print_vec2();
};

vector<uint32_t> temp::VEC = {1,2,3};

void temp::print_vec2() {
    throw 2;
}

void temp::print_vec(vector<uint32_t> vec) {
    print_vec2();
    
    cout << "Hello" << endl;
    /*for(auto i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;*/
    
}

void fn2() {
  throw 10;

  cout << "In fn2" << endl;
}

void fn1() {
  fn2();

  cout << "In fn1" << endl;
}

int main(int argc, const char * argv[]) {
    string key = "eth-1/1/1";
    cout << key.find_last_of("/") << " " << key.substr(key.find_last_of("/")+1) << endl;
//    try {
//     int sz = 0, n = stoi(key.substr(key.find_last_of("/")));
//    cout << sz << " " << n <<  " "  << key.substr(key.find_last_of("/")) << endl;
//    } catch (exception& e) {
//        cout << e.what();
//    }
    
    
    /*try {
        fn1();
    } catch (...) {
        cout << "Caught exception." << endl;
    }*/
    
    /*    temp obj;
    vector<uint32_t> vec = {1,2,3,4,5};
    
    obj.print_vec();
    obj.print_vec(vec);*/
    return 0;
}
