//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        // code here
        deque<int>q;
        int ans;
        for(int i=1;i<=N;i++)
        q.push_back(i);
        while(!q.empty())
        {
            int num=K;
            while(num-- && !q.empty())
            {ans=q.front();
            q.pop_front();}
            num=K;
            while(num-- && !q.empty())
            {ans=q.front();
            q.pop_back();}
            
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends