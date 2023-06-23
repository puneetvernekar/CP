//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        // code here
        map<char,int>m;
        int maxi_freq=0;
        char c;
        for(int i=0;i<N;i++)
        {   
            m[tasks[i]]++;
            if(m[tasks[i]]>maxi_freq)
            {   maxi_freq=m[tasks[i]];
                c=tasks[i];
            }
        }
        int chunks=maxi_freq-1;
        int idle_spots=chunks*K;
        
        for(auto it:m)
        {   
            if(it.first==c)
            continue;
            idle_spots-=min(chunks,it.second);
        }
            
        if(idle_spots<0)
        return N;
        return idle_spots+N;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends