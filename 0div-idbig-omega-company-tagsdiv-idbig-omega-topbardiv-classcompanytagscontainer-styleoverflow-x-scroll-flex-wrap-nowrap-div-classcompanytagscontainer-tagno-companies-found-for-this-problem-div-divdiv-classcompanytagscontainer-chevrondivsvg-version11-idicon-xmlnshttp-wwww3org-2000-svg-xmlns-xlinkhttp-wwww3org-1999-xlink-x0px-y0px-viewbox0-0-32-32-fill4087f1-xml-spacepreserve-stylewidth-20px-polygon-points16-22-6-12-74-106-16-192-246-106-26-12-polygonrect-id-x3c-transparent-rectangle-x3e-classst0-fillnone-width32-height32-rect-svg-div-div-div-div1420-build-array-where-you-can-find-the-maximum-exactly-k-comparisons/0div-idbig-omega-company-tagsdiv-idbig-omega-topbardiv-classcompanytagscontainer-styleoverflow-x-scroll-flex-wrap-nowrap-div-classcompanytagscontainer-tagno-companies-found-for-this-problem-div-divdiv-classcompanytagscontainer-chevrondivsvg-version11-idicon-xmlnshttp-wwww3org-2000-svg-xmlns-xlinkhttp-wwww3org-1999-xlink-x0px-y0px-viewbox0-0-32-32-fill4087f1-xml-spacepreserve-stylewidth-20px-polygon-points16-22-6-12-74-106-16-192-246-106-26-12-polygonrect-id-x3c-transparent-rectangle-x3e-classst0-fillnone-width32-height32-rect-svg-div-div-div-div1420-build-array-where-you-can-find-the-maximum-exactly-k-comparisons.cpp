class Solution {
public:
    int size,tot,aim,mod=1e9+7;
    int dp[51][51][101];
    int solve(int i,int cost,int max_so_far)
    {
        if(i==size)
        {
            if(cost==aim)
                return 1;
            return 0;
        }
        if(max_so_far!=-1 && dp[i][cost][max_so_far]!=-1)
            return dp[i][cost][max_so_far];
        
        int ans=0;
        for(int j=1;j<=tot;j++)
        {
            if(j>max_so_far)
                ans=(ans+solve(i+1,cost+1,j))%mod;
            else
                ans=(ans+solve(i+1,cost,max_so_far))%mod;
        }
        
        if(max_so_far!=-1)
        return dp[i][cost][max_so_far]=ans%mod;
        
        return ans%mod;
    }
    
    int numOfArrays(int n, int m, int k) {
        size=n,tot=m,aim=k;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,-1);
    }
};