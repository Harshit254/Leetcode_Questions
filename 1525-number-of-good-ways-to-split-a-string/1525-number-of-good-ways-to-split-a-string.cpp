class Solution {
public:
    // int fun(int i,string s,int n,vector<vector<int>>&dp)
    // {
    //     if(i==0)return 0;
    //     if(dp[i][n-1-i]!=-1) return dp[i][n-1-i];
    //     int take=0,nottake=0;
    //     if(equal(0,i-1,s)==equal(i,n-1,s))
    //     {
    //         take=1+fun(i-1,s,n,dp);
    //     }
    //     else
    //     {
    //         nottake=fun(i-1,s,n,dp);
    //     }
    //     return dp[i][n-1-i]=take+nottake;
    // }
    // int equal(int n,int m,string s)
    // {
    //     int count=0;
    //     unordered_map<char,int>mp;
    //     for(int i=n;i<=m;i++)
    //     {
    //         mp[s[i]]++;
    //     }
    //     for(auto i:mp)
    //     {
    //         if(i.second>0)
    //         {
    //             count++;
    //         }
    //     }
    //     return count;
    // }
    int numSplits(string s) {
        // int n=s.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return fun(n-1,s,n,dp);
        
        
        vector<int> freqLeft(26) , freqRight(26);
        int cnt1=0,cnt2=0,ans=0;
        for(char ch : s) if(!freqRight[ch-'a']++) cnt2++;
        for(char ch : s)
        {
            if(!freqLeft[ch-'a']++) cnt1++;
            if(--freqRight[ch-'a'] == 0) cnt2--;
            if(cnt1==cnt2) ans++;
        }
        return ans;
    }
};