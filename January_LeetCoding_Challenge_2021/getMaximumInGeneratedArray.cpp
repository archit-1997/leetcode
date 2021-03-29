class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0)
            return 0;
        else if(n==1 || n==2)
            return 1;
        else{
            vector<int> v(n+1,0);
            v[0]=0,v[1]=1;
            for(int i=2;i<=n;i++){
                if(i%2==0)
                    v[i]=v[i/2];
                else{
                    int index=i/2;
                    v[i]=v[index]+v[index+1];
                }
            }
            return *max_element(v.begin(),v.end());
        }

        
    }
};