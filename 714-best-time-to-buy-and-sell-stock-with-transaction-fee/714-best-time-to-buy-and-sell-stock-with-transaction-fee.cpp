class Solution {
public:
     int fun(int i,int n,vector<int>&prices,int buy,vector<vector<int>>&dp,int fee)
{
    if(i>=n) return 0;
    int profit=0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    if(buy)
    {
        profit=max(-prices[i]+fun(i+1,n,prices,0,dp,fee),0+fun(i+1,n,prices,1,dp,fee));
    }
    else
    {
        profit=max(-fee+prices[i]+fun(i+1,n,prices,1,dp,fee),0+fun(i+1,n,prices,0,dp,fee));
    }
    return dp[i][buy]=profit;
}
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return fun(0,n,prices,1,dp,fee);
    }
};