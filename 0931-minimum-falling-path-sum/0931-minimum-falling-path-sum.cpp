class Solution {
public:
    int fun(int i,int j,int m,int n,vector<vector<int>>&dp,vector<vector<int>>&matrix)
    {
        if(i==n-1 && j<m && j>=0) return matrix[i][j];
        if(j>=m || j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int left,right,bottom;
        left=matrix[i][j]+fun(i+1,j-1,m,n,dp,matrix);
        bottom=matrix[i][j]+fun(i+1,j,m,n,dp,matrix);
        right=matrix[i][j]+fun(i+1,j+1,m,n,dp,matrix);
        return dp[i][j]=min(left,min(bottom,right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int mn=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<m;i++)
        {
            mn=min(mn,fun(0,i,m,n,dp,matrix));
        }
        return mn;       
    }
};