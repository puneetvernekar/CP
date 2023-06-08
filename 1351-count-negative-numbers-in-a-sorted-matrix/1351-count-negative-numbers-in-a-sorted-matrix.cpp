class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            int posi=upper_bound(grid[i].rbegin(),grid[i].rend(),-1)-grid[i].rbegin();
            ans+=posi;
        }
        return ans;
    }
};