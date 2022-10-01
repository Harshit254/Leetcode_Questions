class Solution {
public:
    bool f(int i,vector<int>&nums,int sum,vector<vector<int>>&dp)
    {
        if(sum==0)
        {
            return true;
        }
        if(i>=nums.size() || sum<0)
        {
            return false;
        }
        if(dp[i][sum]!=-1)
        {
            return dp[i][sum];
        }
         return dp[i][sum]=f(i+1,nums,sum-nums[i],dp)|| f(i+1,nums,sum,dp);
    }
    bool canPartition(vector<int>& nums) {
       int sum=0;
        for(auto i:nums)
        {
            sum+=i;
        }
        if(sum%2!=0)
        {
            return false;
        }
        vector<vector<int>>dp(nums.size()+1,vector<int>((sum/2)+1,-1));
        
        return f(0,nums,sum/2,dp);
    }
};