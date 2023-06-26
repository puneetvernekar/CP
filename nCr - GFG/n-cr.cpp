//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        // code here
        // if(n<r)
        // return 0;
        // int ans=1,mod=1e9+7;
        // for(int i=1;i<=r;i++)
        // ans=(((ans*(n-r+i))%mod)/i)%mod;
        // return ans%mod;
        
        int mod=1e9+7,ans=1;
        if(n<r)
        return 0;
        int dp[r+1]={0};
        dp[0]=1;
        for(int i=1;i<=n;i++)
        for(int j=min(i,r);j>0;j--)
        dp[j]=(dp[j]+dp[j-1])%mod;
        return dp[r];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends