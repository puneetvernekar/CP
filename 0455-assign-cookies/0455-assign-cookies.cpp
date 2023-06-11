class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.rbegin(),g.rend());
        sort(s.rbegin(),s.rend());
        int c=0,cur;
        for(int i=0,j=0;i<g.size();i++)
        if(j<s.size() && s[j]>=g[i])
        c++,j++;
        return c;
    }
};