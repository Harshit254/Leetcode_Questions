//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Disjointset
{
    vector<int>parent,rank,size;
    public:
    Disjointset(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUltimateparent(int node)
    {
        if(node==parent[node])return node;
        return parent[node]=findUltimateparent(parent[node]);
    }
    void unionbyrank(int u,int v)
    {
        int ulp_U=findUltimateparent(u);
        int ulp_V=findUltimateparent(v);
        if(ulp_U==ulp_V) return;
        else if(rank[ulp_U]>rank[ulp_V])
        {
           parent[ulp_V]=ulp_U; 
        }
        else if(rank[ulp_V]>rank[ulp_U])
        {
            parent[ulp_U]=ulp_V;
        }
        else
        {
            parent[ulp_V]=ulp_U;
            rank[ulp_U]++;
        }
    }
    public:
    void unionbysize(int u,int v)
    {
        int ulp_U=findUltimateparent(u);
        int ulp_V=findUltimateparent(v);
        if(ulp_U==ulp_V) return;
        if(size[ulp_U]<size[ulp_V])
        {
            parent[ulp_U]=ulp_V;
            size[ulp_V]+=size[ulp_U];
        }
        else
        {
            parent[ulp_V]=ulp_U;
            size[ulp_U]+=size[ulp_V];
        }
    }
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        int extra=0;
        Disjointset ds(n);
        for(auto i:edge)
        {
            int u=i[0];
            int v=i[1];
            if(ds.findUltimateparent(u)==ds.findUltimateparent(v))
            {
                extra++;
            }
            else
            {
                ds.unionbysize(u,v);
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(ds.findUltimateparent(i)==i)
            {
                count++;
            }
        }
        int ans=count-1;
        if(extra>=ans) return ans;
        return -1;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends