//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        //code here
        int mod=1e9+7;
        vector<long>ans(n+1,0);
        ans[0]=1,ans[1]=1;
        if(n==0 || n==1)
        return 1;
        for(int i=2;i<=n;i++)
        {
            int k=i-1;
            for(int j=0;j<i;j++)
            {
                ans[i]=(ans[i]+(ans[j]*ans[k--])%mod)%mod;
            }
        }
        return ans[n];
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends