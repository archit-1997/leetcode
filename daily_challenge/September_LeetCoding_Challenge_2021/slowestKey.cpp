/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : slowestKey.cpp
 * @created     : Wednesday Sep 08, 2021 10:17:29 IST
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
    char slowestKey(vector<int>& releaseTimes, string s) {
        long long ans=releaseTimes[0],n=s.size();
        char res=s[0],cur;

        for(int i=1;i<n;i++){
            //fetch the current character
            cur=s[i];
            //find the duration
            long long dur=releaseTimes[i]-releaseTimes[i-1];
            if(dur>=ans){
                //we have to find out the lexicographically smallest character
                if(dur==ans){
                    if(res<cur)
                        res=cur;
                }
                else{
                    ans=dur;
                    res=cur;
                }
            }
        }
        return res;
    }
};
