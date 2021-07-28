/** @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : searchInASortedRotatedArray.cpp
 * @created     : Wednesday Jul 28, 2021 12:40:32 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void findPivot(vector<int> &nums,int low,int high,int &pivot){
        if(low>high)
            return;
        int n=nums.size();

        int mid=low+(high-low)/2;

        //if this is the pivot element
        if(mid+1<n && nums[mid]>nums[mid+1]){
            pivot=mid;
            return;
        }

        //if not found, then search in the left and right part
        findPivot(nums,low,mid-1,pivot);
        if(pivot>=0)
            return;
        findPivot(nums,mid+1,high,pivot);
        
    }

    bool findNum(vector<int> &nums,int low,int high,int target,int &ans){
        int n=nums.size();
        if(low<0 || high>=n)
            return false;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                return true;
            }

            if(nums[mid]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }

    int search(vector<int>& nums, int target) {
        int n=nums.size();
        //if there is only one element
        if(n==1){
            if(nums[0]==target)
                return 0;
            else
                return -1;
        }
        //if the array is already sorted
        bool flag=true;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                flag=false;
                break;
            }
        }

        if(flag){
            //this means the array is already sorted
            int index=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
            if(index>=0 && index<n && nums[index]==target)
                return index;
            return -1;
        }


        //first lets find the index of the pivot element
        int pivot=-1;
        findPivot(nums,0,n-1,pivot);
        //cout<<nums[pivot]<<"\n";
        
        //now that we have the pivot, we just need to find in the two halves
        int ans=-1;
        if(findNum(nums,0,pivot,target,ans))
            return ans;

        //find in the other half
        findNum(nums,pivot+1,n-1,target,ans);
        return ans;
    }
};



