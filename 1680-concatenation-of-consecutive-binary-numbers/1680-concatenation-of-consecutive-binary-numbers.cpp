class Solution {
public:
    // int concatenatedBinary(int n) {
    //     vector<string>st;
    //     for(int i=1;i<=n;i++)
    //     {
    //         string s;
    //         int temp=i;
    //         while(temp!=0)
    //         {
    //             s+=(temp%2+'0');
    //             temp=temp/2;
    //         }
    //         reverse(s.begin(),s.end());
    //         st.push_back(s);
    //     }
    //     string str;
    //     for(int i=0;i<st.size();i++)
    //     {
    //         str+=st[i];
    //     }
    //     long long int sum=0;
    //     cout<<str<<endl;
    //     int k=0;
    //     for(int i=str.length()-1;i>=0;i--)
    //     {
    //         sum+=(str[i]-'0')*pow(2,k);
    //         sum=sum%1000000007;
    //         k++;
    //     }
    //     return sum%1000000007;
    // }
    long long int MOD = 1e9+7;
    
    int countbits(int n){
        return log2(n)+1;
    }
    
    int concatenatedBinary(int n) {
        
        long long temp = 0;
        for(int i=1;i<=n;i++) temp = ((temp<<countbits(i))^i)%MOD;
        return temp%MOD;
        
    }
};