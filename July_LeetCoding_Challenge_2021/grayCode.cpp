#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans={0,1};
        for(int i=1;i<n;i++){
            int num=pow(2,i);
            //add numbers in reverse fashion
            int len=ans.size();
            for(int j=len-1;j>=0;j--)
                ans.push_back(ans[j]+num);
        }
        return ans;
    }
};
