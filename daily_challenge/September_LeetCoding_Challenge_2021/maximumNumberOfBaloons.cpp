/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : maximumNumberOfBaloons.cpp
 * @created     : Saturday Sep 18, 2021 09:45:35 IST
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

    int countInstances(unordered_map<char,int> &count){
        int ans=INT_MAX;
        ans=min(ans,count['a']);
        ans=min(ans,count['b']);
        ans=min(ans,count['l']/2);
        ans=min(ans,count['o']/2);
        ans=min(ans,count['n']);
        return ans;
    }

    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> count;
        int n=text.size();
        for(int i=0;i<n;i++){
            if(text[i]=='a' || text[i]=='b' || text[i]=='l' || text[i]=='o' || text[i]=='n')
                count[text[i]]++;
        }

        int ans=countInstances(count);
        return ans;
    }
};
