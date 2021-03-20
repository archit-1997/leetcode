class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        set<string> st;
        int n=s.size();
        if(k>=n)
            return false;
        for(int i=0;i<=n-k;i++){
            string str=s.substr(i,k);
            st.insert(str);
        }

        int count=pow(2,k);

        if(count==st.size())
            return true;
        else   
            return false;
    }
};