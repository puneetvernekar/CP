//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        // code here
        //OPTIMAL
        vector<int>num;
        int fact=1;
        for(int i=1;i<n;i++)
        {
            fact*=i;
            num.push_back(i);
        }
        num.push_back(n);
        k=k-1;  // AS WE ARE USING ZERO BASED INDEXING
        string ans="";
        while(true)
        {
            int row=k/fact;
            ans+=to_string(num[row]);
            num.erase(num.begin()+row);
            if(num.size()==0)
            break;
            k=k%fact;
            fact=fact/num.size();
        }
        return ans;
        
        /*
        vector<int>str;
        for(int i=1;i<=n;i++)
        str.push_back(i);
        for(int i=0;i<k-1;i++)
        next_permutation(str.begin(),str.end());
        string ans="";
        for(int i=0;i<n;i++)
        ans+=str[i]+'0';
        return ans;*/
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends