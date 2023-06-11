class Solution {
public:
    bool isSubsequence(string s, string t) {
        string ans;
        int i=0,j=0;
        while(i<s.size() && j<t.size())
        {
            if(s[i]==t[j])
            {ans+=s[i];
            i++;
            j++;
            }
            else
            j++;
        }
        if(s==ans)
        return true;
        return false;
    }
};