/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : implementLRUCache.cpp
 * @created     : Saturday Aug 14, 2021 16:08:19 IST
 */

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    list<int> l;
    unordered_map<int,int> map;
    unordered_map<int,list<int>::iterator> reference;
    int len;
    LRUCache(int capacity) {
        l.clear();
        map.clear();
        reference.clear();
        len=capacity;
    }
    
    int get(int key) {
       //we need to check whether this key is present in the map or not
       if(map.find(key)!=map.end()){
           int ans=map[key];
            //this means that they key exists
            //find the reference to this key and delete
            auto it=reference[key];
            l.erase(it);
            //insert this value at the front
            l.push_front(key);
            reference[key]=l.begin();
            //we just need to return the value for this key
            return map[key];
       }
       //if it does not exits
       return -1;
    }
    
    void put(int key, int value) {
        //first check if this exits or not
        if(map.find(key)!=map.end()){
            //this means that the key exist
            //find the reference to this key and remove it
            auto it=reference[key];
            l.erase(it);
            l.push_front(key);
            reference[key]=l.begin();
            map[key]=value;
        }
        else{
            //this means this does not exist
            int size=l.size();
            if(size>=len){
                //we need to pop the element which is at the last
                int lastVal=l.back();
                l.pop_back();
                //remove form the map as well as from the reference
                map.erase(lastVal);
                reference.erase(lastVal);
            }
            //we can just insert this into the list
            l.push_front(key);
            reference[key]=l.begin();
            map[key]=value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

