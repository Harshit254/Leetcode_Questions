class Solution {
public:
    int fun(int m,int turn,vector<int>&piles,int i,vector<vector<vector<int>>>&dp)
    {
        if(i>=piles.size()) return 0;
        if(dp[i][m][turn]!=-1) return dp[i][m][turn];
         int stones;
        if(turn)
        {
            stones=INT_MAX;
            for(int j=0;j<2*m && j+i<piles.size();j++)
            {
                stones=min(stones,fun(max(m,j+1),0,piles,j+i+1,dp));
            }
        }
        else
        {
            int temp=0;
            stones=0;
            for(int j=0;j<2*m && j+i<piles.size();j++)
            {
                temp+=piles[j+i];
                stones=max(stones,temp+fun(max(m,j+1),1,piles,j+i+1,dp));
            }
        }
        return dp[i][m][turn]=stones;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>>dp(105,vector<vector<int>>(105,vector<int>(2,-1)));
        return fun(1,0,piles,0,dp);
    }
};