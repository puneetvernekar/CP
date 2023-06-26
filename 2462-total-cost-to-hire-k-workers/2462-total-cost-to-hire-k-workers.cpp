class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans=0;
        priority_queue<int,vector<int>,greater<int>>q1,q2;
        int i=0,j=costs.size()-1;
        int fir_ele,sec_ele;
        while(k--)
        {
            int fir_ele=INT_MAX,sec_ele=INT_MAX;
            while(q1.size()<candidates && i<=j)
                q1.push(costs[i++]);
            while(q2.size()<candidates && j>=i)
                q2.push(costs[j--]);
            if(q1.size()>0)
                fir_ele=q1.top();
            if(q2.size()>0)
                sec_ele=q2.top();
            if(fir_ele<=sec_ele)
            {
                ans+=fir_ele;
                q1.pop();
            }
            else
            {
                ans+=sec_ele;
                q2.pop();
            }
        }
        return ans;
        
    }
};