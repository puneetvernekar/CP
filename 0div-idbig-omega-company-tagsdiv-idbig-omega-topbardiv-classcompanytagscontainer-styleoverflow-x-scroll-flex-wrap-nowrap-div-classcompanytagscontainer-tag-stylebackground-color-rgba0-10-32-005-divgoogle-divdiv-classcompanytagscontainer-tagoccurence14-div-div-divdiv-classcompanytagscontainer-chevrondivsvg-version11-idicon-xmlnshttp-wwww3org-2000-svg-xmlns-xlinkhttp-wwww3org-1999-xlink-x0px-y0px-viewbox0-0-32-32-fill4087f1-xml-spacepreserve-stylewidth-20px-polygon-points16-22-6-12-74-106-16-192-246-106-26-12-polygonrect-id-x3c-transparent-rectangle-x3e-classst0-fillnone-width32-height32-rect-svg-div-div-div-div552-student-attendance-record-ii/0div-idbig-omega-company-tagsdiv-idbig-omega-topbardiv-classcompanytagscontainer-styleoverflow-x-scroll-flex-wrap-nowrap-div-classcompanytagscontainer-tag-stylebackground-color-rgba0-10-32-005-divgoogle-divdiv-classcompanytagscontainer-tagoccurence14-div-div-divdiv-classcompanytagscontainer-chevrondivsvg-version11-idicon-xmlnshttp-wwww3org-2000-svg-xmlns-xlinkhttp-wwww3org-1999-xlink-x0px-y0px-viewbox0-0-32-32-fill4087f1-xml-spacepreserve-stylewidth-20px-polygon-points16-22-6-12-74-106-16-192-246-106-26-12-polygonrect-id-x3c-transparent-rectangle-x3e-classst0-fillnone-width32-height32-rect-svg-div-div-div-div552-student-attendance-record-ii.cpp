class Solution {
public:
    long long mod=1e9+7;
    int checkRecord(int n) {
      
        long long dp[100001][3][3];
        memset(dp,-1,sizeof(dp));
        
        return solve(dp,n,0,0);
    }
    
    long long solve(long long dp[100001][3][3],int n,int ab,int l)
    {
        if(n==0)
            return 1;
        
        if(dp[n][ab][l]!=-1)
            return dp[n][ab][l];
        
        long long ans=0;
        ans=(solve(dp,n-1,ab,0))%mod;
        if(ab<1)
            ans+=(solve(dp,n-1,ab+1,0))%mod;
        if(l<2)
            ans+=(solve(dp,n-1,ab,l+1))%mod;
        
        return dp[n][ab][l]=ans%mod;
    }
};