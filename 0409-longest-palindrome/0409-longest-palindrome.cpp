class Solution {
public:
    int longestPalindrome(string s) {
        int ans=0;
        map<char,int>m;
        bool che=false;
        if(s.size()==1)
        return 1;
        for(char c:s)
        m[c]++;
        for(auto c:m)
        {
        if(c.second%2==0)
        ans+=c.second;
        else
        {che=true;
        ans+=c.second-1;}}
        if(che)
        return ans+1;
        return ans;
    }
};