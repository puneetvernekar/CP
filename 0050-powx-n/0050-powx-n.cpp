class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long num=n;
        if(num<0)
        num=-1*num;
        while(num)
        {
            if(num%2==0)
            {x=x*x;
            num=num/2;}
            else
            {ans=ans*x;
            num=num-1;}
        }
        if(n<0)
        ans=1.0/ans;
        return ans;
    }
};