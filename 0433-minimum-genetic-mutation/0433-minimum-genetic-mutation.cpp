class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string>st(bank.begin(),bank.end());
        queue<pair<string,int>>q;
        q.push({start,0});
        char c[]={'A','C','G','T'};
        while(!q.empty())
        {
            string str=q.front().first;
            int level=q.front().second;
            q.pop();
            if(str==end)
            {
                return level;
            }
            for(int i=0;i<str.size();i++)
            {
                char original=str[i];
                for(int j=0;j<4;j++)
                {
                    str[i]=c[j];
                    if(st.find(str)!=st.end())
                    {
                        st.erase(str);
                        q.push({str,level+1});
                    }
                }
                str[i]=original;
            }
        }
        return -1;
    }
};