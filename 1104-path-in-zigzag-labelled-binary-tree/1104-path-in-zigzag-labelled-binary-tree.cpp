class Solution {
public:
    vector<int> pathInZigZagTree(int n) {
         int lastValue = 1; // start and end of root node will be 1
    int currVal = 0 ; // To traverse to the given root/level
    
    while(currVal <n)
    {
        currVal += lastValue; // to reach the correct level
        lastValue *=2;
    }
    
    lastValue /=2; // to come back to the original level 
    
    vector<int> ans;
    while( n != 1)
    {
        ans.emplace_back(n);
        int complement = 3*lastValue - n - 1; // start = lastValue , end = 2*lastValue-1 , compl = start + end - n;
        int parent = complement/2;   // parent = complement of n/2;
        n = parent;  // update number
        lastValue /=2; // decrease level
    }
    ans.emplace_back(1);
    sort(ans.begin(),ans.end());
    return ans;
    }
};