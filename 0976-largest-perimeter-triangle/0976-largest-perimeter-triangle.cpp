class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<nums.size()-2;i++)
        {
            int one=nums[i];
            int two=nums[i+1];
            int three=nums[i+2];
            if(one+two>three && one+three>two && three+two>one)
            {
                return one+two+three;
            }
        }
        return 0;
    }
};