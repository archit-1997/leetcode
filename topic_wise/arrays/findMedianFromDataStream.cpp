/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : findMedianFromDataStream.cpp
 * @created     : Tuesday Aug 24, 2021 21:50:42 IST
 */

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    //max heap
    priority_queue<int>lq;
    //min heap
    priority_queue<int,vector<int>,greater<int>> rq;
    MedianFinder() {
    }
    
    void addNum(int num) {
        int ls=lq.size(),rs=rq.size();
        if(ls==0){
            lq.push(num);
            return;
        }

        if(ls==rs){
            if(num<rq.top())
                //we can simply push in the left queue
                lq.push(num);
            else{
                //bring the one from left in the right and then insert in right
                int t=rq.top();
                rq.pop();
                lq.push(t);
                rq.push(num);
            }
        }
        else{
            //we are sure that ls is greater than rs
            if(num<lq.top()){
                //pop from left,insert new in left and insert the popped one into the right
                int t=lq.top();
                lq.pop();
                lq.push(num);
                rq.push(t);
            }
            else
                rq.push(num);
        }
    }
    
    double findMedian() {
        if(lq.size()==rq.size()){
            double lv=lq.top(),rv=rq.top();
            double ans=(lv+rv)/2.0;
            return ans;
        }
        return lq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
