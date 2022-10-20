class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<long long>dist(n,1e15);
        vector<int>path(n,0);
        dist[0]=0;
        path[0]=1;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        pq.push({0,0});
        int modd=(int)1e9+7;
        while(!pq.empty())
        {
            long long dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto i:adj[node])
            {
                int adjnode=i.first;
                long long adjdis=i.second;
                if(dist[adjnode]>dis+adjdis)
                {
                    dist[adjnode]=dis+adjdis;
                    pq.push({dist[adjnode],adjnode});
                    path[adjnode]=path[node];
                }
                else if(dist[adjnode]==(dis+adjdis))
                {
                    path[adjnode]=(path[adjnode]+path[node])%modd;
                }
            }
        }
        return (path[n-1])%modd;
    }
};