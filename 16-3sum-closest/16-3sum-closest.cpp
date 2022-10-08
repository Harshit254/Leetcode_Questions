class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
         sort(nums.begin(),nums.end());
        int i=0,diff=INT_MAX,ans=0;
        while(i<nums.size()){
            int j = i+1, k = nums.size()-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(abs(target-sum)<diff){
                    diff = abs(target-sum);
                    ans = sum;
                }
                if(sum == target) return target;
                else if(sum<target) j++;
                else k--;
            }
            i++;
        }
        return ans;
    }
};