class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int n1=num1.size()-1,n2=num2.size()-1,sum=0;
        while(n1>=0 || n2>=0|| sum)
        {
            if(n1>=0)
            {sum+=num1[n1]-'0';
            n1--;}
            if(n2>=0)
            {sum+=num2[n2]-'0';
            n2--;}
            ans.push_back((sum%10)+'0');
            sum=sum/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};