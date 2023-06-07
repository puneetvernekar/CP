class Solution {
public:
    int climbStairs(int n) {
        int a[1000]={0,1,2};
        if(n<=2)
        return a[n];
        for(int i=3;i<=n;i++)
        a[i]=a[i-1]+a[i-2];
        return a[n];
    }
};