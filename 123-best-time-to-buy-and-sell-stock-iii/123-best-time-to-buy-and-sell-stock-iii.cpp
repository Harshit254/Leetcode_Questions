class Solution {
public:
    int fun(int i,int n,vector<int>&prices,int buy,int trans,vector<vector<vector<int>>>&dp)
{
    if(i==n || trans==0) return 0;
    if(dp[i][buy][trans]!=-1) return dp[i][buy][trans];
    
    if(buy) return dp[i][buy][trans]=max(-prices[i]+fun(i+1,n,prices,0,trans,dp),0+fun(i+1,n,prices,1,trans,dp));
    else return dp[i][buy][trans]=max(prices[i]+fun(i+1,n,prices,1,trans-1,dp),0+fun(i+1,n,prices,0,trans,dp));
}
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<int>> ahead(2,vector<int> (k+1,0));
        // vector<vector<int>> cur(2,vector<int> (k+1,0));
        // for(int ind = n-1; ind>=0; ind--){
        //     for(int buy = 0; buy<=1; buy++){
        //         for(int cap=1; cap<=k; cap++){
        //             if(buy==0){// We can buy the stock
        //                 cur[buy][cap] = max(0+ahead[0][cap],-prices[ind] + ahead[1][cap]);
        //             }
        //             if(buy==1){// We can sell the stock
        //                 cur[buy][cap] = max(0+ahead[1][cap],prices[ind] + ahead[0][cap-1]);
        //             }
        //         }
        //     }
        //     ahead = cur;
        // }
        // return ahead[0][k];
    int n=prices.size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return fun(0,n,prices,1,2,dp);
    }
};