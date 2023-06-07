class Solution {
public:

    int calc(int i,int j,vector<int>&cuts,vector<vector<int>>&dp)
    {
        if(i>j)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans=INT_MAX;
        for(int index=i;index<=j;index++)
        {
            int cost=cuts[j+1]-cuts[i-1]+calc(index+1,j,cuts,dp)+calc(i,index-1,cuts,dp);
            ans=min(ans,cost);
        }
        dp[i][j]=ans;
        return dp[i][j];
    }

    int minCost(int n, vector<int>& cuts) {
        int cuts_size=cuts.size();
        vector<vector<int>>dp(cuts_size+1,vector<int>(cuts_size+1,-1));
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int ans=calc(1,cuts_size,cuts,dp);
        return ans;
    }
};