class Solution {
public:
    void find(vector<int>&candidates,int target,vector<int>&temp,vector<vector<int>>&ans,int index)
    {
        if(index==candidates.size())
        {
            if(target==0)
                ans.push_back(temp);
            return;
        }
        if(candidates[index]<=target)
        {
            temp.push_back(candidates[index]);
            find(candidates,target-candidates[index],temp,ans,index);
            temp.pop_back();
        }
        find(candidates,target,temp,ans,index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        find(candidates,target,temp,ans,0);
        return ans;
    }
};