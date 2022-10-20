class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto i:flights)
        {
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int>dist(n,1e9);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        dist[src]=0;
        //queue<pair<int,pair<int,int>>>pq;
        pq.push({-1,{src,0}});
        int mini=INT_MAX;
        while(!pq.empty())
        {
            int stop=pq.top().first;
            int node=pq.top().second.first;
            int dis=pq.top().second.second;
            pq.pop();
            if(node==dst && stop<=k) mini=min(dis,mini);
            for(auto i:adj[node])
            {
                int adjnode=i.first;
                int adjdis=i.second;
                if(dist[adjnode]>dis+adjdis)
                {
                    dist[adjnode]=dis+adjdis;
                    if(stop+1<=k)
                    {
                        pq.push({stop+1,{adjnode,dist[adjnode]}});
                    }
                }
            }
        }
        if(mini==INT_MAX) return -1;
        return mini;

    }
};