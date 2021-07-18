#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        map<int,vector<pair<int,int>>> map;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j)
                    map[nums[i]+nums[j]].push_back({i,j});
            }
        }
        set<vector<int>> res;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int csum=nums[i]+nums[j];
                int remSum=target-csum;
                if(map[csum].size()>0 && map[remSum].size()>0){
                    vector<pair<int,int>> a=map[csum];
                    vector<pair<int,int>> b=map[remSum];

                    for(int k=0;k<a.size();k++){
                        int n1=a[k].first,n2=a[k].second;
                        for(int l=0;l<b.size();l++){
                            int n3=b[l].first,n4=b[l].second;
                            //if all these four numbers are unique
                            if(n1!=n3 && n1!=n4 && n2!=n3 && n2!=n4){
                                vector<int> tmp={nums[n1],nums[n2],nums[n3],nums[n4]};
                                sort(tmp.begin(),tmp.end());
                                res.insert(tmp);
                            }
                        }
                    }
                    map.erase(csum);
                    map.erase(remSum);
                }
            }
        }

        vector<vector<int>> ans;
        for(auto it=res.begin();it!=res.end();it++)
            ans.push_back(*it);

        return ans;
    }
};

