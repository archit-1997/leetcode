/*There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5*/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,int> hash;
        
        vector<int> v;
        
        for(int i=0;i<nums1.size();i++)
        {
            if(hash[nums1[i]]==0)
                v.push_back(nums1[i]);
        }
        
        for(int i=0;i<nums2.size();i++)
        {
            if(hash[nums2[i]]==0)
                v.push_back(nums2[i]);
        }
        
        sort(v.begin(),v.end());
        
        int s=v.size();
        
        if(s%2==1)
        {
            int pos=s/2;
            return v[pos];
        }
     else
        {
            int pos=s/2;
            double avg=(v[pos-1]+v[pos])/2.0;
            return avg;
        }
        
    }
};
