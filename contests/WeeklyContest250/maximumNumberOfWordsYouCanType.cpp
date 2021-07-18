#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> v;
        string str="";
        for(int i=0;i<text.size();i++){
            if(text[i]==32){
                v.push_back(str);
                str="";
            }
            else 
                str=str+text[i];
        }
        v.push_back(str);
        if(brokenLetters.size()==26)
            return 0;

        unordered_map<char,int> count;
        for(char ch : brokenLetters)
            count[ch]++;
        int ans=0;
        for(int i=0;i<v.size();i++){
            bool flag=true;
            for(int j=0;j<v[i].size();j++){
                if(count[v[i][j]]>0){
                    flag=false;
                    break;
                }
            }
            if(flag)
                ans++;
        }
        return ans;
    }
};

int main(){

    string s1="leet code",s2="lt";
    Solution s;
    int ans=s.canBeTypedWords(s1,s2);
    cout<<ans;

    return 0;
}
