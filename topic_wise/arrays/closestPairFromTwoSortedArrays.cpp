/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : closestPairFromTwoSortedArrays.cpp
 * @created     : Thursday Jul 29, 2021 09:21:36 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    vector<int> findClosestPair(vector<int> &a, vector<int> &b,int k){
        int na=a.size(),nb=b.size();

        //l for a and r for b
        int l=0,r=nb-1;
        int minDiff=INT_MAX;
        vector<int> ans;
        while(l<na && r>=0){
            int sum=a[l]+b[r];
            int diff=sum-k;
            
            //diff =0, exact difference
            if(diff==0){
                vector<int> tmp={a[l],b[r]};
                ans=tmp;
                return ans;
            }

            if(abs(diff)<minDiff){
                minDiff=abs(diff);
                vector<int> tmp={a[l],b[r]};
                ans=tmp;
            }

            if(sum>k)
                r--;
            else
                l++;
        }
        return ans;
    }

};

void init(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}


int main(){
    init();

    int a;cin>>a;
    vector<int> va(a);
    for(int i=0;i<a;i++)
        cin>>va[i];

    int b;cin>>b;
    vector<int> vb(b);
    for(int i=0;i<b;i++)
        cin>>vb[i];

    int target;cin>>target;

    Solution s;
    vector<int> ans=s.findClosestPair(va,vb,target);

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";

    return 0;
}
