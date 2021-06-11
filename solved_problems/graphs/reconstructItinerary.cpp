class Solution {
public:

    void dfs(vector<vector<string>> & graph,vector<string> &ans, string curr){
        ans.push_back(curr);
        for(string s : graph[curr])
            dfs(graph,ans,s);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> ans;
        set<string> st;
        for(vector<string> ticket: tickets ){
            for(string s : ticket)
                st.insert(s);
        }

        int n=st.size();

        vector<vector<string>> graph(n);

        for(vector<string> ticket: tickets ){
            string a=ticket[0],b=ticket[1];
            graph[a].push_back(b);
        }

        for(vector<string> ticket : tickets)
            sort(ticket.begin(),ticket.end());

        dfs(graph,ans,"JFK");

        return ans;
    }
};