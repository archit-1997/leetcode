#include <bits/stdc++.h>
using namespace std;

void init(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int countSubsets(vector<int> &v,int limit){
    int n=v.size();
    int len=pow(2,n);
    int ans=0;
    for(int i=0;i<len;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            //if the jth bit is set in i
            if(i&(1<<j))
                sum+=v[j];
        }
        if(sum<=limit)
            ans++;
    }
    return ans;
}

int main(){

    init();

    int n;cin>>n;
    vector<int> v(n);

    for(int i=0;i<n;i++)
        cin>>v[i];
    
    int limit;cin>>limit;

    int ans=countSubsets(v,limit);

    cout<<ans;


    return 0;
}
