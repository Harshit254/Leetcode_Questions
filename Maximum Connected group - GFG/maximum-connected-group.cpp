//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Disjointset
{
     public:
    vector<int>parent,rank,size;
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
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        Disjointset ds(n*n);
        int r[]={-1,0,+1,0};
        int c[]={0,+1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0) continue;
                
                for(int k=0;k<4;k++)
                {
                    int nrow=i+r[k];
                    int ncol=j+c[k];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1)
                    {
                        int parent=n*i+j;
                        int child=n*nrow+ncol;
                        ds.unionbysize(parent,child);
                    }
                    
                }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) continue;
                set<int>st;
                for(int k=0;k<4;k++)
                {
                    int nrow=i+r[k];
                    int ncol=j+c[k];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1)
                    {
                        int child=n*nrow+ncol;
                        st.insert(ds.findUltimateparent(child));
                    }
                    
                }
                int ans=0;
                for(auto k:st)
                {
                    ans+=ds.size[k];
                }
                mx=max(mx,ans+1);
            }
        }
        for(int i=0;i<n*n;i++)
        {
            mx=max(mx,ds.size[ds.findUltimateparent(i)]);
        }
        return mx;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends