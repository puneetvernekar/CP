class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> m1;
        map<string,char> m2;        
        stringstream str(s);
        vector <string> v;
        string sam;
        while(getline(str,sam,' '))
        v.push_back(sam);
        if(v.size()!=pattern.size())
        return false;
        for(int i=0;i<v.size();i++)
        {if(m1.count(pattern[i]))
            if(m1[pattern[i]]!=v[i])
                return false;

        if(m2.count(v[i]))
            if(m2[v[i]]!=pattern[i])
                return false;

        m1[pattern[i]]=v[i];
        m2[v[i]]=pattern[i];
        }
        return true;
    }
};