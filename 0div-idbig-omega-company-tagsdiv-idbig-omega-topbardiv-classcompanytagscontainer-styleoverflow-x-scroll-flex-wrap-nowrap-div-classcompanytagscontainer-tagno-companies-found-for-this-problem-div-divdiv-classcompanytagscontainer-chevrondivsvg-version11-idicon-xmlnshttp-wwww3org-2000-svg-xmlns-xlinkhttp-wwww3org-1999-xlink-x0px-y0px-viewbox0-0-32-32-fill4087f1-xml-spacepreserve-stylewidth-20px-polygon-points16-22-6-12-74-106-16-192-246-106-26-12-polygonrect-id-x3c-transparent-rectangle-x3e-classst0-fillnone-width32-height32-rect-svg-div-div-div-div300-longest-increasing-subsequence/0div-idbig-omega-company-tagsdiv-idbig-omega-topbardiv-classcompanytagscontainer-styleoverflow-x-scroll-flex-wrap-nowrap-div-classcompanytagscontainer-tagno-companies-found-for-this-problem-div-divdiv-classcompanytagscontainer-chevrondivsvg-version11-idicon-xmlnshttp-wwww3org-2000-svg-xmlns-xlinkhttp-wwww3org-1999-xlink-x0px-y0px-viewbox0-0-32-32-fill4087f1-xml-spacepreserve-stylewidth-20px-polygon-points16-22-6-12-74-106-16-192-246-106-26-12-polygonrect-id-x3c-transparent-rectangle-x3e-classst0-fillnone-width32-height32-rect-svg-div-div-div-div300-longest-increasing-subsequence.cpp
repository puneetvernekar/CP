class Solution {
public:
//     int dp[2501][2501];
//     int solve(int i,int p,vector<int>&nums)
//     {
//         if(i>=nums.size())
//             return 0;
//         if(p!=-1 && dp[i][p]!=-1)
//             return dp[i][p];
//         int take=0;
//         if(p==-1 || nums[i]>nums[p])
//         {
//             //int prev=nums[i];
//             take=1+solve(i+1,i,nums);    
//         }
//         int skip=solve(i+1,p,nums);
        
//         if(p!=-1)
//             dp[i][p]=max(take,skip);
        
//         return max(take,skip);
//     }
    
    int lengthOfLIS(vector<int>& nums) {
        
        // int prev=-1;
        // memset(dp,-1,sizeof(dp));
        // return solve(0,prev,nums);
        
        int n=nums.size();
        vector<int>dp(n,1);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
        
    }
};