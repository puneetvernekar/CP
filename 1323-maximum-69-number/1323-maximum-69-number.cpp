class Solution {
public:
    int maximum69Number (int num) {
        string ans;
        bool b=true;
        string n=to_string(num);
        for(char c: n)
        {if(c=='6' && b==true)
        {ans+='9';
        b=false;}
        else
        ans+=c;
        }
        return stoi(ans);
    }
};