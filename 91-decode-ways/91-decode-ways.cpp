class Solution {
public:
    int fun(string &s,int i,vector<int>&dp,int n)
    {
        if(i>=n) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int one=fun(s,i+1,dp,n);
        int two=0;
        if(i+1<n)
        {
            if((s[i]-'0')*10 + (s[i+1]-'0')<=26) two=fun(s,i+2,dp,n);
        }
        return dp[i]=one + two;
    }
    int numDecodings(string s) {
        if(s=="0" || s[0]=='0') return 0;
        int n=s.size();
        vector<int>dp(n,-1);
        return fun(s,0,dp,n);
    }
};