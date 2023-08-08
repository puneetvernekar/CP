//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool bfs(vector<int>adj[],vector<int>&vis,queue<int>&q,int strt)
    {
	    q.push(strt);
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        for(int ele:adj[node])
	        {
	            if(vis[ele]==-1)
	            {
	                q.push(ele);
	                vis[ele]=!vis[node];
	            }
	            else 
	            if(vis[ele]==vis[node])
	            return false;
	        }
	    }
	    return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>vis(V,-1);
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(vis[i]==-1)
            if(bfs(adj,vis,q,i)==false)
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
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends