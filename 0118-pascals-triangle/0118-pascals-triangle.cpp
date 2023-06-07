class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a1;
        for(int i=0;i<numRows;i++)
        {vector<int> a2(i+1,1);
            for(int j=1;j<i;j++)
        {
            a2[j]=a1[i-1][j]+a1[i-1][j-1];
        }
        a1.push_back(a2);
        }        
        return a1;
    }
};