class Solution {
public:
    bool isHappy(int n) {
        long d,sum;
        int count=0,x=n;
        while(x && count<999)
        {count++;
        n=x;
        sum=0;
        while(n)
        {   d=n%10;
            sum+=pow(d,2);
            n=n/10;
        }
        x=sum;
        if(sum==1)
        return true;
        }
        return false;
    }
};