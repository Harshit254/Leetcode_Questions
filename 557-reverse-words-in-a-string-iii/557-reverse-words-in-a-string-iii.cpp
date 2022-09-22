class Solution {
public:
    string reverseWords(string s) {
        stack<int>st;
        string str;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ' || i==s.length()-1)
            {
                if(i==s.length()-1)
                {
                    st.push(s[i]);
                }
                while(!st.empty())
                {
                    str+=st.top();
                    st.pop();
                }
                if(i!=s.length()-1)str+=' ';
            }
            else
            {
                st.push(s[i]);
            }
        }
        return str;
    }
};