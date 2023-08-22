//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        int ans=0;
        vector<int>rsum,csum;
        for(int i=0;i<n;i++)
        {
            int rtemp=0,ctemp=0;
            for(int j=0;j<n;j++)
            {
                rtemp+=matrix[i][j];
                ctemp+=matrix[j][i];
            }
            rsum.push_back(rtemp);
            csum.push_back(ctemp);
        }
        
        int fin=max(*max_element(rsum.begin(),rsum.end()),*max_element(csum.begin(),csum.end()));
        for(int i=0;i<n;i++)
        ans+=fin-rsum[i];
        
        return ans;
        
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends