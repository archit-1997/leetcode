/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : longestCommonPrefix.cpp
 * @created     : Saturday Aug 21, 2021 17:08:42 IST
 */

#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        
        TrieNode(){}

        unordered_map<char,TrieNode*> children;
        bool eow;
};

class Trie{
public:

    TrieNode* root;

    Trie(){
        root=new TrieNode();
        root->eow=false;
    }

    void insert(string s){
        TrieNode* cur=root;
        int n=s.size();
        for(int i=0;i<n;i++){
            //we find the character
            char ch=s[i];

            //if this character is not present : we will create a new node
            if(cur->children[ch]==NULL)
                cur->children[ch]=new TrieNode();
            cur=cur->children[ch];
        }
        //we will have to the eow here as true
        cur->eow=true;
    }

    string findLCP(){
        TrieNode* cur=root;
        string ans="";
        while(1){
            //eow=true : map.size()>1
            if(cur->eow==true || cur->children.size()>1)
                return ans;
            auto m=cur->children;
            auto it=m.begin();
            char ch=it->first;
            ans=ans+ch;
            cur=cur->children[ch];
        }
        return ans;
    }
};

class Solution {
public:

    string longestCommonPrefix(vector<string>& strs) {
        Trie t;
        int n=strs.size();
        for(int i=0;i<n;i++){
            string s=strs[i];
            t.insert(s);
        }
        string ans=t.findLCP();
        return ans;
    }
};


void init(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int main(){
    init();

    int n;cin>>n;

    vector<string> v(n);

    for(int i=0;i<n;i++)
        cin>>v[i];

    Solution s;
    string ans=s.longestCommonPrefix(v);
    cout<<ans;

}
