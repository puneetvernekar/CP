//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) 
    {
        vector<vector<int>>edg(n,vector<int>(n,INT_MAX));
        for(int i=0;i<m;i++)
        {
            edg[edges[i][0]][edges[i][1]]=edges[i][2];
            edg[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int i=0;i<n;i++)
        edg[i][i]=0;
        
        for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(edg[i][k]==INT_MAX || edg[k][j]==INT_MAX)
            continue;
            edg[i][j]=min(edg[i][j],edg[i][k]+edg[k][j]);
        }
        
        int ans,cnt=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            int temp=0;
            for(int j=0;j<n;j++)
            {
                if(distanceThreshold>=edg[i][j])
                temp++;
            }
            if(temp<=cnt)
            {
                cnt=temp;
                ans=i;
            }
        }
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
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends