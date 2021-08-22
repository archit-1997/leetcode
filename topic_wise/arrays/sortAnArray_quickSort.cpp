/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : sortAnArray_quickSort.cpp
 * @created     : Sunday Aug 22, 2021 19:32:12 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    int partition(vector<int> &nums,int l,int r){
        //i will chose the first element as the pivot element
        int pivot=nums[l];
        int i=l,j=r;
        while(i<j){
            //incrementing the left index until we find an element greater than the pivot element
            while(i<=r && nums[i]<=pivot)
                i++;
            //decrementing the left index unti we find an element less than the pivot element : notice that we are
            //keeping equal elements on the left
            while(j>=l && nums[j]>pivot)
                j--;
            //swap if the i<j
            if(i<j)
                swap(nums[i],nums[j]);
        }
        //we swap the pivot element with the current index
        swap(nums[l],nums[j]);
        //the current index ist he index of the pivot element and hence the partition
        return j;

    }
    
    void quickSort(vector<int> &nums,int l,int r){
        if(l>=r)
            return;

        //we need to find the partition
        int m=partition(nums,l,r);
        
        //quick sort the left and the right part
        quickSort(nums,l,m-1);

        quickSort(nums,m+1,r);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();

        quickSort(nums,0,n-1);

        return nums;
    }
};
