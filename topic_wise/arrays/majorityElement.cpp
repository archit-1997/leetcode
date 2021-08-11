/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : majorityElement.cpp
 * @created     : Wednesday Aug 11, 2021 14:12:33 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,majority=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                count=1;
                majority=nums[i];
            }
            else if(nums[i]==majority)
                count++;
            else
                count--;
        }
        return majority;
    }
};
