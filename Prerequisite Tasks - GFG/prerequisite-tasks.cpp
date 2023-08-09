//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(vector<int>adj[],vector<int>&vis,vector<int>&path,int node)
    {
        vis[node]=1,path[node]=1;
        for(int ele:adj[node])
        {
            if(!vis[ele])
            {if(dfs(adj,vis,path,ele))
            return true;}
            else if(path[ele])
            return true;
        }
        path[node]=0;
        return false;
    }
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int>vis(N,0),path(N,0);
	    vector<int>adj[N];
	    for(auto it:prerequisites)
	    {
	        adj[it.second].push_back(it.first);
	    }
	    
	    for(int i=0;i<N;i++)
	    {
	        if(!vis[i])
	        if(dfs(adj,vis,path,i)==true)
	        return false;
	    }
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends