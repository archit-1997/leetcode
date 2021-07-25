/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : theNumberOfTheSmallestUnoccupiedChair.cpp
 * @created     : Sunday Jul 25, 2021 06:25:04 IST
 */


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();

        //find the arrival time of the target friend
        int targetArrival=times[targetFriend][0];
        
        sort(times.begin(),times.end());

        //priority queue to store the current status of chairs
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        priority_queue<int,vector<int>,greater<int>> available;

        for(int i=0;i<n;i++){
            //make all the seats vacant where friends have gone
            while(!pq.empty() && pq.top().first<=times[i][0]){
                available.push(pq.top().second);
                pq.pop();
            }

            //if target friend arrived
            if(times[i][0]==targetArrival)
                break;

            //we have to allot a seat
            if(!available.empty()){
                pq.push({times[i][1],available.top()});
                available.pop();
            }
            else
                pq.push({times[i][1],pq.size()});
        }

        //if we have no available seats
        if(available.empty())
            return pq.size();
        else
            return available.top();
    }
};

