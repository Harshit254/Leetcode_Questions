class Solution {
public:
    string breakPalindrome(string palindrome) {
        int flag=0;
        
        for(int i=0;i<palindrome.size()/2;i++)
        {
            if(palindrome[i]!='a')
            {
                palindrome[i]='a';
                flag=1;
                break;
            }
        }
        if(flag==1) return palindrome;
        else if(flag==0 && palindrome.size()!=1)
        {
            palindrome[palindrome.size()-1]='b';
            return palindrome;
        }
        else return "";
    }
};