class Solution {
public:
    char repeatedCharacter(string s) {
        map<char,int> m;
        for(int i=0;i<s.size();i++)
        {
            if(m[s[i]]>0)
            return s[i];
            else
            m[s[i]]++;
        }
        return 0;
    }
};