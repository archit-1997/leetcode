#include <bits/stdc++.h>
using namespace std;

void findPermutations(vector<int> &v,int &ans,int index){
    int n=v.size();
    if(index==n){
        //found one such permutation
        ans++;
        return;
    }

    for(int i=index;i<v.size();i++){
        //swap the values
        swap(v[i],v[index]);
        //check if either of the condition is satisfied
        if(index%v[index]==0 || v[index]%index==0)
            findPermutations(v,ans,index+1);
        //undo the operation
        swap(v[i],v[index]);
    }
}

class Solution {
public:
    int countArrangement(int n) {
        vector<int> v(n+1);
        for(int i=1;i<=n;i++)
            v[i]=i;

        int ans=0;

        findPermutations(v,ans,1);
        return ans;
    }
};
