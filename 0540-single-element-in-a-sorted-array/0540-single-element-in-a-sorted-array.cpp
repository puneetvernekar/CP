class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=1,h=nums.size()-2,n=nums.size();
        if(n==1)
            return nums[0];
        if(nums[0]!=nums[1])
            return nums[0];
        if(nums[n-1]!=nums[n-2])
            return nums[n-1];
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
                return nums[mid];
            if((mid%2==0 && nums[mid]==nums[mid+1])||(mid%2==1 && nums[mid]==nums[mid-1]))
                l=mid+1;
            else
                h=mid-1;
        }
        return -1;
    }
};