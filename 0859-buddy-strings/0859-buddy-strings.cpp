class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())
            return false;
        if(s==goal)
        {
            int cou[26]={0};
            for(int i=0;i<s.size();i++)
            {
                int c=s[i]-'a';
                cou[c]++;
                if(cou[c]==2)
                    return true;
            }
        }
        int ind1=-1,ind2=-1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=goal[i])
            {
                if(ind1==-1)
                    ind1=i;
                else if(ind2==-1)
                    ind2=i;
                else
                    return false;
            }
        }
        if(ind2==-1)
            return false;
        if(s[ind1]==goal[ind2] && s[ind2]==goal[ind1])
            return true;
        return false;
    }
};