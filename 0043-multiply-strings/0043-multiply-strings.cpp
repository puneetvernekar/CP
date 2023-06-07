class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")
        return "0";
        string ans(num1.size()+num2.size(),'0');
        int c;
        for(int i=num1.size()-1;i>=0;i--)
        {
            c=0;
            for(int j=num2.size()-1;j>=0;j--)
            {
                int t=(ans[i+j+1]-'0')+(num1[i]-'0')*(num2[j]-'0')+c;
                ans[i+j+1]=t%10+'0';
                c=t/10;
            }
            ans[i]=ans[i]+c;
        }
        int j=0;
        while(ans[j]=='0')
        j++;
        return ans.substr(j);
    }
};