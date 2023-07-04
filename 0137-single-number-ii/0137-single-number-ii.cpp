class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int i=1;
        // if(nums.size()<3)
        // return nums[0];
        // sort(nums.begin(),nums.end());
        // while(i<nums.size())
        // {
        //     if(nums[i]!=nums[i-1])
        //     return nums[i-1];
        //     i=i+3;
        // }
        // return nums[nums.size()-1];
        
        int ans=0;
        for(int i=0;i<32;i++)
        {
            int sum=0;
            for(int j=0;j<nums.size();j++)
            {
                sum+=(nums[j]>>i)&1;
            }
            sum=sum%3;
            ans|=(sum<<i);
        }
        return ans;
    }
};