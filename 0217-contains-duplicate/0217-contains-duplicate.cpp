class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> a;
        for(int i=0;i<nums.size();i++)
        {if(a[nums[i]])
        return true;
        else
        a[nums[i]]++;}
        return false;
    }
};