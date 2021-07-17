
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long long int mod=1000000007;
        long long int n=arr.size();
        sort(arr.begin(),arr.end());
        
        unordered_map<long long int,long long int> map;
        for(long long int i=0;i<n;i++)
            map[arr[i]]=i;
        
        vector<long long int> dp(n,1);
        for(long long int i=0;i<n;i++){
            for(long long int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    int quo=arr[i]/arr[j];
                    if(map.find(quo)!=map.end()){
                        if(quo==arr[j]){
                        dp[i]+=(dp[j]*dp[j])%mod;
                        }
                        else { 
                            int index=map[quo];
                            dp[i]+=(dp[j]*dp[index])%mod;
                        }
                        dp[i]%=mod;
                    }
                }
            }
        }
        
        long long int ans=0;
        for(long long int i=0;i<n;i++){
            ans+=dp[i];
            ans%=mod;
        }
        return ans%mod;
    }
};


