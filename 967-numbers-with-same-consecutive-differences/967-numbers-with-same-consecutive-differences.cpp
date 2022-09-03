class Solution {
public:
    void solve(int idx, int n, int k, int num, vector<int>&ans){
    if(idx==n){
        if(ans.empty() || ans.back()!=num){ 
            ans.push_back(num);
        }
        return;
    }    
    int lastDigit = num%10;
    if(lastDigit+k < 10){                
        solve(idx+1,n,k, num*10 + (lastDigit+k), ans);    
    }
    if(lastDigit-k >= 0){                      
        solve(idx+1,n,k, num*10 + (lastDigit-k), ans);
    }
    
    return;
}
vector<int> numsSameConsecDiff(int n, int k) {
    vector<int>ans;
    for(int i=1;i<10;i++){ 
        solve(1,n,k,i,ans);
    }
    return ans;
}
};