class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> ans(coins.size()+1,vector<int>(amount+1));
        for(int i=0;i<=coins.size();i++)
        for(int j=0;j<=amount;j++)
        {   
            if(i==0)
            ans[i][j]=0;
            if(j==0)
            ans[i][j]=1;
        }
        for(int i=1;i<=coins.size();i++)
        for(int j=1;j<=amount;j++)
        {   
            if(j>=coins[i-1])
            ans[i][j]=ans[i][j-coins[i-1]]+ans[i-1][j];
            else
            ans[i][j]=ans[i-1][j];
        }
        return ans[coins.size()][amount];

    }
};