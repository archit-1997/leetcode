class Solution {
public:

//we will find the longest even and the odd string

    vector<int> even(string s){
        int n=s.size();
        int len=0,start=-1,end=-1;
        for(int i=0;i<n;i++){
            int low=i,high=i+1;
            while(low>=0 && high<n && s[low]==s[high]){
                int curlen=high-low+1;
                if(curlen>len){
                    len=curlen;
                    start=low,end=high;
                }
                low--;high++;
            }
        }
        vector<int> ans={start,end};
        return ans;
    }

    vector<int> odd(string s){
        int n=s.size();
        int len=0,start=0,end=0;
        for(int i=0;i<n;i++){
            int low=i,high=i;
            while(low>=0 && high<n && s[low]==s[high]){
                int curlen=high-low+1;
                if(curlen>len){
                    len=curlen;
                    start=low,end=high;
                }
                low--;high++;
            }
        }
        vector<int> ans={start,end};
        return ans;
    }

    string longestPalindrome(string s) {
        vector<int> e=even(s);
        vector<int> o=odd(s);
        string even="",odd="";
        //find both the strings
        if(e[0]!=-1 && e[1]!=-1){
            for(int i=e[0];i<=e[1];i++)
                even=even+s[i];
        }
            for(int i=o[0];i<=o[1];i++)
                odd=odd+s[i];
    
        if(even.size() > odd.size())
            return even;
        else
            return odd;

    }
};