
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v=nums;
        sort(v.begin(),v.end());

        int i=0,j=nums.size()-1;
        while(i<nums.size() && nums[i]==v[i])
            i++;
        //if the array is already sorted
        if(i==nums.size())
            return 0;

        while(j>i && nums[j]==v[j])
            j--;

        int ans=j-i+1;
        return ans;
    }
};

