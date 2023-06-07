class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s="";
    int strsSize=strs.size();
    for(int i=0;i<strs[0].length();i++)
    {   char c=strs[0][i];
    bool match=true;
        for(int j=1;j<strsSize;j++)
        {
            if(c!=strs[j][i])
            {
                match=false;
                break;
            }
        }
    if(match==false)
        break;
    else
        s.push_back(c);
    }
return s; 
    }
};