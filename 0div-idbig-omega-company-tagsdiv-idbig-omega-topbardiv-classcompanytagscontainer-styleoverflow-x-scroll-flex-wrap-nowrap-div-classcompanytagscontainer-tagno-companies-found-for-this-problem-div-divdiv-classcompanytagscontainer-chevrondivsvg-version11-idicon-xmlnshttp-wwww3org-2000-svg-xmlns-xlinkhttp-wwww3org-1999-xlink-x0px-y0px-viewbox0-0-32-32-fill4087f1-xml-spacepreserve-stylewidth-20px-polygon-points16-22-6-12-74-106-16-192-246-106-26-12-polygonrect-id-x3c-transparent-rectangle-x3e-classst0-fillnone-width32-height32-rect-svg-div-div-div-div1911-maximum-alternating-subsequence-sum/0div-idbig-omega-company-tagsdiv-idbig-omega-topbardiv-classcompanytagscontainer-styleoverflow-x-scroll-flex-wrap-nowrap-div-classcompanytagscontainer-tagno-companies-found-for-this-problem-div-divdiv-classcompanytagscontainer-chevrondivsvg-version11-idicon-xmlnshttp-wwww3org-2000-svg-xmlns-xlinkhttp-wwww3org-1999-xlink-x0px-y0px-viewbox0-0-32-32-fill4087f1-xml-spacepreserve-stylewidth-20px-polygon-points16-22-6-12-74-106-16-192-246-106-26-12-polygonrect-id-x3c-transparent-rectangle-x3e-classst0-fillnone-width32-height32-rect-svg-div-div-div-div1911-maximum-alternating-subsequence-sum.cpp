class Solution {
public:
    long long dp[100001][2];
    long long solve(int i,vector<int>&nums,int flag)
    {
        if(i>=nums.size())
        return 0;
        if(dp[i][flag]!=-1)
            return dp[i][flag];
        long long skip=solve(i+1,nums,flag);
        long long value=nums[i];
        if(flag==false)
            value=-value;
        long long take=solve(i+1,nums,!flag)+value;
        
        return dp[i][flag]=max(skip,take);
        
        
        
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        long long n=nums.size();
        return solve(0,nums,true);
    }
};