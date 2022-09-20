class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size(),vector<int>(nums2.size(),0));
        int ans=INT_MIN;
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(nums1[i]==nums2[j])
                {
                    if(i==0 || j==0)
                    {
                        dp[i][j]=1;
                    }
                    else
                    {
                        dp[i][j]=dp[i-1][j-1]+1;
                    }
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};