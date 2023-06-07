class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
         map<char,int>rm[9];
        map<char,int>cm[9];
        map<char,int>bm[9];
        for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {

            if(board[i][j]=='.')
            continue;
            if(!(rm[i][board[i][j]]))
            rm[i][board[i][j]]++;
            else
            return false;
            if(!(cm[j][board[i][j]]))
            cm[j][board[i][j]]++;
            else
            return false;
            if(!(bm[(i/3)*3+(j/3)][board[i][j]]))
            bm[(i/3)*3+(j/3)][board[i][j]]++;
            else
            return false;
        }
        return true;
    }
};