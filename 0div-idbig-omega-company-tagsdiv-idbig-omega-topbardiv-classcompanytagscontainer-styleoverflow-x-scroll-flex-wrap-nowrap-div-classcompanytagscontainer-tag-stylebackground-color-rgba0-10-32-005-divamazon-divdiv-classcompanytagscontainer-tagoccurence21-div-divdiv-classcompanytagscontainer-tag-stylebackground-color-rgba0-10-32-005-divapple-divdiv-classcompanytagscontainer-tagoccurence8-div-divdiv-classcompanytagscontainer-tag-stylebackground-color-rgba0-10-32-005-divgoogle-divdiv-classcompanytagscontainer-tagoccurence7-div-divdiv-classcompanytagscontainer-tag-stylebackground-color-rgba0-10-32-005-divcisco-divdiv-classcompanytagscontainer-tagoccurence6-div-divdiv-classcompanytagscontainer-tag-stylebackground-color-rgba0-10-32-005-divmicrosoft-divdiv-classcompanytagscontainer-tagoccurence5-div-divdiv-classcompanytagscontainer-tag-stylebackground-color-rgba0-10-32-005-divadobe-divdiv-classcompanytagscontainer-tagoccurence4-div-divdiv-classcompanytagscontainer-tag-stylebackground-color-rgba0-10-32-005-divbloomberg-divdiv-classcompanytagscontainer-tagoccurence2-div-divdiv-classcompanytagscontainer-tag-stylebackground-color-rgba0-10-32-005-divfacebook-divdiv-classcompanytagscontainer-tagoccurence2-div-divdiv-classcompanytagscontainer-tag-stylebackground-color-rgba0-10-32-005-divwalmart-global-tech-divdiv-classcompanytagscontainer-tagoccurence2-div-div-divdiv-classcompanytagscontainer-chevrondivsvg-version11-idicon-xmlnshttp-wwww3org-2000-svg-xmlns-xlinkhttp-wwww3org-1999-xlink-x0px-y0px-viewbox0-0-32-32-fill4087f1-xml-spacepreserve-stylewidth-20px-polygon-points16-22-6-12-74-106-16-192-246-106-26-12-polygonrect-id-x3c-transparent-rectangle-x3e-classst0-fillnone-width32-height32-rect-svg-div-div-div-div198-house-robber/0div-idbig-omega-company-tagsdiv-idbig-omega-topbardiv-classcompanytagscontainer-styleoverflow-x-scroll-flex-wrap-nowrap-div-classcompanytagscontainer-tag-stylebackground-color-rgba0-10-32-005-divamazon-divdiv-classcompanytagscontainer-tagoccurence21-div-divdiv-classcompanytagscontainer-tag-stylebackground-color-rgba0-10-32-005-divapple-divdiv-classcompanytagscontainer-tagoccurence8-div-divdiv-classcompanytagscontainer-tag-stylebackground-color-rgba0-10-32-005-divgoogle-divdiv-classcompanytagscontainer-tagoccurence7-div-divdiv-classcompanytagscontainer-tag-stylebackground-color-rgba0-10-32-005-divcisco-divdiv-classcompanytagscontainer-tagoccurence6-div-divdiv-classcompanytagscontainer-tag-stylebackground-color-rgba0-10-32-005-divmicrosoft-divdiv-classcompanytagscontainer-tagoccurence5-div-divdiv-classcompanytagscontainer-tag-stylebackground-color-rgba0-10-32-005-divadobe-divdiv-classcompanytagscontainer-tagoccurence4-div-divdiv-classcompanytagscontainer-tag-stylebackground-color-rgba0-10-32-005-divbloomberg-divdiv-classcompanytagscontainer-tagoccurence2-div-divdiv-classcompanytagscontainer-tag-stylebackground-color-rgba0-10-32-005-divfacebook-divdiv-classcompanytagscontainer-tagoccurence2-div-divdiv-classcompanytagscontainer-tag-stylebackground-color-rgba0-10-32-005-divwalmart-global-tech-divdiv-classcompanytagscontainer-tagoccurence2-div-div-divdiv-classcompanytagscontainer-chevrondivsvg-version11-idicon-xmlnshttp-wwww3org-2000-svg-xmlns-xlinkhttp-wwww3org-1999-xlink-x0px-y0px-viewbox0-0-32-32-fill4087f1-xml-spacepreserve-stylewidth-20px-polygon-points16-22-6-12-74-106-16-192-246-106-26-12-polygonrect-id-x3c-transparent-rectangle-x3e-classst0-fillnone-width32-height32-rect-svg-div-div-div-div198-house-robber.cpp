class Solution {
public:
    int solve(vector<int>&nums,int i,vector<int>&dp)
    {
        if(i>=nums.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int steal=nums[i]+solve(nums,i+2,dp);
        int skip=solve(nums,i+1,dp);
        
        return dp[i]=max(steal,skip);
    }
    
    int rob(vector<int>& nums) {
        vector<int>dp(101,-1);
        int ans=solve(nums,0,dp);

        return ans;
    }
};