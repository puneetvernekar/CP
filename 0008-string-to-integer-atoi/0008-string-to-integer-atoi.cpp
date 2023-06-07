class Solution {
public:
    int myAtoi(string s) {
        long long int num=0;
        int mul=1,j=0;
        while(j<s.size() && s[j]==' ')
        j++;

        if(s[j] == '-'){
            mul = 0;
            j++;
        }
        else if(s[j] == '+')
            j++;

        while(j<s.size())
        {   int d=s[j] - '0';
            if(d<0 || d>9)
            break;
            if(num>=INT_MAX || num<=INT_MIN)
            break;
            if(s[j]>='0' && s[j]<='9')
            num=(num*10)+d;
            j++;
        }
        
        if(mul == 0)
            num = -1 * num;
        if(num <= INT_MIN)
            return INT_MIN;
        if(num >= INT_MAX)
            return INT_MAX;
        return num;
    }
};