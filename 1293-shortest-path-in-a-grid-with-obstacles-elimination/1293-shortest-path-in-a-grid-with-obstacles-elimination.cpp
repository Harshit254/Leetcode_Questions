class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue< pair< pair<int,int> , pair<int,int> > >q;
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==1)
        {
            if(k==0) return -1;
            else
            {
                q.push({{0,0},{k-1,0}});
            }
        }
        else
        {
            q.push({{0,0},{k,0}});
        }
        vector<vector<vector<int>>>vis(m,vector<vector<int>>(n,vector<int>(k+1,0)));
        vis[0][0][k]=1;
        while(!q.empty())
        {
            int x=q.front().first.first;
            int y=q.front().first.second;
            int l=q.front().second.first;
            int dis=q.front().second.second;
            q.pop();
            if(x==m-1 && y==n-1)
            {
                return dis;
            }
            int nrow[]={-1,0,+1,0};
            int ncol[]={0,+1,0,-1};
            for(int i=0;i<4;i++)
            {
                int nx=nrow[i]+x;
                int ny=ncol[i]+y;
                if(nx>=0 && nx<m && ny>=0 && ny<n && vis[nx][ny][l]==0)
                {
                    if(grid[nx][ny]==1)
                    {
                        if(l>0 && !vis[nx][ny][l-1])
                        {
                            q.push({{nx,ny},{l-1,dis+1}});
                            vis[nx][ny][l-1]=1;
                        }
                    }
                    else
                    {
                        q.push({{nx,ny},{l,dis+1}});
                        vis[nx][ny][l]=1;
                    }
                }
            }
            
        }
        return -1;
    }
};