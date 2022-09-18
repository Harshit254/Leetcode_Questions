class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int left=height[0];
        int right=height[n-1];
        int ans=0;
        while(l<=r){
            if(left<right){
                if(left<height[l]){
                    left=height[l];
                }
                else{
                    ans+=left-height[l];
                }
                l++;
            }
            else{
                if(right<height[r]){
                    right=height[r];
                }
                else{
                    ans+=right-height[r];
                }
                r--;
            }
        }
        return ans;
    }
};