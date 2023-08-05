//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(vector<vector<int>>&grid,vector<vector<int>>&vis,vector<pair<int,int>>&temp,int x,int y,int xini,int yini)
    {
        int n=grid.size(),m=grid[0].size();
        vis[x][y]=1;
        int dx[]={0,0,-1,1},dy[]={1,-1,0,0};
        temp.push_back({x-xini,y-yini});
        
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny])
            dfs(grid,vis,temp,nx,ny,xini,yini);
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>s;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j])
                {
                    vector<pair<int,int>>temp;
                    dfs(grid,vis,temp,i,j,i,j);
                    s.insert(temp);
                }
            }
        }
        return s.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends