class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0;
        vector<int>ans;
       for(int i=0;i<nums.size();i++)
       {
           if(nums[i]%2==0)
           {
               sum+=nums[i];
           }
       }
       for(int i=0;i<queries.size();i++)
       {
           int flag=0,temp=0;
           if( nums[queries[i][1]]%2==0)
           {
               flag=1;
               temp=nums[queries[i][1]];
           }
           nums[queries[i][1]]=nums[queries[i][1]]+queries[i][0];
           
           if(nums[queries[i][1]]%2==0)
           {
                if(flag==1)
                {
                    sum=sum-temp;
                    sum=sum+nums[queries[i][1]];
                }
               else
               {
                   sum+=nums[queries[i][1]];
               }
           }
           else
           {
               if(flag==1)
               {
                    sum=sum-temp;
               }
           }
           ans.push_back(sum);
       }
        return ans;
        
    }
};