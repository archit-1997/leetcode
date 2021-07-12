#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        int ans=0,count=0;
        //{identifier,value}
        stack<pair<char,int>> st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(count!=0){
                    int val=pow(2,count-1);
                    st.push({'n',val});
                    count=0;
                }
                //c implies that a character has been pushed
                st.push({'c',i});
            }
            else if(s[i]==')'){
                if(st.top().first=='c'){
                    st.pop();
                    count++;
                }
                else{
                    if(count!=0){
                        int val=pow(2,count-1);
                        st.push({'n',val});
                        count=0;
                    }
                    int val=0;
                    while(!st.empty() && st.top().first=='n'){
                        val+=st.top().second;
                        st.pop();
                    }
                    //pop one parenthesis corresponding to the closing one
                    st.pop();
                    st.push({'n',2*val});
                }
            }
        }
        if(count!=0){
            int val=pow(2,count-1);
            st.push({'n',val});
        }
        while(!st.empty()){
            ans+=st.top().second;
            st.pop();
        }

        return ans;
     } 
};

