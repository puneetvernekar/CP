class Solution {
public:
    static bool compare(const vector<int> &v1,const vector<int> &v2)
    {
        return v1[0]<v2[0];
    }
    int find(int ind,int count,vector<vector<int>>& events,vector<vector<int>>&dp)
    {
        int n=events.size();
        if(count==0 || ind==n)
            return 0;
        if(dp[ind][count]!=-1)
            return dp[ind][count];
        int ans = find(ind+1,count,events,dp);
        if(count){
           vector<int> temp = {events[ind][1],INT_MAX,INT_MAX};
           int nxt_ind = upper_bound(events.begin(), events.end(), temp)-events.begin();
           ans = max(ans, events[ind][2] + find(nxt_ind,count-1,events,dp));
        }
        return dp[ind][count]=ans;
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
    
        sort(events.begin(),events.end());
        int n=events.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));

        return find(0,k,events,dp);
    }
};