class Solution {
public:
    int fun(int i,vector<int>&arr,int k,vector<int>&dp,int n)
    {
        if(i==arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int mx=-1e9;
        int mxans=-1e9;
        int len=0;
        for(int j=i;j<min(i+k,n);j++)
        {
            len++;
            mx=max(mx,arr[j]);
            int sum=len*mx+fun(j+1,arr,k,dp,n);
            mxans=max(mxans,sum);
        }
        return dp[i]=mxans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return fun(0,arr,k,dp,n);
    }
};