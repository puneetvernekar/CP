class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int profit=0,effective_buy=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            profit=max(profit,prices[i]-effective_buy-fee);
            effective_buy=min(effective_buy,prices[i]-profit);
        }
        return profit;
    }
};