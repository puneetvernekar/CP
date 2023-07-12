class Solution {
public:
    bool dfs(vector<vector<int>>& adj,vector<int> &vis,vector<int> &path,int index)
    {
        vis[index]=1,path[index]=1;
        for(auto it:adj[index])
        {
            if(!vis[it] && dfs(adj,vis,path,it))
                return true;
            else if(path[it]==1)
                return true;
        }
        path[index]=0;
        return false;
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0),path(n,0),safe;
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
            for(int j=0;j<graph[i].size();j++)
                adj[i].push_back(graph[i][j]);
        for(int i=0;i<n;i++)
            if(!vis[i])
                dfs(adj,vis,path,i);
        
        for(int i=0;i<n;i++)
            if(path[i]==0)
                safe.push_back(i);
        return safe;
    }
};