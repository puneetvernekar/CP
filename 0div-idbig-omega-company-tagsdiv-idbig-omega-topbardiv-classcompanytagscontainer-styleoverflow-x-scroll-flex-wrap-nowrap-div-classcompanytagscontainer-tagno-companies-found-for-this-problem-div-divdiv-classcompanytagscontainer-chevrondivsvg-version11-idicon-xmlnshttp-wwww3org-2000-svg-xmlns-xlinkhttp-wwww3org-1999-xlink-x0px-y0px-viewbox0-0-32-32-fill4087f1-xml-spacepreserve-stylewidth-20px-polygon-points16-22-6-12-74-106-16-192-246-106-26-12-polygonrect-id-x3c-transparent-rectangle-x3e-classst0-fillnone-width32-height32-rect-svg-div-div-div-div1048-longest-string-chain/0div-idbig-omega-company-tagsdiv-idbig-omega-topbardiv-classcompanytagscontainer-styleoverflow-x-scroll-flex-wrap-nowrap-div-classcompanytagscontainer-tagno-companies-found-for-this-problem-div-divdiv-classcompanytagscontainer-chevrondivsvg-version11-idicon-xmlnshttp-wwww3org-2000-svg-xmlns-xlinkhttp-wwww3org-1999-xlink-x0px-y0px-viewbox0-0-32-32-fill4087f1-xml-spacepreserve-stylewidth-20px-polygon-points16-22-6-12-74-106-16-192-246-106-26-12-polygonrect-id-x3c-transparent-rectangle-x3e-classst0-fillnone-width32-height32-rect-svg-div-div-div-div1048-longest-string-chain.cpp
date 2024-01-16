class Solution {
public:
    int dp[1001][1001];
    static bool WordSort(string &word1,string &word2)
    {
        return word1.length()<word2.length();
    }
    
    bool isPred(string &word1,string &word2)
    {
        int n=word1.size(),m=word2.size();
        if(n>=m || m-n!=1)
            return false;
        int i=0,j=0;
        
        while(i<n && j<m)
        {
            if(word1[i]==word2[j])
                i++;
            j++;
        }
        if(i==n)
            return true;
        return false;
    }
    
    int solve(int i,int pre,vector<string>&word)
    {
        if(i==word.size())
            return 0;
        if(pre!=-1 && dp[i][pre]!=-1)
            return dp[i][pre];
        int take=0;
        if(pre==-1 || isPred(word[pre],word[i]))
            take=1+solve(i+1,i,word);
        int skip=solve(i+1,pre,word);
        
        if(pre!=-1)
            dp[i][pre]=max(skip,take);
        return max(skip,take);
    }
    
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),WordSort);
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,words);
    }
};