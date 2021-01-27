class Solution {
public:
    //taking a global variable count which will count correctly
    //even during recursion
    int count=0;
    
    void permute(vector<int> &v, int l){
        int n=v.size();
        //if reached the last position, then break
        if(l==n)
            count++ ;
        
        //this i has the indexes
        for(int i=l;i<n;i++){
            swap(v[i],v[l]);
            if(v[l]%(l+1)==0 || (l+1)%v[l]==0)
                permute(v,l+1);
            swap(v[i],v[l]);
        }
        
    }
    
    int countArrangement(int n) {
        vector<int> v(n);
        for(int i=1;i<=n;i++)
            v[i-1]=i;
        
        //the second argument that we are passing handles the index part
        //where we will find the permutation
        permute(v,0);
        return count;
    }
};
