class Solution {
public:
    int fun(int i,vector<int>&days,vector<int>&cost,int n,int j,vector<int>&dp)
    {
        if(j>=n)
        {
            return 0;
        }
        if(days[j]<=i)
        {
            return fun(i,days,cost,n,j+1,dp);
        }
        if(dp[j]!=-1) return dp[j];
        int one=cost[0]+fun(days[j],days,cost,n,j+1,dp);
        
        int seven=cost[1]+fun(days[j]+6,days,cost,n,j+1,dp);
        
        int thirty=cost[2]+fun(days[j]+29,days,cost,n,j+1,dp);
        return dp[j]=min(one,min(seven,thirty));
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n,-1);
        return fun(0,days,costs,n,0,dp);
    }
};