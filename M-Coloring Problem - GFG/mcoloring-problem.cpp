//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool possible(bool graph[101][101],int colors[],int col,int node,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(graph[node][i]==1 && colors[i]==col && i!=node)
            return false;
        }
        return true;
    }
    bool find(bool graph[101][101],int colors[],int m,int n,int node)
    {
        if(node==n)
        return true;
        for(int i=1;i<=m;i++)
        {
            if(possible(graph,colors,i,node,n))
            {
                colors[node]=i;
                if(find(graph,colors,m,n,node+1))
                return true;
                colors[node]=0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int colors[n]={0};
        if(find(graph,colors,m,n,0))
        return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends