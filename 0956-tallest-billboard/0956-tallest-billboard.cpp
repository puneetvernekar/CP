class Solution {
public:
    int find(int i,int dif,vector<int>&rods,int dp[21][2 * 5000 + 1])
    {
        if(i==rods.size())
        {
            if(dif==0)
                return 0;
            return INT_MIN;
        }
        
        int &ans=dp[i][dif+5000];
        if(ans!=-1)
            return ans;
        
        int option1=find(i+1,dif,rods,dp);
        int option2=rods[i]+find(i+1,dif+rods[i],rods,dp);
        int option3=find(i+1,dif-rods[i],rods,dp);
        
        return ans=max({option1,option2,option3});
    }
    
    int tallestBillboard(vector<int>& rods) {
        
        int dp[21][2 * 5000 + 1];
        fill_n(*begin(dp),21*(2*5000+1),-1);
        int ans=find(0,0,rods,dp);
        if(ans<0)
            return 0;
        return ans;
    }
};