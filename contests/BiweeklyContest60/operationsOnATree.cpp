/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : operationsOnATree.cpp
 * @created     : Sunday Sep 05, 2021 17:16:17 IST
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define P pair<int,int>

void init(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

class LockingTree {
public:
    unordered_map<int, vector<int>> descendents;
    vector<vector<int>> Node;
    /*
        Node[i][0] = parent[i]
        Node[i][1] = -1; (means unlocked)
        Node[i][1] = x;  (means locked by user x)
    */
    int n;
    LockingTree(vector<int>& parent) {
        n = parent.size();
        Node.resize(n, vector<int>(2, -1));
        
        Node[0][0] = -1; //root has no parent
        for(int i = 1; i<n; i++) {
            Node[i][0] = parent[i];
            descendents[parent[i]].push_back(i);            
        }
    }
    
    bool lock(int num, int user) {
        if(Node[num][1] != -1) return false;
        
        Node[num][1] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(Node[num][1] != user) return false;
        
        Node[num][1] = -1;
        return true;
    }
    
    //Condition-2 (Atleast one descendent should be locked)
    void checkDescendents(int num, bool& atleastOne) {
        if(descendents.count(num) == 0 || descendents[num].size() == 0)
            return;
        
        for(int& x : descendents[num]) {
            if(Node[x][1] != -1) {
                atleastOne = true;
                return;
            }
            checkDescendents(x, atleastOne);
        }
    }
    
    //Condition-3 (Check if any ancestor is locked)
    bool IsAnyAncestorLocked(int& num) {
        if(num == -1)
            return false; //you reached end and found none locked
        
        return Node[num][1] != -1 || IsAnyAncestorLocked(Node[num][0]);
    }
    
    void unlockDescendents(int num) {
        if(descendents.count(num) == 0 || descendents[num].size() == 0)
            return;
        
        for(int& x : descendents[num]) {
            Node[x][1] = -1;
            unlockDescendents(x);
        }
    }
    
    bool upgrade(int num, int user) {
        //condition : 1
        if(Node[num][1] != -1) return false;
        
        
        //condition : 2
        bool atleastOne = false;
        checkDescendents(num, atleastOne);
        //If no node was locked, return false
        if(!atleastOne) return false;
        
        
        //condition : 3
        if(IsAnyAncestorLocked(Node[num][0])) return false;
        
        
        //Do the rest
        unlockDescendents(num);
        Node[num][1] = user;
        return true;
    }
};
/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
