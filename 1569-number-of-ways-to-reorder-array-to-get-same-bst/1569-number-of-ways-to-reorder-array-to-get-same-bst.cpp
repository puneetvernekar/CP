class Solution {
public:
    long mod=1e9+7;
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long>>table(n+1);
        for(int i=0;i<=n;i++)
        {
            table[i]=vector<long>(i+1,1);
            for(int j=1;j<i;j++)
            {
                table[i][j]=(table[i-1][j-1]+table[i-1][j])%mod;
            }
        }
        long ans=dfs(nums,table);
        return ans%mod-1;
    }
    
    long dfs(vector<int>&nums,vector<vector<long>>&table)
    {
        int n=nums.size();
        if(n<=2)
            return 1;
        vector<int>left;
        vector<int>right;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[0])
                right.push_back(nums[i]);
            else
                left.push_back(nums[i]);
        }
        long left_ans=dfs(left,table)%mod;
        long right_ans=dfs(right,table)%mod;
        
        int left_size=left.size(),right_size=right.size();
        
        return (((table[n-1][left_size] * left_ans ) % mod)* right_ans)%mod;
    }
};