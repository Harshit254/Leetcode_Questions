class Solution {
public:
    int count=0;
    void dfs(vector<int>adj[],vector<int>&vis,int ind)
    {
        vis[ind]=1;
        for(auto i:adj[ind])
        {
            if(!vis[abs(i)])
            {
                if(i>0)count++;
                dfs(adj,vis,abs(i));
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int>adj[n+1];
        vector<int>vis(n+1,0);
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(-connections[i][0]);
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(adj,vis,i);
            }
        }
        return count;
    }
};