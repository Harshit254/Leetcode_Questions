class Solution {
public:
    int minCost(string colors, vector<int>&time) {
        int s=0;
        for(int i=0;i<colors.size()-1;i++)
        {
            if(colors[i]==colors[i+1])
            {
                int mini=min(time[i],time[i+1]);
                time[i+1]=max(time[i],time[i+1]);
                s+=mini;
            }
        }
        return s;
    }
};