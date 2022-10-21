class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue< pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> >pq;
        pq.push({0,{0,0}});
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        int nrow[]={-1,0,+1,0};
        int ncol[]={0,+1,0,-1};
        while(!pq.empty())
        {
            int dis=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if(x==n-1 && y==m-1)
            {
                return dis;
            }
            for(int i=0;i<4;i++)
            {
                int adjrow=nrow[i]+x;
                int adjcol=ncol[i]+y;
                if(adjrow>=0 && adjrow<n && adjcol>=0 && adjcol<m)
                {
                    int mndis=max(abs(heights[x][y]-heights[adjrow][adjcol]),dis);
                    if(dist[adjrow][adjcol]>mndis)
                    {
                        dist[adjrow][adjcol]=mndis;
                        pq.push({dist[adjrow][adjcol],{adjrow,adjcol}});
                    }
                }
            }
        }
        return 0;
    }
};