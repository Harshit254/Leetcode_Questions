//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    vector<int>adj[n];
	    for(auto i:edges)
	    {
	        adj[i[0]].push_back(i[1]);
	        //adj[i[1]].push_back(i[0]);
	    }
	    queue<int>q;
	    q.push(s);
	    vector<int>vis(n,0);
	    int count=0;
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        if(node==d)
	        {
	            count++;
	        }
	        for(auto i:adj[node])
	        {
	           q.push(i);
	        }
	    }
	    return count;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends