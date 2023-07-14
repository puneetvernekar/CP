class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int,int>m;
        int ans=1,prev;
        for(int x:arr)
        {
            int prev=m[x-difference];
            m[x]=prev+1;
            ans=max(ans,prev+1);
        }
        return ans;
    }
};