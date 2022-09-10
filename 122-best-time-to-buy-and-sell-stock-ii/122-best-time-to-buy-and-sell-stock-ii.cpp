class Solution {
public:
    int maxProfit(vector<int>&nums) {
        int sum=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                sum+=nums[i]-nums[i-1];
            }
        }
        return sum;
    }
};