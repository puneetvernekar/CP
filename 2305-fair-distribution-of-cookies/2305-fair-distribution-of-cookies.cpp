class Solution {
public:
    void help(vector<int> &cookies,vector<int> &count,int k,int &ans,int index)
    {
        if(index==cookies.size())
        {
            int m=0;
            for(int i=0;i<k;i++)
            {
                m=max(m,count[i]);
            }
            ans=min(ans,m);
            return;
        }
        for(int i=0;i<k;i++)
        {
            count[i]+=cookies[index];
            help(cookies,count,k,ans,index+1);
            count[i]-=cookies[index];   
        }
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        int ans=INT_MAX;
        vector<int>count(k);
        help(cookies,count,k,ans,0);
        return ans;
    }
};