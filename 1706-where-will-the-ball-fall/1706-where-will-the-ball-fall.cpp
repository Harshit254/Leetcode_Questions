class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>ans;
       for(int k=0;k<grid[0].size();k++)
       {
            int i=0,j=k;
           int flag=0;
           while(i<grid.size() && j>=0 && j<grid[0].size())
           {
               if(grid[i][j]==1)
               {
                   if(j+1<grid[0].size() && grid[i][j+1]==1)
                   {
                       i++;
                       j++;
                       
                   }
                   else
                   {
                       ans.push_back(-1);
                       flag=1;
                       break;
                   }
               }
               else
               {
                   if(j-1>=0 && grid[i][j-1]==-1)
                   {
                       i++;
                       j--;
                       
                   }
                   else
                   {
                       ans.push_back(-1);
                       flag=1;
                       break;
                   }
               }
           }
           if(flag==0)
           {
               ans.push_back(j);
           }
       }
        return ans;
    }
};