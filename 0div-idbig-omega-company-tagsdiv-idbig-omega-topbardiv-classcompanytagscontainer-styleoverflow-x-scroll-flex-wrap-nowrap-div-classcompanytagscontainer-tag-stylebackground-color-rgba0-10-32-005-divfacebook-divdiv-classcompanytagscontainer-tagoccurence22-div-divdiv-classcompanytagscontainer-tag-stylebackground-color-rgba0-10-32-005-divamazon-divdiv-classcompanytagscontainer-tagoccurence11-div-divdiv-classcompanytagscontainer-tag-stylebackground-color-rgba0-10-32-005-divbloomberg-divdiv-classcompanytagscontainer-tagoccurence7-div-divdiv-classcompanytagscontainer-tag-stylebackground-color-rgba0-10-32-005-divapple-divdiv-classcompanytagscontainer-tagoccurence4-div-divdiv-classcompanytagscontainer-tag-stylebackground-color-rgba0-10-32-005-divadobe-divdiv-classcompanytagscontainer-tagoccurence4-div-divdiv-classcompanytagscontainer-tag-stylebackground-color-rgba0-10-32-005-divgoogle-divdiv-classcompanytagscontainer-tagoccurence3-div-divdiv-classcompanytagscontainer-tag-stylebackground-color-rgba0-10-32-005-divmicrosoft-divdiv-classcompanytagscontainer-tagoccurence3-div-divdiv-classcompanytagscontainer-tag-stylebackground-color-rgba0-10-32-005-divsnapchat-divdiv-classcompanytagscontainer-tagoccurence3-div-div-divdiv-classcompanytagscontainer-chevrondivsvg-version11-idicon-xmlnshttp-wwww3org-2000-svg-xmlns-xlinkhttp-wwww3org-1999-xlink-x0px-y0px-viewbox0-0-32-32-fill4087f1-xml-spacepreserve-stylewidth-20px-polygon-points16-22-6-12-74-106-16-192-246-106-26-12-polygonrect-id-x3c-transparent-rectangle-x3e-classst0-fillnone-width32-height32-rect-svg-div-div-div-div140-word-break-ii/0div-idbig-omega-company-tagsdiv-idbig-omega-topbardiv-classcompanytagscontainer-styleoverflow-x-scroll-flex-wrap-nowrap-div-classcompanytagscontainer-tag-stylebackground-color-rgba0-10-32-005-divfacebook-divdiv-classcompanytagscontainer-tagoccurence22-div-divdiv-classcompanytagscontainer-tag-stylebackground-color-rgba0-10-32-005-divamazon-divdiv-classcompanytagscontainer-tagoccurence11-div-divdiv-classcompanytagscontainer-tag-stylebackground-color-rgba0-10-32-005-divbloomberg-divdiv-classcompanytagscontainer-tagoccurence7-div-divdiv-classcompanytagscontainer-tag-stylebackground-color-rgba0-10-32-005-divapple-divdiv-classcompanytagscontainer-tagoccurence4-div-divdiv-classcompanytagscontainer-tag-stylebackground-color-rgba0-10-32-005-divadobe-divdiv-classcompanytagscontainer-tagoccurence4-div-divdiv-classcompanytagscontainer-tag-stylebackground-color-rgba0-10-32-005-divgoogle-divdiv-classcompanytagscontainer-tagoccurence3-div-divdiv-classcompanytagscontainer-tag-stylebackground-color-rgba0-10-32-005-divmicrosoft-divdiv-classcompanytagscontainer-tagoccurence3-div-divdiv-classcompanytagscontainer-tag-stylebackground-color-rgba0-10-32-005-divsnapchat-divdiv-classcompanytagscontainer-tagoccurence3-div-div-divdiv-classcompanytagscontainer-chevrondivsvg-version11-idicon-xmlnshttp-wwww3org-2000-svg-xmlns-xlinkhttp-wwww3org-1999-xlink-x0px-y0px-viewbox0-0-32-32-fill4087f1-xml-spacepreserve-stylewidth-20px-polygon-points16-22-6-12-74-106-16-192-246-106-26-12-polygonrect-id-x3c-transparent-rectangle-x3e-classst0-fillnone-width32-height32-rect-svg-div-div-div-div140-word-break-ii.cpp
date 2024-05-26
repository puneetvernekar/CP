class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        vector<string>ans;
        
        for(string word:wordDict)
        {
            if(s.substr(0,word.size())==word)
            {
                if(s.size()==word.size())
                    ans.push_back(word);
                else
                {
                    vector<string>tempo=wordBreak(s.substr(word.size()),wordDict);
                    
                    for(string temp_word:tempo)
                        ans.push_back(word+" "+temp_word);
                }
            }
        }
        return ans;
    }
};