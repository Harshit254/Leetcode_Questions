//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
    vector<pair<int,int>> adj[n];
        for(auto x : flights){
            int u = x[0];
            int v = x[1];
            int price = x[2];
            adj[u].push_back({v, price});
        }
        vector<int> price(n, 1e6);
        price[src] = 0;
        //<stops,<node, price>>
        queue<pair<int,pair<int,int>>> pq;
        pq.push({-1,{src, 0}});
        int mini = INT_MAX;
        
        while(!pq.empty()){
            
            int stops = pq.front().first;
            int node = pq.front().second.first;
            int cost = pq.front().second.second;
            pq.pop();
            
            if(node == dst and stops <= k){
                mini = min(mini, cost);
            }
            
            for(auto x : adj[node]){
                int v = x.first;
                int fare = x.second;
                if(cost + fare < price[v]){
                    price[v] = cost + fare;
                    if(stops+1 <= k)
                        pq.push({stops+1,{v,price[v]}});
                }
            }
            
        }
        if(mini == INT_MAX) mini = -1;
        return mini;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends