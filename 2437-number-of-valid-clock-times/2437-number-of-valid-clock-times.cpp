class Solution {
public:
    int countTime(string s) {
        int total=1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='?' && i==0)
            {
                if(s[i+1]=='?')
                {
                    total*=24;
                    i++;
                }
                else
                {
                    if(s[i+1]>='4')
                    {
                        total*=2;
                    }
                    else
                    {
                        total*=3;
                    }
                }
            }
            else if(s[i]=='?' && i==1)
            {
                if(s[i-1]>'1')
                {
                    total*=4;
                }
                else
                {
                    total*=10;
                }
            }
            else if(s[i]=='?' && i==3)
            {
                if(s[i+1]=='?')
                {
                    total*=60;
                    i++;
                }
                else
                {
                    total*=6;
                }
            }
            else if(s[i]=='?' && i==4)
            {
                total*=10;
            }
        }
        return total;
    }
};