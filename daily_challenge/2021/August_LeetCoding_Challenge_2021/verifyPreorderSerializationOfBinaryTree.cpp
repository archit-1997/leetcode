/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : verifyPreorderSerializationOfBinaryTree.cpp
 * @created     : Wednesday Sep 01, 2021 20:34:18 IST
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define P pair<int,int>

void init(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

class Solution {
public:

    bool isValidSerialization(string preorder) {
        //first lets pares the string into vector<string> with different elements
        vector<string> nodes=parse(preorder);
        int count=1,n=nodes.size();

        for(int i=0;i<n;i++){
            count--;
            if(count<0)
                return false;

            if(nodes[i]!="#")
                count+=2;
        }
        return (count==0);
    }

    vector<string> parse(string &s){
        vector<string> ans;

        string tmp="";
        int n=s.size();

        for(int i=0;i<n;i++){
            if(s[i]==','){
                ans.push_back(tmp);
                tmp="";
            }
            else
                tmp=tmp+s[i];
        }

        //pushing the last element into the string
        ans.push_back(tmp);
        return ans;
    }
};
