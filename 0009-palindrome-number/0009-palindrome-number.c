bool isPalindrome(int x){
int n=x;
long rev=0;
if(n<0)
{return false;
}  
while(n)
{int d=n%10;
rev=rev*10+d;
n=n/10;
}
return rev==x;
}