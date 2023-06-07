class Solution {
public:
    string longestPalindrome(string s) {
        int max=1;
        int n=s.size();
        vector<vector<int>>ans(n,vector<int>(n,0));
        string strans;
        for(int d=0;d<s.size();d++)
        {
            for(int i=0,j=i+d;j<n;i++,j++)
            {
                if(i==j)
                ans[i][j]=1;
                else if(d==1)
                {
                    if(s[i]==s[j])
                    ans[i][j]=2;
                    else
                    ans[i][j]=0;
                }
                else
                {
                    if(s[i]==s[j] && ans[i+1][j-1])
                    ans[i][j]=ans[i+1][j-1]=2;
                }
                if(ans[i][j] && j-i+1>=max)
                {
                    max=j-i+1;
                    strans=s.substr(i,max);
                }
            }
        }
        
        return strans;
    }
};