class Solution {
public:
    // int fun(int i,vector<int>&nums,vector<int>&dp)
    // {
    //     if(i<0)return 0;
    //     if(i==0) return nums[0];
    //     if(dp[i]!=-1) return dp[i];
    //     int pick,notpick;
    //     pick=nums[i]+fun(i-2,nums,dp);
    //     notpick=0+fun(i-1,nums,dp);
    //     return dp[i]=max(pick,notpick);
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<=n;i++)
        {
        int pick,notpick;
        pick=nums[i-1]+dp[i-2];
        notpick=dp[i-1];
        dp[i]=max(pick,notpick);
        }
        //return fun(n-1,nums,dp);
        return dp[n];
    }
};