class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
            int sum=0;
            int i=0;
            int flag=0;
            while(true)
            {
                sum+=pow(2,i);
                if(n==pow(2,i))
                {
                    flag=1;
                    break;
                }
                else if(sum>=n)
                {
                    break;
                }
                i++;
            }
        vector<int>temp;
        while(n>0)
        {
            if(n>=pow(2,i))
            {
                n=n-pow(2,i);
                temp.push_back(pow(2,i));
            }
            i--;
        }
        reverse(temp.begin(),temp.end());
        vector<int>rs;
        for(int j=0;j<queries.size();j++)
        {
            int a=queries[j][0];
            int b=queries[j][1];
            long long int res=temp[queries[j][0]];
            int c=a+1;
            while(c<=b)
            {
                res=(res*temp[c])%1000000007;
                c++;
            }
            rs.push_back((int)res);
        }
        return rs;
    }
};