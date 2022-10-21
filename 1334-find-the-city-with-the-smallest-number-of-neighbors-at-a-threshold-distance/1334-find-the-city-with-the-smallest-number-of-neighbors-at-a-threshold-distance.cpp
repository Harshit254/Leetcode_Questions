class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int mn=INT_MAX;
        int ans;
        for(int i=0;i<n;i++)
        {
            vector<int>dist(n,1e9);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            dist[i]=0;
            pq.push({0,i});
            while(!pq.empty())
            {
                int dis=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                for(auto it:adj[node])
                {
                    int adjnode=it.first;
                    int adjdis=it.second;
                    if(dist[adjnode]>dis+adjdis)
                    {
                        dist[adjnode]=dis+adjdis;
                        pq.push({dist[adjnode],adjnode});
                    }
                }
            }
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(dist[j]<=distanceThreshold && i!=j)
                {
                    count++;
                }
                cout<<dist[j]<<" ";
            }
            if(mn>count)
            {
                mn=count;
                ans=i;
                
            }
            else if(mn==count)
            {
                ans=max(ans,i);
            }
        }
        return ans;
        
    }
};