/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : removeDuplicatesFromSortedArray.cpp
 * @created     : Friday Aug 06, 2021 07:19:19 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        int index=1,val=nums[0],count=1,i=1;

        while(i<n){
            if(nums[i]==val){
                count++;
                if(count>1){
                    while(i<n && nums[i]==val)
                        i++;
                    //if we have gone out of range, then break
                    if(i==n)
                        return index;
                    count=1;
                    val=nums[i];
                }
            }
            else{
                //we have found a new number
                val=nums[i];
                count=1;
            }
            swap(nums[index++],nums[i++]);
        }
        
        return index;
    }
};

