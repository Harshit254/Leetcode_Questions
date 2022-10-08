class Solution {
public:
    int fun(int i,int n,vector<int>&nums,int prev,vector<vector<int>>&dp)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int notpick=0+fun(i+1,n,nums,prev,dp);
            int pick=0;
            if(prev==-1 || nums[i]>nums[prev])
            {
                pick=1+fun(i+1,n,nums,i,dp);
            }
        return dp[i][prev+1]=max(pick,notpick);
    }
    int lengthOfLIS(vector<int>& nums){
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size()+1,-1));
        int n=nums.size();
//         for(int i = 0; i < nums.size(); i++)
//         {
//             for(int j = 0; j < i; j++)
//             {
//                 if(nums[i] > nums[j])
//                     dp[i] = max(dp[i], dp[j] + 1);
//             }
//         }
        
//         return *max_element(dp.begin(), dp.end());
        return fun(0,n,nums,-1,dp);
    }
};