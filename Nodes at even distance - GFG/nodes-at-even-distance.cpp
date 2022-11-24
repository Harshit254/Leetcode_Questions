//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int countOfNodes(vector<int> graph[], int n)
    {
        queue<int>q;
         vector<int>dist(n+1,0);
        vector<bool>visited(n+1,false);
        q.push(1);
        visited[1]=true;
        
        while(!q.empty())
        { //BFS
            int node = q.front();
            int distance = dist[node]; 
            q.pop();
            
            for(int neighbour:graph[node])
            {
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    dist[neighbour]=distance+1;
                    visited[neighbour]=true;
                }
            }
            
        }
        int even =0;
        int odd =0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]%2==0)even++;
            else odd++;
        }
        
        return even*(even-1)/2 + odd*(odd-1)/2;


    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int>graph[n+1];
        for(int i=0;i<n-1;i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        Solution ob;
        cout<<ob.countOfNodes(graph, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends