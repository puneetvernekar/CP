class Solution {
    unordered_map<string,vector<string>>dp;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        if(dp.find(s)!=dp.end())
            return dp[s];
        
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
        return dp[s]=ans;
    }
};