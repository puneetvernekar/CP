class Solution {
public:
    bool find(vector<vector<int>>&grid,int row,int col)
    {
        int dirx[4]={0,0,-1,1},diry[4]={1,-1,0,0};
        queue<pair<int,int>>q;
        for(int x=0;x<col;x++)
        {
            if(grid[0][x]==0)
            {
                q.push({0,x});
                grid[0][x]=1;
            }
        }
        while(!q.empty())
        {
            auto [r,c]=q.front();
            q.pop();
            if(r==row-1)
                return true;
            for(int i=0;i<4;i++)
            {
                int nr=r+dirx[i],nc=c+diry[i];
                if(nr<0 || nr==row || nc<0 || nc==col || grid[nr][nc]==1)
                    continue;
                grid[nr][nc]=1;
                q.push({nr,nc});
            }
        }
        return false;
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int left=1,right=cells.size(),ans=0;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            vector<vector<int>>grid(row,vector<int>(col,0));
            for (int i = 0; i < mid; ++i) 
                grid[cells[i][0]-1][cells[i][1]-1] = 1;
            if(find(grid,row,col))
            {
                ans=mid;
                left=mid+1;
            }
            else
                right=mid-1;
        }
        return ans;
    }
};