/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : c.cpp
 * @created     : Tuesday Aug 31, 2021 13:41:52 IST
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

    int minSessions(vector<int>& tasks, int sessionTime) {
        int n=tasks.size();
        int lim=(1<<n)-1;
        vector<vector<int>> dp(lim+2,vector<int> (sessionTime+1,INT_MAX));

        //we have to return the answer when we havent chosen any taks
        return solve(tasks,sessionTime,lim,dp,0,0);
    }

    int solve(vector<int> &tasks,int &sessionTime,int &lim,vector<vector<int>> &dp,int status,int time){
        int n=tasks.size();
        //base case, when we have completed all task
        if(status==lim){
            //we don't require any more sessions now
            return 0;
        }

        //if we already have the value for status : time
        if(dp[status][time]<INT_MAX)
            return dp[status][time];

        
        //we can either include or exclude a particular taks

        //excluding only when we are sure we haven't immediately started a new session
        int res=INT_MAX;
        if(time!=sessionTime)
            res= 1+solve(tasks,sessionTime,lim,dp,status,sessionTime);

        //include a task which hasn't been picked up and can be completed in given time
        for(int i=0;i<n;i++){
            if(tasks[i]<=time && (status&(1<<i))==0)
                res=min(res,solve(tasks,sessionTime,lim,dp,(status|(1<<i)),time-tasks[i]));
        }

        dp[status][time]=res;

        return dp[status][time];

    }
};
