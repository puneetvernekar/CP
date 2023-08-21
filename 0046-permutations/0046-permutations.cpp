class Solution {
public:
    void find(vector<int>&nums,vector<vector<int>>&ans,int ind)
    {
        if(ind==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int j=ind;j<nums.size();j++)
        {
            swap(nums[ind],nums[j]);
            find(nums,ans,ind+1);
            swap(nums[ind],nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        find(nums,ans,0);
        return ans;
    }
};