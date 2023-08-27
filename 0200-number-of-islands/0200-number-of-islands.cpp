class Solution {
public:
    void dfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int n,int m,int r,int c)
    {
        vis[r][c]=1;
        int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nr=r+dx[i],nc=c+dy[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && !vis[nr][nc])
            {
                dfs(grid,vis,n,m,nr,nc);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    ans++;
                    dfs(grid,vis,n,m,i,j);
                }
            }
        }
        return ans;
    }
};