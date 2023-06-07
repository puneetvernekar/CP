class Solution {
public:
    int ans=0,temp=0;
    void dfs(int node,unordered_map<int,vector<int>>&m,vector<int>&informTime)
    {
        ans=max(ans,temp);
        for(auto x:m[node])
        {
            temp+=informTime[node];
            dfs(x,m,informTime);
            temp-=informTime[node];    
        }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>>m;
        for(int i=0;i<n;i++)
        if(manager[i]!=-1)
        m[manager[i]].push_back(i);
        
        dfs(headID,m,informTime);
        return ans;
    }
};