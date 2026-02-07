/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : rangeSumQuery.cpp
 * @created     : Tuesday Aug 17, 2021 05:06:39 IST
 */

#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> segmentTree;
    int len,low,high;


    void constructSegmentTree(vector<int> &nums,vector<int> &segmentTree,int low,int high,int pos){
        //if we are at a child node
        if(low==high){
            segmentTree[pos]=nums[low];
            return;
        }

        int mid=low+(high-low)/2;
        //populate the left and the right subtree
        constructSegmentTree(nums,segmentTree,low,mid,2*pos+1);
        constructSegmentTree(nums,segmentTree,mid+1,high,2*pos+2);

        //value of the node will the sum of the two children node
        segmentTree[pos]=segmentTree[2*pos+1]+segmentTree[2*pos+2];
    }

    int rangeSumQuery(vector<int> &segmentTree,int low,int high,int ql,int qr,int pos){
        //if the current range is outside the given query range
        if(low>qr || high<ql)
            return 0;

        //if current range completely inside the given range
        if(low>=ql && high<=qr)
            return segmentTree[pos];

        //in case of partial overlapp, find the sum from the left and the right subtree
        int mid=low+(high-low)/2;
        
        int leftSum=rangeSumQuery(segmentTree,low,mid,ql,qr,2*pos+1);
        int rightSum=rangeSumQuery(segmentTree,mid+1,high,ql,qr,2*pos+2);
        
        //return the sum from the left and the right subtree
        return (leftSum + rightSum);
    }

    NumArray(vector<int>& nums) {
        int n=nums.size();
        len=4*n;
        low=0,high=n-1;
        //constructing the segment tree
        segmentTree.resize(len,0);

        //we need to construct the semgent tree as well
        constructSegmentTree(nums,segmentTree,low,high,0);
    }
    
    int sumRange(int left, int right) {
        //we need to find the sum of elements between the given range
        //the last argument is 0 as it stores the index for the segment tree
        return rangeSumQuery(segmentTree,low,high,left,right,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
