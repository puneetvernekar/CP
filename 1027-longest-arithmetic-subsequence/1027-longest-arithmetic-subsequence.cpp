class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        if(nums.size()<=2)
            return nums.size();
        map<int,int>dp[nums.size()+1];
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                int dif=nums[i]-nums[j];
                int count=1;
                if(dp[j].count(dif))
                    count=dp[j][dif];
                dp[i][dif]=count+1;
                ans=max(ans,dp[i][dif]);
            }
        }        
        return ans;
    }
};