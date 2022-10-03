class Solution {
public:
bool equalFrequency(string word)
{
map<char,int>mp;
for(int i=0;i<word.size();i++)
{
mp[word[i]]++;
}
set<int>st;
for(int i=0;i<word.size();i++)
{
st.insert(word[i]);
}
int x=st.size();
int y=word.size();
if(y%x==1 || y%x==(x-1) || x==y)
{
return true;
}
return false;
}
};