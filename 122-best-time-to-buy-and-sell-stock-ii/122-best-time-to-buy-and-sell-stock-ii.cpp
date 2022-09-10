class Solution {
// public:
//     int maxProfit(vector<int>&nums) {
//         int sum=0;
//         for(int i=1;i<nums.size();i++)
//         {
//             if(nums[i]>nums[i-1])
//             {
//                 sum+=nums[i]-nums[i-1];
//             }
//         }
//         return sum;
//     }
    
     int maxProfit(vector<int> &pr, int ind, int buy, vector<vector<int>> &dp) {
        if(ind >= pr.size())return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        
        if(buy)
            return dp[ind][buy] = max(-pr[ind] + maxProfit(pr, ind + 1, 0, dp), maxProfit(pr, ind + 1, 1, dp));
        else
            return dp[ind][buy] = max(pr[ind] + maxProfit(pr, ind + 1, 1, dp), maxProfit(pr, ind + 1, 0, dp));
    }
public:
    int maxProfit(vector<int>& pr) {
        vector<vector<int>> dp(pr.size() + 1, vector<int>(2, -1));
        return maxProfit(pr, 0, 1, dp);
    }
};