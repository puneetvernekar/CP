//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        if(source.first==destination.first && source.second==destination.second)
        return 0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{source.first,source.second}});
        int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[source.first][source.second]=0;
        
        while(!q.empty())
        {
            int dis=q.front().first;
            int r=q.front().second.first,c=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr=r+dx[i],nc=c+dy[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && dist[nr][nc]>dis+1)
                {
                    dist[nr][nc]=dis+1;
                    q.push({dis+1,{nr,nc}});
                    if(nr==destination.first && nc==destination.second)
                    return dis+1;
                }
            }
        }
        return -1;
        
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends