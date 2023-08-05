//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(vector<vector<int>>&grid,vector<vector<int>>&vis,int x,int y,int n,int m)
    {
        vis[x][y]=1;
        int dx[]={0,0,-1,1},dy[]={1,-1,0,0};
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]==1)
            dfs(grid,vis,nx,ny,n,m);
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if((i==0 || i==n-1 || j==0 || j==m-1) && !vis[i][j] && grid[i][j]==1)
        dfs(grid,vis,i,j,n,m);
        
        int ans=0;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(!vis[i][j] && grid[i][j]==1)
        ans++;
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends