class Solution {
public:
    int fun(int i,int n,vector<int>&nums,vector<int>&dp)
    {
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(nums[i]+fun(i+2,n,nums,dp),fun(i+1,n,nums,dp));
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
       return max(fun(0,n-1,nums,dp),fun(1,n,nums,dp2));
    }
};