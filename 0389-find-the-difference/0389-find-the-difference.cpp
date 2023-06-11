class Solution {
public:
    char findTheDifference(string s, string t) {
        int ss=0,ts=0;
        for(int i=0;i<s.size();i++)
        {   char c1=s[i];
            ss+=c1;
        }
        for(int j=0;j<t.size();j++)
        {   char c2=t[j];
            ts+=c2;
        }
        return ts-ss;
    }
};