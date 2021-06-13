#define P pair<int,int>

class Solution {
public:

    int findIndex(int i,int j,int col){
        int pos=(i*col)+j;
        return pos;
    }

    bool isReachable(int i,int j,int row, int col){
        if(i>=0 && i<row && j>=0 && j<col)
            return true;
        return false;
    }

    vector<vector<P>> buildGraph(vector<vector<int>> &heights){
        int r=heights.size(),c=heights[0].size();
        int n=r*c;
        vector<vector<P>> graph(n);
        vector<int> x={0,1,0,-1};
        vector<int> y={1,0,-1,0};
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int curNode = findIndex(i,j,c);
                for(int k=0;k<4;k++){
                    int x1=i+x[k];
                    int y1=j+y[k];

                    if(isReachable(x1,y1,r,c)){
                        int nextNode = findIndex(x1,y1,c);
                        int edgeWeight = abs(heights[x1][y1]-heights[i][j]);
                        graph[curNode].push_back({nextNode,edgeWeight});
                    }
                }
            }
        }
        return graph;
    }

    void dfs(vector<vector<P>> &graph,vector<vector<int>> &paths,vector<int> &tmp,P p,int target){
        int x=p.second;
        int wt=p.first;
        tmp.push_back(wt);
        if(x==target){
            paths.push_back(tmp);
            tmp.pop_back();
            return ;
        }
        for(int i=0;i<graph[x].size();i++){
            dfs(graph,paths,tmp,graph[x][i],target)
        }
        tmp.pop_back();
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int r=heights.size(),c=heights[0].size();
        int n=r*c;
        vector<vector<P>> graph=buildGraph(heights);

        vector<vector<int>> paths;
        int source =0,target=n-1;
        for(int i=0;i<graph[source].size();i++){
            vector<int> tmp;
            dfs(graph,paths,tmp,graph[source][i],target);
        }

        int ans=INT_MAX;
        for(int i=0;i<paths.size();i++){
            int big=*max_element(paths.begin(),paths.end());
            ans=min(ans,big);
        }

        return ans;
    }
};