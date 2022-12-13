//{ Driver Code Starts
// Initial Template for C++

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
    int findultimateparent(int node)
    {
        if(parent[node]==node) return node;
        return parent[node]=findultimateparent(parent[node]);
    }
    void unionbysize(int u,int v)
    {
        int ultp_U=findultimateparent(u);
        int ultp_V=findultimateparent(v);
        if(ultp_U==ultp_V) return;
        if(size[ultp_U]>size[ultp_V])
        {
            parent[ultp_V]=ultp_U;
            size[ultp_U]+=size[ultp_V];
        }
        else
        {
            parent[ultp_U]=ultp_V;
            size[ultp_V]+=size[ultp_U];
        }
    }
    void unionbyrank(int u,int v)
    {
        int ultp_U=findultimateparent(u);
        int ultp_V=findultimateparent(v);
        if(ultp_U==ultp_V) return;
        else if(rank[ultp_U]>rank[ultp_V])
        {
            parent[ultp_V]=ultp_U;
        }
        else if(rank[ultp_U]<rank[ultp_V])
        {
            parent[ultp_U]=ultp_V;
        }
        else
        {
             parent[ultp_V]=ultp_U;
             rank[ultp_U]++;
        }
    }
    
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        Disjointset ds( n * m );
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        int r[]={-1,0,+1,0};
        int c[]={0,+1,0,-1};
        vector<int>ans;
        for(auto i:operators)
        {
            int row=i[0];
            int col=i[1];
            if(vis[row][col]==1)
            {
                ans.push_back(count);
                continue;
            }
            count++;
            vis[row][col]=1;
            for(int j=0;j<4;j++)
            {
                int nrow=row+r[j];
                int ncol=col+c[j];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol])
                {
                    int par=m*row+col;
                    int child=m*nrow+ncol;
                    if(ds.findultimateparent(par)!=ds.findultimateparent(child))
                    {
                        ds.unionbysize(par,child);
                        count--;
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends