class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend>=INT_MAX && divisor == -1)return -1*INT_MAX;
        else if(dividend<=INT_MIN && divisor==-1)return INT_MAX;
        else if (dividend >= INT_MAX && divisor == 1) return INT_MAX;
		else if(dividend <= INT_MIN && divisor == 1)return INT_MIN;
        long divd=abs(dividend);
        long div=abs(divisor);
        int ans=0;
        while(divd>=div)
        {
            long sum=div,c=1;
            while(divd-sum>=sum)
            {
                sum*=2;
                c*=2;
            }
            ans+=c;
            divd-=sum;
        }
        if((divisor>0 && dividend>0) || (divisor<0 && dividend<0))
        return ans;
        return -1*(ans);
    }
};