class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prev=0,cur=0,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                ans=max(ans,prev+cur);
                prev=cur;
                cur=0;
            }
            else
            {
                cur++;
            }
        }
        ans=max(ans,prev+cur);
        if(ans==nums.size())
            return ans-1;
        return ans;
    }
};