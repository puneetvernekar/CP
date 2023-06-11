class Solution {
public:
    int addDigits(int num) {
        int s=0;
        while(num)
        {int d=num%10;
        s+=d;
        num=num/10;
        if(num==0 && s<=9)
        return s;
        if(num==0 && s>9)
        {num=s;
        s=0;}
        }
        return 0;
    }
};