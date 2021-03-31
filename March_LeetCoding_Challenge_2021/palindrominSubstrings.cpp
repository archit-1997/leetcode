class Solution {
public:

    int even(string s){
        int n=s.size();
        int len=0,start=-1,end=-1;
        int ans=0;
        for(int i=0;i<n;i++){
            int low=i,high=i+1;
            while(low>=0 && high<n && s[low]==s[high]){
                ans++;
                int curlen=high-low+1;
                if(curlen>len){
                    len=curlen;
                    start=low,end=high;
                }
                low--;high++;
            }
        }
        
        return ans;
    }

    int odd(string s){
        int n=s.size();
        int len=0,start=0,end=0;
        int ans=0;
        for(int i=0;i<n;i++){
            int low=i,high=i;
            while(low>=0 && high<n && s[low]==s[high]){
                ans++;
                int curlen=high-low+1;
                if(curlen>len){
                    len=curlen;
                    start=low,end=high;
                }
                low--;high++;
            }
        }
        
        return ans;
    }

    int countSubstrings(string s) {
        int ans=even(s)+odd(s);
        return ans;
    }
};