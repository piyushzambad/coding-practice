//
//  main.cpp
//  lru_cache
//
//  Created by pzambad on 7/14/19.
//  Copyright © 2019 pzambad. All rights reserved.
//

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    int csize;
    list<pair<int, int>> deq;
    unordered_map<int, list<pair<int, int>>::iterator> umap;
    
public:
    LRUCache(int capacity) {
        csize = capacity;
    }
    
    int get(int key) {
        int ret_val = ((umap.find(key) == umap.end()) ? -1 : umap[key]->second);
        
        if (umap.find(key) != umap.end()) {
            deq.erase(umap[key]);
            umap.erase(key);
            
            deq.push_front(make_pair(key, ret_val));
            umap[key] = deq.begin();
        }
                
        return ret_val;
    }
    
    void put(int key, int value) {
        if (deq.size() < csize) {
            if (umap.find(key) != umap.end()) {
                deq.erase(umap[key]);
                umap.erase(key);
            }
            
            deq.push_front(make_pair(key, value));
            umap[key] = deq.begin();
        } else {
            if (umap.find(key) == umap.end()) {
                umap.erase(deq.back().first);
                deq.pop_back();
            } else {
                deq.erase(umap[key]);
                umap.erase(key);
            }
            deq.push_front(make_pair(key, value));
            umap[key] = deq.begin();
        }        
    }
};


int main(int argc, const char * argv[]) {
    LRUCache* cache = new LRUCache( 10 /* capacity */ );
    
    cache->put(7, 28);
    //cout << cache->get(39) << endl;
    cache->put(7, 1);
    //cout << cache->get(129) << endl;
    //cout << cache->get(115) << endl;
    //cout << cache->get(112) << endl;
    cache->put(8, 15);
    cout << cache->get(6) << endl;       // returns -1 (not found)
    cache->put(10, 27);
    cache->put(8, 10);
    cout << cache->get(8) << endl;
    cache->put(6, 29);
    cache->put(1, 9);
    cout << cache->get(6) << endl;
    cache->put(10, 7);
    //cache->put(33, 58);
    cout << cache->get(1) << endl;

    return 0;
}
