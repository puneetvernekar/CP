class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int i,j=0;
        for(i=0;i<n;i++)
        {if(nums[i]<=target)
            j=i+1;
        if(nums[i]==target)
            return i;
        }
    return j;  
    }
};