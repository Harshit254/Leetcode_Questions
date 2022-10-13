class Solution {
public:
    int fun(int i,int j,string s,string t,vector<vector<int>>&dp)
    {
        if(i==0 || j==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==t[j-1]) return 1+fun(i-1,j-1,s,t,dp);
        else
        {
            return dp[i][j]=max(fun(i-1,j,s,t,dp),fun(i,j-1,s,t,dp));
        }
    }
    // bool isSubsequence(string s, string t) {
    //     vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,0));
    //     int n=s.size();
    //     int m=t.size();
    //     //return s.size()==fun(s.size(),t.size(),s,t,dp);
    //     for(int i=1;i<=n;i++)
    //     {
    //         for(int j=1;j<=m;j++)
    //         {
    //             if(s[i-1]==t[j-1])
    //             {
    //                 dp[i][j]=1+dp[i-1][j-1];
    //             }
    //             else
    //             {
    //                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    //             }
    //         }
    //     }
    //     return s.size()==dp[n][m];
    // }
    bool isSubsequence(string s, string t, int i = 0) {
        for(int j = 0; j < t.length(); j++) if(s[i] == t[j])i++;
        return i == s.length();
    }
};