class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i=1;
        if(nums.size()<3)
        return nums[0];
        sort(nums.begin(),nums.end());
        while(i<nums.size())
        {
            if(nums[i]!=nums[i-1])
            return nums[i-1];
            i=i+3;
        }
        return nums[nums.size()-1];
    }
};