class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string sa,ta;
        for(char c: s)
        {
            if(c!='#')
            sa.push_back(c);
            else if(!sa.empty())
            sa.pop_back();
        }
        for(char c: t)
        {
            if(c!='#')
            ta.push_back(c);
            else if(!ta.empty())
            ta.pop_back();
        }
        if(sa==ta)
        return true;
        return false;
    }
};