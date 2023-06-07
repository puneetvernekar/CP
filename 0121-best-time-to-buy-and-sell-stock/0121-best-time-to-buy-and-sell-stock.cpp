class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=prices[0];
        int i=0,pro,max2=0;   
        int n=prices.size();
        for(int j=1;j<n;j++)
        {   if(prices[i]<prices[j])
            {pro=prices[j]-prices[i];
            max2=max(pro,max2);
            }
            else
            prices[i]=prices[j];
        }
        return max2;
    }
};