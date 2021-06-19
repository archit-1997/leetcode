class Solution {
public:


    int minJumps(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;

        unordered_map<int,vector<int>> pos;
        for(int i=0;i<nums.size();i++)
            pos[nums[i]].push_back(i);

        vector<int> vis(n,0);
        queue<int> q;
        q.push(0);
        vis[0]=1;
        int steps=0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                int index=q.front();
                q.pop();

                if(index==(n-1))
                    return steps;

                //can we go to index+1?
                if(index+1<n && !vis[index+1]){
                    q.push(index+1);
                    vis[index+1]=1;
                }

                //can we go to index-1?
                if(index-1>=0 && !vis[index-1]){
                    q.push(index-1);
                    vis[index-1]=1;
                }

                //where else can we go
                vector<int> value=pos[nums[index]];
                for(int num : value){
                    if(!vis[num]){
                        q.push(num);
                        vis[num]=1;
                    }
                }
                pos[nums[index]].clear();
            }
            steps++;
        }

        return steps;
    }
};