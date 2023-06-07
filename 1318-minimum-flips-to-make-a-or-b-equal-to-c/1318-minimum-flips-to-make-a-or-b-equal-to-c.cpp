class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0;
        for(int i=0;i<=31;i++)
        {
            int a_ibit=(a>>i)&1;
            int b_ibit=(b>>i)&1;
            int c_ibit=(c>>i)&1;
            if(c_ibit==1)
            {
                if(a_ibit==0 && b_ibit==0)
                count++;
            }
            else
            {
                if(a_ibit==1 && b_ibit==1)
                count+=2;
                else if((a_ibit==1 && b_ibit==0) || (a_ibit==0 && b_ibit==1))
                count++;
            }
        }
        return count;
    }
};