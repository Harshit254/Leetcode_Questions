//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int dfs(int x,int y,vector<vector<int>>&vis,vector<vector<int>>&grid)
    {
        vis[x][y]=1;
        int area=1;
        int n=grid.size();
        int m=grid[0].size();
        int nrow[]={-1,-1,-1,0,+1,+1,+1,0};
        int ncol[]={-1,0,+1,+1,+1,0,-1,-1};
        for(int i=0;i<8;i++)
        {
            int nx=nrow[i]+x;
            int ny=ncol[i]+y;
            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]==1)
            {
                area+=dfs(nx,ny,vis,grid);
            }
        }
        return area;
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int mx=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    int area=dfs(i,j,vis,grid);
                    mx=max(mx,area);
                }
            }
        }
        return mx;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends