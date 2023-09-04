class Solution {
public:
    int partition(vector<int>&nums,int l,int r)
    {
        int pivot=nums[l],ini_left=l;
        l=l+1;
        while(l<=r)
        {
            if(nums[l]<pivot && pivot<nums[r])
            {
                swap(nums[l],nums[r]);
                l++,r--;
            }
            if(nums[l]>=pivot)
                l++;
            if(nums[r]<=pivot)
                r--;
        }
        swap(nums[ini_left],nums[r]);
        return r;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int l=0,r=nums.size()-1;
        while(true)
        {
            int ind=partition(nums,l,r);
            if(ind==k-1)
                return nums[ind];
            if(ind<k-1)
                l=ind+1;
            else
                r=ind-1;
        }
        return -1;
    }
};