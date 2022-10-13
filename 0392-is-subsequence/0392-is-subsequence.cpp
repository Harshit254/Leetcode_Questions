class Solution {
public:
    int fun(int i,int j,string s,string t,vector<vector<int>>&dp)
    {
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return 1+fun(i-1,j-1,s,t,dp);
        else
        {
            return dp[i][j]=max(fun(i-1,j,s,t,dp),fun(i,j-1,s,t,dp));
        }
    }
    bool isSubsequence(string s, string t) {
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        return s.size()==fun(s.size()-1,t.size()-1,s,t,dp);
    }
};