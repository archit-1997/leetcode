
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if(s.size()==0)
            return s;
       int n=s.size();
       stack<int> st;
       vector<int> index(n,0);
       for(int i=0;i<n;i++){
            if(s[i]=='(')
                st.push(i);
            else if(s[i]==')' && !st.empty()){
                //if the stack is non-empty, then only pop from the stack
                    int t=st.top();
                    st.pop();
                    index[i]=1;
                    index[t]=1;
            }
            else if(s[i]!='(' && s[i]!=')')
                index[i]=1;
       }
       string ans="";
       for(int i=0;i<n;i++){
            if(index[i]==1)
                ans=ans+s[i];
       }
        return ans;
    }
};

