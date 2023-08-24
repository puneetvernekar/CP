//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */


    string multiplyStrings(string s1, string s2) {
       //Your code here
       long long n1=s1.size(),n2=s2.size();
       vector<int>num1,num2;
       bool n1_neg=false,n2_neg=false,num_found=true;
       int i=n1;
       while(i>0)
       {
          if(s1[n1-i]=='-')
          {
              n1_neg=true;
              i--;
              continue;
          }
          //num1=num1+((s1[n1-i]-48)*pow(10,i));
          if(s1[n1-i]=='0' && num_found)
          {
              i--;
              continue;
          }
          num1.push_back(s1[n1-i]-48);
          num_found=false;
          i--;
       }
       i=n2,num_found=true;
       while(i>0)
       {
          if(s2[n2-i]=='-')
          {
              n2_neg=true;
              i--;
              continue;
          }
          //num2=num2+((s2[n2-i-1]-48)*pow(10,i));
          if(s2[n2-i]=='0' && num_found)
          {
              i--;
              continue;
          }
          num2.push_back(s2[n2-i]-48);
          num_found=false;
          i--;
       }
       
        string ans(num1.size()+num2.size(),'0');
        //if((n1_neg==true && n2_neg==false) || (n1_neg==false && n2_neg==true))
        //ans[0]='-';
        int c;
        for(int i=num1.size()-1;i>=0;i--)
        {
            c=0;
            for(int j=num2.size()-1;j>=0;j--)
            {
                int t=(ans[i+j+1]-'0')+(num1[i])*(num2[j])+c;
                ans[i+j+1]=t%10+'0';
                c=t/10;
            }
            ans[i]=ans[i]+c;
        }
        int j=0;
        while(ans[j]=='0')
        j++;
        string main_ans=ans.substr(j);
        if((n1_neg==true && n2_neg==false) || (n1_neg==false && n2_neg==true))
        main_ans.insert(0,1,'-');
        return main_ans;

    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends