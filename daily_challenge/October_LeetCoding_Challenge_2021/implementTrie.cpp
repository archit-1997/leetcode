/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : implementTrie.cpp
 * @created     : Monday Aug 23, 2021 10:48:13 IST
 */

#include <bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    unordered_map<char,TrieNode*> children;
    bool eow;

    TrieNode(){
        eow=false;
    }
};

class Trie {
public:
    TrieNode* root;

    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur=root;
        int n=word.size();

        for(int i=0;i<n;i++){
            char ch=word[i];
            if(cur->children[ch]==NULL)
                cur->children[ch]=new TrieNode();
            cur=cur->children[ch];
        }
        cur->eow=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur=root;
        int n=word.size();
        for(int i=0;i<n;i++){
            char ch=word[i];
            if(cur->children[ch]==NULL)
                return false;
            cur=cur->children[ch];
        }
        return (cur!=NULL && cur->eow==true);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur=root;
        int n=prefix.size();

        for(int i=0;i<n;i++){
            char ch=prefix[i];
            
            if(cur==NULL)
                return false;
            //if we are unable to locate this character
            if(cur->children[ch]==NULL)
                return false;

            cur=cur->children[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
