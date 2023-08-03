//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void dfs(vector<int>mat[],vector<int>&vis,int node)
    {
        vis[node]=1;
        for(int ele:mat[node])
        {
            if(!vis[ele])
            dfs(mat,vis,ele);
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int ans=0;
        vector<int>mat[V];
        for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
        if(adj[i][j]==1)
        mat[i].push_back(j);
        
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(mat,vis,i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends