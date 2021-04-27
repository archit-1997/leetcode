class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int na=A.size(),nb=B.size();
        //first lets calculate the count of array B
        vector<int> count(26,0);
        for(int i=0;i<nb;i++){
            string s=B[i];
            vector<int> tmp(26,0);
            for(int j=0;j<s.size();j++){
                int val=s[j]-'a';
                tmp[val]++;
            }
            for(int j=0;j<26;j++)
                count[j]=max(count[j],tmp[j]);
        }

        vector<string> ans;
        for(int i=0;i<na;i++){
            int flag=0;
            string s=A[i];
            vector<int> tmp(26,0);
            for(int j=0;j<s.size();j++){
                 int val=s[j]-'a';
                 tmp[val]++;
            }
            for(int j=0;j<26;j++){
                if(count[j]>tmp[j]){
                    flag=1;
                    break;
                }
            }
           if(flag==0)
            ans.push_back(A[i]);
        }

        return ans;
    }
};