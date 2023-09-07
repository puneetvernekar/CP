//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start==end)
        return 0;
        int mod=1e5;
        vector<int>vis(mod,0);
        queue<pair<int,int>>q;
        q.push({0,start});
        vis[start]=1;
        
        while(!q.empty())
        {
            int lev=q.front().first;
            int val=q.front().second;
            q.pop();
            for(int i=0;i<arr.size();i++)
            {
                int pro=(arr[i]*val)%mod;
                if(pro==end)
                return lev+1;
                if(!vis[pro])
                {
                    q.push({lev+1,pro});
                    vis[pro]=1;
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends