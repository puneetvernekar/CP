class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>s(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        s.erase(beginWord);
        while(!q.empty())
        {
            string word=q.front().first;
            int count=q.front().second;
            q.pop();
            if(word==endWord)
                return count;
            for(int i=0;i<word.size();i++)
            {
                string temp=word;
                for(char ch='a';ch<='z';ch++)
                {
                    temp[i]=ch;
                    if(s.find(temp)!=s.end())
                    {
                        q.push({temp,count+1});
                        s.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};