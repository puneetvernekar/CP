//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int check(int N)
    {
        if(N==1 || N==7)
        return 1;
        int sum=N,cur=N;
        while(sum>9)
        {
            sum=0;
            while(cur)
            {
                int d=cur%10;
                sum+=d*d;
                cur=cur/10;
            }
            if(sum==1)
            return 1;
            cur=sum;
        }
        if(sum==7)
        return 1;
        return 0;
    }

    int nextHappy(int N){
        // code here
        while(true)
        {
            N++;
            if(check(N)==1)
            return N;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends