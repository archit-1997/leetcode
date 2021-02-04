class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> hash;
        int n=nums.size();
        for(int i=0;i<n;i++)
            hash[nums[i]]++;
        
        if(hash.size()<=1)
            return 0;
    
        int ans=INT_MIN;
    
        vector<pair<int,int>> v;
        for(auto it=hash.begin();it!=hash.end();it++){
            v.push_back(make_pair(it->first,it->second));
        }
        
        int len=v.size();
        for(int i=0;i<len-1;i++){
            int diff=v[i+1].first-v[i].first;
            if(diff==1){
                int sum=v[i].second+v[i+1].second;
                ans=max(ans,sum);
            }
        }
        
        if(ans==INT_MIN)
            return 0;
        
        return ans;
        
    }
};
