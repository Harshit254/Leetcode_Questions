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
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto i:edges)
        {
            adj[i[1]].push_back(i[0]);
        }
        vector<vector<int>>ans;
        vector<int>temp;
        for(int i=0;i<n;i++)
        {
            vector<int>vis(n,0);
            dfs(i,vis,adj);
            for(int j=0;j<n;j++)
            {
                if(vis[j] && j!=i)
                {
                    temp.push_back(j);
                }
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};