class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sw=0,pos;
        bool flag=true;
        for(int i=nums.size()-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {sw=nums[i-1];
            pos=i-1;
            flag=false;
            break;}
        }
        if(flag)
        sort(nums.begin(),nums.end());
        else
        {   int minimum=INT_MAX;
            for(int j=pos+1;j<nums.size();j++)
            {
                if(nums[j]-sw>0 && nums[j]-sw<minimum)
                swap(nums[j],nums[pos]);
            }
            sort(nums.begin()+pos+1,nums.end());
        }
    }
};