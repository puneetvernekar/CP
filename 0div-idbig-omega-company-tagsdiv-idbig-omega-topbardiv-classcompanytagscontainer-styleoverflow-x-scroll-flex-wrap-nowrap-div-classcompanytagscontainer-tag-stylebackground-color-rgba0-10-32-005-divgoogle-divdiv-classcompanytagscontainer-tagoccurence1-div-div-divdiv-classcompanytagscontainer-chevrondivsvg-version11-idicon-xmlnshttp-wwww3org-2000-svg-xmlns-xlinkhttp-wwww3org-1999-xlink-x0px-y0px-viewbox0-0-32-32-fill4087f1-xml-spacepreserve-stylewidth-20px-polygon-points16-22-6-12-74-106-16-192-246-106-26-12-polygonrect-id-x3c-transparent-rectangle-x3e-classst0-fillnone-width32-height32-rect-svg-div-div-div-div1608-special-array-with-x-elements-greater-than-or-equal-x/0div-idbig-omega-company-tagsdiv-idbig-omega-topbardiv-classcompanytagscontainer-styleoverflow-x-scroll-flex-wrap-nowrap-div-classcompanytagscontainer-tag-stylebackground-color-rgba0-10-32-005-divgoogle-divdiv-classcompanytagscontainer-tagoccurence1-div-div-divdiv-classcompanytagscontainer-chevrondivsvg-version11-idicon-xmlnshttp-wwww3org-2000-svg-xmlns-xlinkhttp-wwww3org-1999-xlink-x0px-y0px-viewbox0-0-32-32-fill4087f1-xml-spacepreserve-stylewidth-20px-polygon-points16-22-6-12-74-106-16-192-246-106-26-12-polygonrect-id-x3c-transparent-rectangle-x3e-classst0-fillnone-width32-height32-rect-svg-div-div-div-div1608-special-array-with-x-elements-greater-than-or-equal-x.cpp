class Solution {
public:
    int specialArray(vector<int>& nums) {
        
        int ans=0;
        sort(nums.rbegin(),nums.rend());
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=ans)
            {
                ans++;
                if(ans>nums[i])
                    return -1;
            }   
            else
                return ans;
        }
        return nums.size();
    }
};