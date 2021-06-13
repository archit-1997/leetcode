class Solution {
public:

    void dfs(unordered_map<string,multiset<string>> &graph,vector<string> &ans, string cur){
        if(graph.count(cur)){
            while(!graph[cur].empty())
            {
                auto it=graph[cur].begin();
                string s=*it;
                graph[cur].erase(it);
                dfs(graph,ans,s);
            }
        }
        ans.push_back(cur);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> graph;

        for(vector<string> ticket : tickets){
            string a = ticket[0];
            string b = ticket[1];
            graph[a].insert(b);
        }

        vector<string> ans;
        string cur="JFK";
        dfs(graph,ans,cur);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};