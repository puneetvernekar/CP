//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    void dfs(vector<vector<int>>& image,vector<vector<int>>&vis, int sr, int sc,int ini, int newColor)
    {
        vis[sr][sc]=1;
        image[sr][sc]=newColor;
        int dx[]={0,0,-1,1};
        int dy[]={1,-1,0,0};
        for(int i=0;i<4;i++)
        {
            int nsr=sr+dx[i],nsc=sc+dy[i];
            if(nsr>=0 && nsc>=0 && nsr<image.size() && nsc<image[0].size() && image[nsr][nsc]==ini && !vis[nsr][nsc])
            dfs(image,vis,nsr,nsc,ini,newColor);
            
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n=image.size(),m=image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ini=image[sr][sc];
        dfs(image,vis,sr,sc,ini,newColor);

        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends