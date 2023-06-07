class Solution {
public:
    int reverse(int x) {
        if(x>=INT_MAX || x<=INT_MIN)
        return 0;
        long long int ans=0;
        int temp=abs(x);
        while(temp)
        {
            int d=temp%10;
            ans=ans*10+d;
            if(ans>=INT_MAX || ans<=INT_MIN)
            return 0;
            temp=temp/10;
        }
        if(x<0)
        return -1*ans;
        return ans;
    }
};