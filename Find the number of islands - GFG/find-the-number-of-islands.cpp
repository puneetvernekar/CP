//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int r,int c,int n,int m)
    {
        if(r<0 || r>=n || c<0 || c>=m || grid[r][c]=='0' || vis[r][c])
        return;
        vis[r][c]=1;
        for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++)
        dfs(grid,vis,r+i,c+j,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(grid[i][j]=='1' && !vis[i][j])
        {
            dfs(grid,vis,i,j,n,m);
            ans++;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends