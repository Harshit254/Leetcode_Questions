class Solution {
public:
    vector<int> findOrder(int v, vector<vector<int>>&pre) {
        vector<int>adj[v];
        for(auto i:pre)
        {
            adj[i[1]].push_back(i[0]);
        }
        vector<int>indegree(v);
        for(int i=0;i<v;i++)
        {
            for(auto j:adj[i])
            {
                indegree[j]++;
            }
        }
        queue<int>q;
        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto i:adj[node])
            {
                indegree[i]--;
                if(indegree[i]==0)
                {
                    q.push(i);
                }
            }
        }
        if(ans.size()==v) return ans;
        return {};
    }
};