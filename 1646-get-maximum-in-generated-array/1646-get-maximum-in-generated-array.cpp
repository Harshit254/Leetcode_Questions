class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        vector<int>nums(n+1,0);
        nums[0]=0;
        nums[1]=1;
        int mxx=1;
        if(n%2==0)
        {
            for(int i=1;i<n/2;i++)
            {
                nums[i*2]=nums[i];
                nums[(i*2)+1]=nums[i]+nums[i+1];
                int mx=max(nums[i*2],nums[(i*2)+1]);
                mxx=max(mxx,mx);
            }
        }
        else
        {
            for(int i=1;i<=n/2;i++)
            {
            nums[i*2]=nums[i];
            nums[(i*2)+1]=nums[i]+nums[i+1];
            int mx=max(nums[i*2],nums[(i*2)+1]);
            mxx=max(mxx,mx);
            }
        }
        return mxx;
    }
};