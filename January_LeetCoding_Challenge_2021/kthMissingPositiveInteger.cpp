class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //we have to find the kth missing positive integer
        //check if the answer lies before the first interger itself
        if(k<arr[0])
            return k;
        int n=arr.size();
        int count=arr[0]-1;
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1] >1){
                int diff=arr[i]-arr[i-1]-1;
                if(count+diff<k)
                    count+=diff;
                else if(count+diff>k){
                    int inc=count+diff-k;
                    diff-=inc;
                    int ans=arr[i-1]+diff;
                    return ans;
                }
                else if(count+diff==k){
                    int ans=arr[i-1]+diff;
                    return ans;
                }
            }
        }
        //we have reached the end and we are still short of answer
        int rem=k-count;
        int ans=arr[n-1]+rem;
        return ans;
    }
};