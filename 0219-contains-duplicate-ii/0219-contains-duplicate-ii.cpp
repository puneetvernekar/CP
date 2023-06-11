class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int>hash;
        for(int i=0;i<nums.size();i++)
        {               
            if(hash.count(nums[i]) && abs(hash[nums[i]]-i)<=k)
            return true;
            hash[nums[i]]=i;
        }
        return false;
    }
};