class Solution {
public:
    int solve(int i,int n,vector<int>&nums,vector<int>&dp)
    {
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        
        int steal=nums[i]+solve(i+2,n,nums,dp);
        int skip=solve(i+1,n,nums,dp);
        
        return dp[i]=max(steal,skip);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(101,-1);
        int n=nums.size();
        if(n==1)
            return nums[0];
        int first=solve(0,n-1,nums,dp);
        vector<int>dp2(101,-1);
        int second=solve(1,n,nums,dp2);
        return max(first,second);
    }
};