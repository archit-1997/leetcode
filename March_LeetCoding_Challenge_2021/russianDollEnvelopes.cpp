bool compare(pair<int,int> &a, pair<int,int> &b){
        if(a.first==b.first)
            return a.second>b.second;
        return a.first>b.first;
    }
class Solution {
public:
    
    
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        vector<pair<int,int>> v;
        for(int i=0;i<envelopes.size();i++){
            pair<int,int> p={envelopes[i][0],envelopes[i][1]};
            v.push_back(p);
        }
        
        sort(v.begin(),v.end(),compare);
        
        vector<int> lds(n,1);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(v[j].first<v[i].first && v[j].second<v[i].second && lds[j]<lds[i]+1)
                    lds[j]=lds[i]+1;
            }
        }

        int ans=*max_element(lds.begin(),lds.end());
        
        return ans;
    }
};