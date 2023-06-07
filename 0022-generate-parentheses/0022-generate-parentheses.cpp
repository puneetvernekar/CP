class Solution {
public:
     vector<string> generateParenthesis(int n) {
        int c1=0,c2=0;
        string s="";
        vector<string>ans;
        solve(c1,c2,n,ans,s);
        return ans;
    }
    void solve(int c1,int c2,int n,vector<string> &ans,string s)
    {
            if(c1==n && c2==n)
            {ans.push_back(s);
            return;}
            if(c1<n)
            solve(c1+1,c2,n,ans,s+"(");
            if(c2<c1)
            solve(c1,c2+1,n,ans,s+")");
    }
};