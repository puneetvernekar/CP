class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> x;
        int ans=0,st=0,en=0;
        while(st<s.size())
        {
            auto it=x.find(s[st]);
            if(it==x.end())
            {
                if((st-en+1)>ans)
                ans=st-en+1;
                x.insert(s[st]);
                st++;
            }
            else
            {
                x.erase(s[en]);
                en++;
            }
        }
        return ans;
    }
};