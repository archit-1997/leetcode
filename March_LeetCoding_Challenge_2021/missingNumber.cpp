class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int v1=0,v2=0;
        for(int i=0;i<=n;i++){
            v1=v1^i;
            if(i!=n)
                v2=v2^nums[i];
        }
        return (v1^v2);
        
    }
};