class Solution {
public:
    void bfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int r,int c,int n,int m)
    {
        vis[r][c]=1;
        queue<pair<int,int>>q;
        q.push({r,c});
        int dx[]={0,0,-1,1};
        int dy[]={1,-1,0,0};
        while(!q.empty())
        {
            int rval=q.front().first;
            int cval=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=rval+dx[i],ncol=cval+dy[i];
                
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol])
                {
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        queue<int>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(grid[i][j]=='1' && !vis[i][j])
        {
            ans++;
            bfs(grid,vis,i,j,n,m);
        }
        
        return ans;
        
    }
};