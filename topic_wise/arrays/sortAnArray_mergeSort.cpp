/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : sortAnArray.cpp
 * @created     : Saturday Aug 21, 2021 14:34:34 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void merge(vector<int>&v,int l,int mid,int r){
        //find the number of elements int the left and the right part
        int li=l,ri=mid+1;
        vector<int> tmp;
        while(li<=mid && ri<=r){
            if(v[li]<=v[ri])
                tmp.push_back(v[li++]);
            else
                tmp.push_back(v[ri++]);
        }
        //fill the left and the right array
        while(li<=mid)
            tmp.push_back(v[li++]);

        while(ri<=r)
            tmp.push_back(v[ri++]);

        int index=0;
        for(int i=l;i<=r;i++)
            v[i]=tmp[index++];
    }

    void mergeSort(vector<int> &v,int l,int r){
        if(l==r)
            return;

        int mid=l+(r-l)/2;
        mergeSort(v,l,mid);
        mergeSort(v,mid+1,r);
        merge(v,l,mid,r);
    }

    vector<int> sortArray(vector<int>& nums) {
        //we will be using merge sort to sort the array
        int n=nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};
