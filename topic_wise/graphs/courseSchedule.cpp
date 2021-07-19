class Solution {
public:

    bool detectCycle(vector<vector<int>> &v,vector<int> &vis,vector<int> &rec, int x){
        rec[x]=1;
        vis[x]=1;
        for(int i=0;i<v[x].size();i++){
            if(!vis[v[x][i]] && detectCycle(v,vis,rec,v[x][i]))
                return true;
            if(rec[v[x][i]])
                return true;
        }
        rec[x]=0;
        return false;
    }

    void buildGraph(vector<vector<int>> &v, vector<vector<int>>& prerequisites){
        for(int i=0;i<prerequisites.size();i++){
            int start=prerequisites[i][1];
            int end =prerequisites[i][0];
            v[start].push_back(end);
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> v(numCourses);

        buildGraph(v,prerequisites);

        vector<int> vis(numCourses,0);
        vector<int> rec(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(detectCycle(v,vis,rec,i))
                return false;
        }

        return true;
    }
};