bool compare(const string &s1, const string &s2){
   return s1.size()<s2.size();
}
class Solution {
public:
    bool check(string s,string t){
        //we will check whether s is a suffix of t or not
        int ss=s.size(),st=t.size();
        ss--,st--;
        while(ss>=0 && s[ss]==t[st])
            ss--,st--;
        if(ss<0)
            return true;
        else
            return false;
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        int n=words.size();
        vector<int> vis(n,0);
        
        sort(words.begin(),words.end(),compare);

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                //we will just check whether words[i] is a suffix of words[j] or not
                bool flag=check(words[i],words[j]);
                if(flag){
                    vis[i]=1;
                    break;
                }
            }
        }

        int ans=0,count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans+=words[i].size();
                count++;
            }
        }

        ans+=count;
        return ans;
    }
};