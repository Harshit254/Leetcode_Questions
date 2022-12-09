//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Disjointset
{
    vector<int>parent,rank,size;
    public:
    Disjointset(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUltimateparent(int node)
    {
        if(node==parent[node])return node;
        return parent[node]=findUltimateparent(parent[node]);
    }
    void unionbyrank(int u,int v)
    {
        int ulp_U=findUltimateparent(u);
        int ulp_V=findUltimateparent(v);
        if(ulp_U==ulp_V) return;
        else if(rank[ulp_U]>rank[ulp_V])
        {
           parent[ulp_V]=ulp_U; 
        }
        else if(rank[ulp_V]>rank[ulp_U])
        {
            parent[ulp_U]=ulp_V;
        }
        else
        {
            parent[ulp_V]=ulp_U;
            rank[ulp_U]++;
        }
    }
    public:
    void unionbysize(int u,int v)
    {
        int ulp_U=findUltimateparent(u);
        int ulp_V=findUltimateparent(v);
        if(ulp_U==ulp_V) return;
        if(size[ulp_U]<size[ulp_V])
        {
            parent[ulp_U]=ulp_V;
            size[ulp_V]+=size[ulp_U];
        }
        else
        {
            parent[ulp_V]=ulp_U;
            size[ulp_U]+=size[ulp_V];
        }
    }
};
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &details) {
        int n=details.size();
        Disjointset ds(n);
        unordered_map<string ,int>mp;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<details[i].size();j++)
            {
                if(mp.find(details[i][j])==mp.end())
                {
                    mp[details[i][j]]=i;
                }
                else
                {
                    ds.unionbysize(i,mp[details[i][j]]);
                }
            }
        }
        vector<string>merge[n];
        for(auto i:mp)
        {
            string s=i.first;
            int node=ds.findUltimateparent(i.second);
            merge[node].push_back(s);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++)
        {
            if(merge[i].size()==0) continue;
            sort(merge[i].begin(),merge[i].end());
            vector<string>temp;
            temp.push_back(details[i][0]);
            for(auto j:merge[i])
            {
                temp.push_back(j);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends