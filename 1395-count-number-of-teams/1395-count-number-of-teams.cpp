// class Solution {
// public:
//     int fun(int i,vector<int>&rating,int count,int prev)
//     {
//         if(count==3) return 1;
//         if(i>=rating.size())
//         {
//             if(count==3)
//             {
//                 return 1;
//             }
//             return 0;
//         }
//         int take=0,notake=0;
//         if(prev==-1 || rating[i]>rating[prev])
//         {
//             take=fun(i+1,rating,count++,i);
//             //cout<<rating[i]<<" ";
//         }
//         notake=fun(i+1,rating,count,prev);
//         return take+notake;
//     }
//     int fun2(int i,vector<int>&rating,int count,int prev)
//     {
//         if(count==3) return 1;
        
//         if(i>=rating.size())
//         {
//             if(count==3)
//             {
//                 return 1;
//             }
//             return 0;
//         }
//         int take=0,notake=0;
//         if(prev==-1 || rating[i]<rating[prev])
//         {
//             take=fun2(i+1,rating,count++,i);
//             //cout<<rating[i]<<" ";
//         }
//         notake=fun2(i+1,rating,count,prev);
//         return take+notake;
//     }
//     int numTeams(vector<int>& rating) {
//         int high=fun(0,rating,0,-1);
//         //cout<<endl;
//         int low=fun2(0,rating,0,-1);
//         cout<<high<<" "<<low;
//         return high+low;
//     }
// };






class Solution {
public:
    int dp1[1002][1002][4];
    int numTeams(vector<int>& arr) {
        
        memset(dp1,-1,sizeof(dp1));
        
        
        int idx=0;
        int prv=-1;
        int k=3;
        int count1=fun1(arr,idx,prv,k);
        
        
        memset(dp1,-1,sizeof(dp1));
        idx=0;
        prv=-1;
        k=3;
        int count2=fun2(arr,idx,prv,k);
        
        return count1+count2;
    }
    int fun1(vector<int>&arr,int idx,int prv,int k)
    {
        //base
       
        if(k==0)
            return 1;    
        
        if(idx>=arr.size() and k>0)
          return 0;
        if(idx>=arr.size() and k==0)
            return 1;
        
        if(dp1[idx][prv+1][k]!=-1)
        {
            return dp1[idx][prv+1][k];
        }
        
        int choise1=0;
        int choise2=0;
        
        if(prv==-1 or arr[prv]<arr[idx])
        choise1=fun1(arr,idx+1,idx,k-1);
        
        choise2=fun1(arr,idx+1,prv,k);
        
        return dp1[idx][prv+1][k] =choise1+choise2;
    }
    int fun2(vector<int>&arr,int idx,int prv,int k)
    {
        
        if(k==0)
            return 1;
        
        if(idx>=arr.size() and k>0)
          return 0;
        
        if(idx>=arr.size() and k==0)
            return 1;
        
        if(dp1[idx][prv+1][k]!=-1)
        {
            return dp1[idx][prv+1][k];
        }
        
        int choise1=0;
        int choise2=0;
        
        if(prv==-1 or arr[prv]>arr[idx])
        choise1=fun2(arr,idx+1,idx,k-1);
        
        choise2=fun2(arr,idx+1,prv,k);
        
        return dp1[idx][prv+1][k] =choise1+choise2;
    }
};