class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> ans(coins.size()+1,vector<int>(amount+1));
        for(int i=0;i<=amount;i++)
        ans[0][i]=0;
        for(int i=0;i<=coins.size();i++)
        ans[i][0]=1;
        for(int i=1;i<=coins.size();i++)
        for(int j=1;j<=amount;j++)
        {if(j>=coins[i-1])
        ans[i][j]=ans[i][j-coins[i-1]]+ans[i-1][j];
        else
        ans[i][j]=ans[i-1][j];}
        return ans[coins.size()][amount];

    }
};