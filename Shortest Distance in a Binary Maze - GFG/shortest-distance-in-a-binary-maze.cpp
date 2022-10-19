//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        //priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        queue<pair<int,pair<int,int>>>pq;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        vis[source.first][source.second]=1;
        pq.push({0,{source.first,source.second}});
        int mini=1e9;
        while(!pq.empty())
        {
            int dist=pq.front().first;
            int x=pq.front().second.first;
            int y=pq.front().second.second;
            pq.pop();
            if(x==destination.first && y==destination.second)
            {
                mini=min(mini,dist);
               // return mini;
            }
            int nrow[]={-1,0,+1,0};
            int ncol[]={0,+1,0,-1};
            for(int i=0;i<4;i++)
            {
                int nr=x+nrow[i];
                int nc=y+ncol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==-1 && grid[nr][nc]==1)
                {
                    pq.push({dist+1,{nr,nc}});
                    vis[nr][nc]=1;
                }
            }
        }
        if(vis[destination.first][destination.second]==-1) return -1;
        return mini;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends