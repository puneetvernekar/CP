class Solution {
public:
    int firstUniqChar(string s) {
        int ans=-1;
        map<char,int>m;
        for(int i=0;i<s.size();i++)
        m[s[i]]++;
        for(char c:s)
        {if(m[c]==1)
        {ans=s.find(c);
        break;}
        }
        return ans;
    }
};