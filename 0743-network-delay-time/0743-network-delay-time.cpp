class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,1e9);
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty())
        {
            int time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto i:adj[node])
            {
                int adjnode=i.first;
                int adjtime=i.second;
                if(dist[adjnode]>time+adjtime)
                {
                    dist[adjnode]=time+adjtime;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        int mx=-1e9;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==1e9) return -1;
            mx=max(mx,dist[i]);
        }
        return mx;
    }
};