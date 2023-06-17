class Solution {
public:
    int dp[2000][2001];
    
    int helper(vector<int>& a1, vector<int>& a2, int i1, int j, int prev){
        if(i1 >= a1.size()) return 0;
        int k = upper_bound(a2.begin()+j, a2.end(), prev) - a2.begin();
        // if replace compulsory and not able to replace return infinity
        if(a1[i1] <= prev && k >= a2.size()) return 2000;
        if(dp[i1][k]!= -1) {
            return dp[i1][k];
        }
        // Case to replace if possible
        int case1  = k<a2.size()? 1 + helper(a1,a2,i1+1,k+1, a2[k]) : 2000;
        // Case to not replace if possible
        int case2 = a1[i1] > prev ? helper(a1,a2,i1+1, k, a1[i1]) : 2000;
        dp[i1][k] = min(case1,case2);
        return dp[i1][k];
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        memset(dp,-1,sizeof(dp));
        auto ans = helper(arr1, arr2, 0, 0, INT_MIN);
        return ans < 2000? ans : -1;
    }
};