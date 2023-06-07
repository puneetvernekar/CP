class Solution {
public:
    int lengthOfLastWord(string s) {
        bool b=false;
        int c=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(b && s[i]==' ')
            break;
            else if(s[i]!=' ')
            {c++;
            b=true;}
        }
        return c;
    }
};