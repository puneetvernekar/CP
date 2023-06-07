class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        return "1";
        if(n==2)
        return "11";
        string ans="11";
        for(int i=3;i<=n;i++)
        {
            string tempstr="";
            ans+='#';
            int cou=1;
            for(int j=1;j<ans.size();j++)
            {
                if(ans[j]!=ans[j-1])
                {tempstr+=to_string(cou)+ans[j-1];
                cou=1;}
                else
                cou++;
            }
            ans=tempstr;}
        return ans;
    }
};