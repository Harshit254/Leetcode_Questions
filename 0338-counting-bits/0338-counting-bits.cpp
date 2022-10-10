class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        for(int i=0;i<=n;i++)
        {
            int num=i,c=0;
            while(num)
            {
                c+=num&1;
                num>>=1;
            }
            ans[i]=c;
        }
        
        return ans;
    }
};