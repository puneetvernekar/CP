class Solution {
public:
    bool check(int r,int col,int n,vector<string>&board)
    {
        int tr=r,tc=col;
        while(tc>=0)
        {
            if(board[tr][tc]=='Q')
                return false;
            tc--;
        }
        tr=r,tc=col;
        while(tr>=0 && tc>=0)
        {
            if(board[tr][tc]=='Q')
                return false;
            tr--,tc--;
        }
        tr=r,tc=col;
        while(tr<n && tc>=0)
        {
            if(board[tr][tc]=='Q')
                return false;
            tr++,tc--;
        }
        return true;
    }
    void solve(int col,int n,vector<string> &board,vector<vector<string>>&ans)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(check(i,col,n,board))
            {
                board[i][col]='Q';
                solve(col+1,n,board,ans);
                board[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string s(n,'.');
        vector<string>board(n,s);
        solve(0,n,board,ans);
        return ans;
    }
};