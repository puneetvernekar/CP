class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<string,int>m;
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            string temp="";
            for(int j=0;j<grid[0].size();j++)
            {
                temp+=to_string(grid[i][j])+",";
            }
            m[temp]++;
        }
        for(int i=0;i<grid.size();i++)
        {
            string comp="";
            for(int j=0;j<grid[0].size();j++)
            {
                comp+=to_string(grid[j][i])+",";
            }
            if(m.find(comp)!=m.end())
                ans+=m[comp];
        }
        return ans;
    }
};