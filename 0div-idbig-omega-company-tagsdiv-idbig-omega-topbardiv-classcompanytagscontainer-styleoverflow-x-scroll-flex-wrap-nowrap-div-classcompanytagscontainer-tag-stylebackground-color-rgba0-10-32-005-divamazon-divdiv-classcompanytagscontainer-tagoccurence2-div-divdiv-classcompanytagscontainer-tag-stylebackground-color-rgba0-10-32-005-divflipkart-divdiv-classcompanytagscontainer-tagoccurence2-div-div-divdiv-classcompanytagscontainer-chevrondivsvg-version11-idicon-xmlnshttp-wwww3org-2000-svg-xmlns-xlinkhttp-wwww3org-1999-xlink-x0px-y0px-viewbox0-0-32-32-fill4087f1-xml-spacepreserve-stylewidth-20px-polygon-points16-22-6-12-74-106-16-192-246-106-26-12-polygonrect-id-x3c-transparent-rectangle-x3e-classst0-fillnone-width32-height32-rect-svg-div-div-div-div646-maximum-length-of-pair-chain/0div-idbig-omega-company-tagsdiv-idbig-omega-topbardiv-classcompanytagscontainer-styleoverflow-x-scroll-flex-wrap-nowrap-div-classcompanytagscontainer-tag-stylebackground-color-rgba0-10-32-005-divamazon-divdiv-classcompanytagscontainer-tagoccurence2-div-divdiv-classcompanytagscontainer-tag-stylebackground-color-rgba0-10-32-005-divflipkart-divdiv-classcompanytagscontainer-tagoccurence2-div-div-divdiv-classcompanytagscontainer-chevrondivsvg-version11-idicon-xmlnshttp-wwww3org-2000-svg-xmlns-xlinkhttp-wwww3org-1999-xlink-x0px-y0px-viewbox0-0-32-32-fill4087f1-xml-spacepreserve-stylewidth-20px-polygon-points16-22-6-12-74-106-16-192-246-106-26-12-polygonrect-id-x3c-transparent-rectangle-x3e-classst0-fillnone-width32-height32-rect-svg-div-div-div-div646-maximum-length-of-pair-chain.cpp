class Solution {
public:
    int dp[1001][1001];
    
    int solve(int i,int pre,vector<vector<int>>&nums)
    {
        if(i>=nums.size())
            return 0;
        
        int take=0;
        if(pre!=-1 && dp[i][pre]!=-1)
            return dp[i][pre];
        
        if(pre==-1 || nums[pre][1]<nums[i][0])
        {
            take=1+solve(i+1,i,nums);
        }
        int skip=solve(i+1,pre,nums);
        
        if(pre!=-1)
            dp[i][pre]=max(take,skip);
        
        return max(take,skip);
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        
        memset(dp,-1,sizeof(dp));
        sort(pairs.begin(),pairs.end());
        return solve(0,-1,pairs);

    }
};