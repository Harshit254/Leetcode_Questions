class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>s(wordList.begin(),wordList.end());
        s.erase(beginWord);
        while(!q.empty())
        {
            string word=q.front().first;
            int level=q.front().second;
                q.pop();
            if(word==endWord)
            {
                return level;
            }
            for(int i=0;i<word.length();i++)
            {
                char original=word[i];
                for(char j='a';j<='z';j++)
                {
                    word[i]=j;
                    if(s.find(word)!=s.end())
                    {
                        s.erase(word);
                        q.push({word,level+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
        
    }
};