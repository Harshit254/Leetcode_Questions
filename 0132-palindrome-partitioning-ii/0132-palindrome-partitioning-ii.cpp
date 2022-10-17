class Solution {
public:
    int function(int i,string s,vector<int>&dp)
    {
        if(i==s.size())
        {
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int mini=1e9;
        for(int j=i;j<s.size();j++)
        {
            if(ispalindrome(s,i,j))
            {
                int cost=1+function(j+1,s,dp);
                if(cost<mini)
                {
                    mini=cost;
                }
            }
        }
        return dp[i]=mini;
    }
    bool ispalindrome(string &s,int st,int ed)
    {
        while(st<=ed)
        {
            if(s[st++]!=s[ed--])
            {
                return false;
            }
        }
        return true;
    }
    int minCut(string s) {
        vector<int>dp(s.size(),-1);
        return function(0,s,dp)-1;
    }
};