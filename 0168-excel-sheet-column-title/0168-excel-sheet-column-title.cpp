class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        int n=columnNumber;
        while(n)
        {   
            int d=(n%26)+'A'-1;
            if(d>=65 && d<=90)
            ans.push_back(char(d));
            else
            {ans.push_back(char(d+26));
            n--;}
            n=n/26;     
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};