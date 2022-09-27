class Solution {
    public:
//     string pushDominoes(string dominoes) {
//         int n=dominoes.size();
//         queue<pair<pair<char,int>,int>>q;
//         vector<int>vis(n,-1);
//         vector<int>indi(n,-1);
//         for(int i=0;i<n;i++)
//         {
//             if(dominoes[i]=='L' || dominoes[i]=='R')
//             {
//                 q.push({{dominoes[i],i},0});
//                 vis[i]=1;
//                 indi[i]=0;
//             }
//         }
//         while(!q.empty())
//         {
//             char value=q.front().first.first;
//             int position=q.front().first.second;
//             int time=q.front().second;
//             q.pop();
//             if(value=='L')
//             {
//                 if(position-1>=0 && !vis[position-1] && dominoes[position-1]=='.')
//                 {
//                     dominoes[position-1]='L';
//                     q.push({{dominoes[position-1],position-1},time+1});
//                     vis[position-1]=1;
//                     indi[position-1]=time+1;
//                 }
//                 else if(vis[position-1] && dominoes[position-1]=='R' && position-1>=0)
//                 {
//                     if(indi[position-1]==time+1)
//                     {
//                         dominoes[position-1]='.';
//                     }
//                 }
//             }
//             else
//             {
//                 if(position+1<n && !vis[position+1] && dominoes[position+1]=='.')
//                 {
//                     dominoes[position+1]='R';
//                     q.push({{dominoes[position+1],position+1},time+1});
//                     vis[position+1]=1;
//                     indi[position+1]=time+1;
//                 }
//                 else if(vis[position+1] && dominoes[position+1]=='L' && position+1<n)
//                 {
//                     if(indi[position+1]==time+1)
//                     {
//                         dominoes[position+1]='.';
//                     }
//                 }
//             }
//         }
//         return dominoes;
//     }
    
    
    
    
    string pushDominoes(string s) {
    int N = s.size(), right = -1;
    for (int i = 0; i < N; ++i) {
        if (s[i] == 'L') {
            if (right == -1) { 
                // Step 2
                for (int j = i - 1; j >= 0 && s[j] == '.'; --j) {
                  s[j] = 'L';  
                } 
            } else {
                // Step 8
                for (int j = right + 1, k = i - 1; j < k; ++j, --k) {
                    s[j] = 'R';
                    s[k] = 'L';
                } 
                right = -1;
            }
        } else if (s[i] == 'R') {
            if (right != -1) {
                for (int j = right + 1; j < i; ++j) s[j] = 'R';
            }
            right = i;
        }
    }
    if (right != -1) {
        for (int j = right + 1; j < N; ++j) s[j] = 'R';
    }
    return s;
}
 };