class Solution {
public:
    int arrangeCoins(int n) {
        /*if(n==1)
        return 1;
        long long sum=0,c=0;
        for(long i=1;sum<=n;i++)
        {
        if(sum<=n)
        {sum=(i*(i+1))/2;
        c++;}
        else
        break;
        }
        return c-1;*/

        //binary search//
        long f=0,l=n;
        while(f<=l)
        {
            long mid=f+(l-f)/2;
            if((mid*(mid+1)/2)>n)
            l=mid-1;
            else
            f=mid+1;
        }
        return (int)f-1;
                                                        //Quadratic equation
        //maths --> k*(k+1)/2<=n -->after solving -->k^2+k<=n --> k=root(2n+1/4)-1/2
        return sqrt(2*n+0.25)-0.5;
    }
};