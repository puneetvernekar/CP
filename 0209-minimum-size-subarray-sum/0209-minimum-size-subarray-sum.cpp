class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int i=0,j=0,ans=INT_MAX,tot=0;
        while(j<nums.size())
        {
            tot+=nums[j];
            while(tot>=target)
            {
                ans=min(ans,j-i+1);
                tot-=nums[i];
                i++;
            }
            j++;
        }
        if(ans==INT_MAX)
            return 0;
        return ans;
    }
};