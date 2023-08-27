//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void find(vector<vector<int>> &m,vector<string>&ans,vector<vector<int>>&vis,string temp, int n,int r,int c)
    {
        if(r==n-1 && c==n-1)
        {
            ans.push_back(temp);
            //temp="";
            return;
        }
        int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
        string dir="URDL";
        for(int i=0;i<4;i++)
        {
            int nr=r+dx[i],nc=c+dy[i];
            if(nr>=0 && nr<n && nc>=0 && nc<n && m[nr][nc]==1 && !vis[nr][nc])
            {
                vis[r][c]=1;
                find(m,ans,vis,temp+dir[i],n,nr,nc);
                vis[r][c]=0;
            }
            
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>>vis(n,vector<int>(n,0));
        vector<string>ans;
        string temp="";
        if(m[0][0]==1)
        find(m,ans,vis,temp,n,0,0);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends