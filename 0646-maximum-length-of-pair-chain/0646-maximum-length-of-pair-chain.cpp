class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<int> ans(pairs.size(),1);
        sort(pairs.begin(),pairs.end());
        for(int i=1;i<pairs.size();i++)
        for(int j=0;j<i;j++)
        if(pairs[j][1]<pairs[i][0] && ans[j]+1>ans[i])
        ans[i]=ans[j]+1;

        return *max_element(ans.begin(),ans.end());

    }
};