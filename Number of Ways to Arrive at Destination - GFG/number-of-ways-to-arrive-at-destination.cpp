//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<int,int>>adj[n];
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<int>dist(n,1e9);
        vector<int>path(n,0);
        dist[0]=0;
        path[0]=1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int modd=(int)1e9+7;
        while(!pq.empty())
        {
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto i:adj[node])
            {
                int adjnode=i.first;
                int adjdis=i.second;
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

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends