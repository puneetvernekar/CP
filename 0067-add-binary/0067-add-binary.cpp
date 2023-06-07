class Solution {
public:
    string addBinary(string a, string b) {
        int m=a.size();
        int n=b.size();
        bool c=false;
        string ans="";
        if((m-n)>0)
        {   for(int i=0;i<m-n;i++)
                b="0"+b;
        }
        else if((m-n)<0)
        {   for(int i=0;i<n-m;i++)
                a="0"+a;
        }
        cout<<a<<" "<<b;
            for(int i=a.size()-1;i>=0;i--)
            {
                if(a[i]=='0' and b[i]=='1')
                {   if(c)
                    ans.append("0");
                    else
                    ans.append("1");
                }
                else if(a[i]=='1' and b[i]=='0')
                {   if(c)
                    ans.append("0");
                    else
                    ans.append("1");
                }
                else if(a[i]=='0' and b[i]=='0')
                {   if(c)
                    {ans.append("1");
                    c=false;
                    }
                    else
                    ans.append("0");
                }
                else if(a[i]=='1' and b[i]=='1')
                {   if(c)
                    ans.append("1");
                    else
                    {ans.append("0");
                    c=true;
                    }
                    c=true;
                }
            }
            if(c)
            ans.append("1");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};