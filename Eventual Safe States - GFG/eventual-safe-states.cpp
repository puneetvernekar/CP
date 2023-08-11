//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<int>adj[],vector<int>&vis,vector<int>&path,vector<int>&ans,int node)
    {
        vis[node]=1,path[node]=1;
        
        for(int ele:adj[node])
        {
            if(!vis[ele])
                dfs(adj,vis,path,ans,ele);
            if(path[ele])
                return;
        }
        ans.push_back(node);
        path[node]=0;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0),path(V,0),ans;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            dfs(adj,vis,path,ans,i);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends