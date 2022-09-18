class Solution {
public:
    bool dfs(int node,vector<int>&vis,vector<int>&path,vector<int>&safe,vector<vector<int>>&graph)
    {
        vis[node]=1;
        path[node]=1;
        safe[node]=0;
        for(auto i:graph[node])
        {
            if(!vis[i])
            {
                if(dfs(i,vis,path,safe,graph)==true)
                {
                    return true;
                }
            }
            else if(path[i]==1)
            {
                return true;
            }
        }
        path[node]=0;
        safe[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<graph[i].size();j++)
        //     {
        //         if(graph[i][j]==1)
        //         {
        //             adj[i].push_back(j);
        //         }
        //     }
        // }
        vector<int>vis(n,0);
        vector<int>path(n,0);
        vector<int>safe(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,path,safe,graph);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(safe[i]==1)
            {
                ans.push_back(i);
            }
        }
        return ans;
            
    }
};