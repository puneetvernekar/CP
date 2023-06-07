class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int c=0,k=0;
        for(int i=0;i<board.size();i++)
        for(int j=0;j<board[0].size();j++)
            if(word[0]==board[i][j] && check(board,i,j,word,0))
            return true;
        return false;
    }

    bool check(vector<vector<char>>& board,int i,int j,string word,int p)
{
    if(p==word.size())
    return true;
    if(i<0 || j<0 || i>=board.size() || j>=board[0].size())
    return false;
    if(word[p]!=board[i][j])
    return false;
    char t=board[i][j];
    board[i][j]='*';
    if((check(board,i+1,j,word,p+1))||(check(board,i-1,j,word,p+1))||(check(board,i,j+1,word,p+1))||(check(board,i,j-1,word,p+1)))
    return true;
    board[i][j]=t;
    return false;
    }
};