#include <bits/stdc++.h>
using namespace std;

bool compare(string &a,string &b){
    if(a.size()==b.size())
        return a<b;
    return a.size()>b.size();
}

class Solution {
public:
     bool find(string &a,string &b, int i,int j){
         //if we have found the string
        if(i==a.size())
            return true;
        //if we have reached the end 
        if(j==b.size())
            return false;
        if(a[i]==b[j])
            return find(a,b,i+1,j+1);
        else
            return find(a,b,i,j+1);
    }
    
string findLongestWord(string s, vector<string>& dictionary) {

    sort(dictionary.begin(),dictionary.end(),compare);
    
    for(int i=0;i<dictionary.size();i++){
        //if this word is a subsequence of s
        if(find(dictionary[i],s,0,0)){
            return dictionary[i];
        }
    }
    return "";
}
};



