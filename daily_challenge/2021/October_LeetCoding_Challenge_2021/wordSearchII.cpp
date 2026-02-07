/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : wordSearchII.cpp
 * @created     : Monday Aug 23, 2021 11:46:53 IST
 */

#include <bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    unordered_map<char,TrieNode*> children;
    bool eow;
    string word;

    TrieNode(){
        eow=false;
        word="";
    }
};

class Trie{
public:
    TrieNode* root;

    Trie(){
        root=new TrieNode();
    }

    void insert(string s){
        TrieNode* cur=root;
        int n=s.size();

        for(int i=0;i<n;i++){
            char ch=s[i];
            if(cur->children[ch]==NULL)
                cur->children[ch]=new TrieNode();
            cur=cur->children[ch];
        }
        cur->eow=true;
        cur->word=s;
    }
};

class Solution {
public:

    Trie t;
    int r,c;

    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,1,0,-1};

    bool isValid(int x,int y){
        return (x>=0 && x<r && y>=0 && y<c);
    }

    void isPresent(vector<vector<char>> &board,int x,int y,vector<string> &ans,TrieNode* cur){
        //backtracking based solution
        char ch=board[x][y];
        //if already visited or root not starting with this node
        if(board[x][y]=='$' || cur->children[ch]==NULL)
            return;

        cur=cur->children[ch];
        //if this is the end of a word
        if(cur->eow){
            ans.push_back(cur->word);
            //changing the value in the trie as we have already discovered this word
            cur->eow=false;
        }

        board[x][y]='$';

        //traverse in all the four directions
        for(int i=0;i<4;i++){
            int x1=x+dx[i];
            int y1=y+dy[i];

            if(isValid(x1,y1))
                isPresent(board,x1,y1,ans,cur);
        }
        
        board[x][y]=ch;

    }


    vector<string> searchTrie(vector<vector<char>> &board){
        vector<string> ans;
        r=board.size(),c=board[0].size();
        TrieNode* root=t.root;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                    //we will dfs for this particular index
                    //find the pointer to the root of the trie
                    isPresent(board,i,j,ans,root);
            }
        }
        return ans;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n=words.size();
        //first we need to insert all the words into the trie
        for(int i=0;i<n;i++){
            string s=words[i];
            t.insert(s);
        }

        vector<string> ans=searchTrie(board);
        return ans;
    }
};
