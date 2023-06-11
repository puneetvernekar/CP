class Solution {
public:

    void dfs(int node,unordered_map<int,vector<int>>&m,vector<bool>&visited)
    {
        visited[node]=true;
        for(auto x:m[node])
        {
            if(!visited[x])
            dfs(x,m,visited);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>>m;
        int n=isConnected.size();
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(!(i==j))
        {if(isConnected[i][j]==0)
        m[i].push_back(0);
        else
        m[i].push_back(j);}
        int ans=0;
        for(int i=0;i<n;i++)
        if(!visited[i])
        {   ans++;
            dfs(i,m,visited);
        }
        return ans;
    }
};