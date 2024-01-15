class Solution {
public:
    int dp[2501][2501];
    int solve(int i,int p,vector<int>&nums)
    {
        if(i>=nums.size())
            return 0;
        if(p!=-1 && dp[i][p]!=-1)
            return dp[i][p];
        int take=0;
        if(p==-1 || nums[i]>nums[p])
        {
            //int prev=nums[i];
            take=1+solve(i+1,i,nums);    
        }
        int skip=solve(i+1,p,nums);
        
        if(p!=-1)
            dp[i][p]=max(take,skip);
        
        return max(take,skip);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int prev=-1;
        memset(dp,-1,sizeof(dp));
        return solve(0,prev,nums);
    }
};