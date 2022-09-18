class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<int>adj[])
    {
        vis[node]=1;
        for(auto i:adj[node])
        {
            if(!vis[i])
            {
                dfs(i,vis,adj);
            }
        }
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<int>adj[n];
        for(auto i:pre)
        {
            adj[i[0]].push_back(i[1]);
        }
        vector<bool>ans;
        for(int i=0;i<queries.size();i++)
        {
            vector<int>vis(n,0);
            dfs(queries[i][0],vis,adj);
            if(vis[queries[i][1]])
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
            
        }
        return ans;
    }
};