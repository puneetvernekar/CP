class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int g_sum=accumulate(gas.begin(),gas.end(),0);
        int c_sum=accumulate(cost.begin(),cost.end(),0);
        
        int ans=0,ini=0;
        for(int i=0;i<gas.size();i++)
        {
            int new_dif=gas[i]-cost[i]+ini;
            ini=new_dif;
            if(new_dif<0)
            {
                ini=0;
                ans=i+1;
            }
        }
        if(g_sum<c_sum)
            return -1;
        return ans;
    }
};