// class Solution {
// public:
//     bool equationsPossible(vector<string>& equations) {
//         vector<char>adj[];
//         for(int i=0;i<equations.size();i++)
//         {
//             if(equations[i][1]==equations[i][2] && equations[i][2]=='=')
//             {
//                 adj[equations[i][0]].push_back(equations[i][3]);
//                 adj[equations[i][3]].push_back(equations[i][0]);
//             }
//         }
//         for(auto s:equations)
//         {
            
//         }
//         return true;
//     }
// };
class Solution {
public:
    map<char,list<char>> mp;
    
    bool dfs_helper(char src,char des,map<char,bool> &visited)
    {
        if(src==des)
            return true;

        visited[src]=true;
        
        for(auto nbr: mp[src])
        {
            if(!visited[nbr])
            {
                if(dfs_helper(nbr,des,visited))
                    return true;
            }
        }
        
        return false;
    }
    
    bool dfs(char src,char des)
    {
        map<char,bool> visited;
        
        return dfs_helper(src,des,visited);
    }
    
    bool equationsPossible(vector<string>& equations) {
        for(auto s:equations)
        {
            if(s[1]=='=')
            {
                mp[s[0]].push_back(s[3]);
                mp[s[3]].push_back(s[0]);
            }
        }
        
        for(auto s:equations)
        {
            if(s[1]=='!')
            {
                if(dfs(s[0],s[3])==true)
                    return false;
            }
        }
        
        return true;
    }
};