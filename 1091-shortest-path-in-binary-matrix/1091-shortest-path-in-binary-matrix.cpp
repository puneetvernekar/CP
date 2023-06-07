class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        /*
        queue<pair<pair<int,int>,int>>que;
        que.push({{0,0},1});
        int n=grid.size();
        if(grid[0][0]==1)
        return -1;
        if(grid[0][0]==0 && n==1)
        return 1;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        visited[0][0]=true;
        while(!que.empty())
        {
            pair<int,int>p=que.front().first;
            int x=p.first;
            int y=p.second;
            int path_len=que.front().second;
            que.pop();

            vector<pair<int,int>>neighb={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
            for(pair<int,int>nei:neighb)
            {
                int newx=nei.first+x;
                int newy=nei.second+y;
                if(newx>=0 && newy>=0 && newx<n && newy<n && grid[newx][newy]==0 && !visited[newx][newy])
                {
                    que.push({{newx,newy},path_len+1});
                    visited[newx][newy]=true;
                    if(newx=n-1 && newy==n-1)
                    return path_len+1;
                }
            }
        }
        return -1;*/

        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        
        if(grid[0][0]==1)return -1;
        
        if(grid[0][0]==0 && grid.size()==1 && grid[0].size()==1)return 1;
        
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid.size(),false));
        visited[0][0]=true;
        while(!q.empty())
        {
            pair<int,int>p = q.front().first; //{0,0}
            int x = p.first; //0
            int y= p.second; //0
            int lengthOfPath = q.front().second; //1
            q.pop();
            
            vector<pair<int,int>>neighbours = {{0,1}, {0,-1}, {1,0}, {-1,0},
                                               {1,1}, {-1,-1}, {1,-1}, {-1,1}};
            
            for(pair<int,int>neighbour: neighbours)
            {
                int newx = neighbour.first + x;
                int newy = neighbour.second+ y;
                
                if(newx>=0 && newy>=0 && newx<grid.size() && newy<
                  grid[0].size() && grid[newx][newy]==0 &&
                  !visited[newx][newy])
                {
                    q.push({{newx,newy},lengthOfPath+1});
                    visited[newx][newy] = true;
                    
                    if(newx==grid.size()-1 && newy==grid[0].size()
                      -1)return lengthOfPath+1;
                    
                    
                }
                    
        
                
            }
            
        }
        
        return -1;

    }
};