class Solution {
public:
    bool fun(int i,int jump,vector<int>&stones,unordered_map<int,int>&mp,vector<vector<int>>&dp)
    {
        if(i>=stones.size()) return false;
        if(i==stones.size()-1) 
        {
            return true;
        }
        if(dp[i][jump]!=-1) return dp[i][jump];
        for(int j=-1;j<=1;j++)
        {
            int nextjump=jump+j;
            int prevvalue=stones[i];
            int nextvalue=prevvalue+nextjump;
            if(mp.find(nextvalue)!=mp.end() && mp[nextvalue]>i)
            {
                if(fun(mp[nextvalue],nextjump,stones,mp,dp)) return dp[i][jump]=true;
            }
        }
        return dp[i][jump]=false;
        
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]-stones[0]>1) return false;
        unordered_map<int,int>mp;
        for(int i=1;i<stones.size();i++)
        {
            mp[stones[i]]=i;
        }
        vector<vector<int>>dp(2000,vector<int>(2000,-1));
        return fun(1,1,stones,mp,dp);
    }
};