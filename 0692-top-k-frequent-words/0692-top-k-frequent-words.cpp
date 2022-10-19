class Solution {
public:
    typedef pair<string, int> stringPair;
    
    // Helper function to help the priority queue sort  
    // by frequency and lexicographical order as well.
    struct Compare {
      bool operator() (stringPair a, stringPair b)
      {
          // Same frequency means sort by lexicographical order.
          if(a.second == b.second)
            return a.first > b.first;
          
          // Otherwise just take the frequency into account.
          return a.second < b.second;
      }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        
        for(auto i:words)
        {
            mp[i]++;
        }
       // priority_queue<pair<int,string>>pq;
         priority_queue<stringPair, vector<stringPair>, Compare>pq;
        for(auto &i:mp)
        {
            pq.push(i);
        }
        vector<string>res;
        while(k--)
        {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};