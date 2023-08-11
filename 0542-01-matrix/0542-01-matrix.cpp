class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(mat[i][j]==0)
                q.push({{i,j},0}),vis[i][j]=1;
        int dx[]={0,0,-1,1},dy[]={1,-1,0,0};
        while(!q.empty())
        {
            int r=q.front().first.first,c=q.front().first.second,d=q.front().second;
            q.pop();
            mat[r][c]=d;
            for(int i=0;i<4;i++)
            {
                int nr=r+dx[i],nc=c+dy[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc])
                {
                    q.push({{nr,nc},d+1});
                    vis[nr][nc]=1;
                }
            }
        }
        return mat;
    }
};