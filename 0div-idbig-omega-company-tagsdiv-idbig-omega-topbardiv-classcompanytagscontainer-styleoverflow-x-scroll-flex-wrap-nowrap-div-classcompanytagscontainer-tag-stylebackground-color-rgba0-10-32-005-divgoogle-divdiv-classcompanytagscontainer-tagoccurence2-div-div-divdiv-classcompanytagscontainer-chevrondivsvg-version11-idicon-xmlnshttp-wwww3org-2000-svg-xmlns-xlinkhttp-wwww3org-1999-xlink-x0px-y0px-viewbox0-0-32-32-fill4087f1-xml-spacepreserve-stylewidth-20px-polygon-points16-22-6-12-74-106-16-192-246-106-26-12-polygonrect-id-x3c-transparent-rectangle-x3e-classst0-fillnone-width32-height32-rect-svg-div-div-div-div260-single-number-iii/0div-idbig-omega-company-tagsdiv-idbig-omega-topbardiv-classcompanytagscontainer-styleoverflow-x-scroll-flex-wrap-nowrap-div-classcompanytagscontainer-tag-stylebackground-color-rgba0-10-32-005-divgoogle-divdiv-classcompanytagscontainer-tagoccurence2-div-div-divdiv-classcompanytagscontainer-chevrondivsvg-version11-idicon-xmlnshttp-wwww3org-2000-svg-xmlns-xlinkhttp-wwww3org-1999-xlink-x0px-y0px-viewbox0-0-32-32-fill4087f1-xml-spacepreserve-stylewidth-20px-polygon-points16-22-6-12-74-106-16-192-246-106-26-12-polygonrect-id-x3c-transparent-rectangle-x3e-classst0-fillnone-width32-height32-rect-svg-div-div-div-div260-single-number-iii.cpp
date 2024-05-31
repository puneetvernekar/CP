class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        long x=0;
        for(int i=0;i<nums.size();i++)
        x=x^nums[i];
        
        int rig_bit=(x&x-1)^x;
        int b1=0,b2=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&rig_bit)
                b1=b1^nums[i];
            else
                b2=b2^nums[i];
        }
        
        return {b1,b2};
    }
};