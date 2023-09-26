//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n=heights.size(),m=heights[0].size(),ans=INT_MAX;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
        while(!pq.empty())
        {
            int dis=pq.top().first;
            int r=pq.top().second.first,c=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int nr=r+dx[i],nc=c+dy[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                    int new_dis=max(abs(heights[r][c]-heights[nr][nc]),dis);
                    if(new_dis<dist[nr][nc])
                    {
                        dist[nr][nc]=new_dis;
                        pq.push({new_dis,{nr,nc}});
                    }
                    // if(nr==n-1 && nc==m-1)
                    // ans=min(ans,dis+heights[nr][nc]);
                }
            }
        }
        return dist[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends