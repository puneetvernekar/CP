class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int,int>>sub;
        for(int i=0;i<nums.size();i++)
            sub.push_back({nums[i],cost[i]});
        sort(sub.begin(),sub.end());
        long long tot_sum=0;
        for(int i=0;i<nums.size();i++)
            tot_sum+=sub[i].second;
        long long j=0,med,total=0;
        while(total<(tot_sum+1)/2 && j<nums.size())
        {
            total+=sub[j].second;
            med=sub[j].first;
            j++;
        }
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans+= 1L* abs(nums[i]-med)*cost[i];
        }
        return ans;
        
    }
};