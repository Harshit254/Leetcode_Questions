class Solution {
public:
int fun(int i,int n,vector<int>&prices,int buy,int trans,vector<vector<vector<int>>>&dp)
{
    if(i==n || trans==0) return 0;
    if(dp[i][buy][trans]!=-1) return dp[i][buy][trans];
    
    if(buy) return dp[i][buy][trans]=max(-prices[i]+fun(i+1,n,prices,0,trans,dp),0+fun(i+1,n,prices,1,trans,dp));
    else return dp[i][buy][trans]=max(prices[i]+fun(i+1,n,prices,1,trans-1,dp),0+fun(i+1,n,prices,0,trans,dp));
}
    int maxProfit(int k, vector<int>& prices) {
    int n=prices.size();
    //vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
    vector<vector<int>>prev(2,vector<int>(k+1,0));
    vector<vector<int>>curr(2,vector<int>(k+1,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int buy=0;buy<=1;buy++)
        {
           for(int trans=1;trans<=k;trans++)
           {
               if(buy)
               {
                   curr[buy][trans]=max(-prices[i]+prev[0][trans],prev[1][trans]);
               }
               else
               {
                   curr[buy][trans]=max(prices[i]+prev[1][trans-1],prev[0][trans]);
               }
           }
        }
        prev=curr;
    }
        return prev[1][k];
    //return fun(0,n,prices,1,k,dp);
    }
};