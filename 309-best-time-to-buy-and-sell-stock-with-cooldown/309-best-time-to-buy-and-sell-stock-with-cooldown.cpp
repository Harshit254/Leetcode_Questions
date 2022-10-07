class Solution {
public:
    int fun(int i,int n,vector<int>&prices,int buy,vector<vector<int>>&dp)
{
    if(i>=n) return 0;
    int profit=0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    if(buy)
    {
        profit=max(-prices[i]+fun(i+1,n,prices,0,dp),0+fun(i+1,n,prices,1,dp));
    }
    else
    {
        profit=max(prices[i]+fun(i+2,n,prices,1,dp),0+fun(i+1,n,prices,0,dp));
    }
    return dp[i][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
    vector<vector<int>>dp(n+2,vector<int>(2,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            if(buy)
            {
               dp[i][buy]=max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
            }
            else
            {
                dp[i][buy]=max(prices[i]+dp[i+2][1],0+dp[i+1][0]);
            }
        }
    }
    //return fun(0,n,prices,1,dp);
    return dp[0][1];
    }
};