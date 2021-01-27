class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int r=pieces.size(),n=arr.size();
        
        int i=0;
        for(;i<n;){
            int num=arr[i];
            
            //search for this element in the first column of th 2d array
            int rn=-1;
            for(int j=0;j<r;j++){
                if(pieces[j][0]==num){
                    rn=j;
                    break;
                }
            }
            
            if(rn==-1)
                return false;
            
            //we have found this element
            int len=pieces[rn].size();
            int j=0;
            while(i<n && j<len && arr[i]==pieces[rn][j]){
                i++,j++;
            }
            
            if(j<len)
                return false;
        }
        
        return true;
        
    }
};
