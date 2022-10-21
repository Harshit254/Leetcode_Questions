class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();i++)
        { 
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back({v,succProb[i]});
            adj[v].push_back({u,succProb[i]});
        }
        priority_queue<pair<double,int>>pq;
        vector<double>dist(n,0.0);
        pq.push({1.0,start});
        dist[start]=1.0;
        while(!pq.empty())
        {
            double prob=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto i:adj[node])
            {
                int adjnode=i.first;
                double adjprob=i.second;
                if(dist[adjnode]<prob*adjprob)
                {
                    dist[adjnode]=prob*adjprob;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        return dist[end]; 
       
    }
};