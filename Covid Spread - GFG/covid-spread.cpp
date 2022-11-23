//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        //code here
        int n=hospital.size();
        int m=hospital[0].size();
        queue< pair <pair<int,int> ,int> >q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(hospital[i][j]==2)
                {
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        int mx=0;
        int nrow[]={-1,0,+1,0};
        int ncol[]={0,+1,0,-1};
        while(!q.empty())
        {
            int x=q.front().first.first;
            int y=q.front().first.second;
            int t=q.front().second;
            q.pop();
            mx=max(t,mx);
            for(int i=0;i<4;i++)
            {
                int nx=nrow[i]+x;
                int ny=ncol[i]+y;
                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && hospital[nx][ny]==1)
                {
                    vis[nx][ny]=1;
                    q.push({{nx,ny},t+1});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && hospital[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return mx;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends