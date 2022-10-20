class Solution {
public:
    bool dfs(int node,vector<int>&vis,vector<int>adj[],int parent)
    {
        vis[node]=1;
        for(auto i:adj[node])
        {
            if(!vis[i])
            {
                if(dfs(i,vis,adj,node)) return true;
            }
            else if(parent!=i) return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>&edges) {
        int n=edges.size();
        vector<int>res;
        vector<int>adj[n+1];
        for(int i=0;i<n;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        vector<int>vis(n+1,0);
            if(!vis[i])
            {
                if(dfs(edges[i][0],vis,adj,-1))
                {
                    res={edges[i][0],edges[i][1]};
                    break;
                }
            }
        }
        return res;
    }
};