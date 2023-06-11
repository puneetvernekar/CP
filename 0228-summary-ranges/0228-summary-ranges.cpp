class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size()==0)
        return ans;
        int s=nums[0];
        int e=nums[0]; 
        for(int i=1;i<nums.size();i++)
        {
            if(e+1==nums[i])
            e=nums[i];
            else
            {
                if(s==e)
                ans.push_back(to_string(s));
                else
                ans.push_back(to_string(s)+"->"+to_string(e));   
            s=nums[i];
            e=nums[i];
            }
        }
        if(s==e)
        ans.push_back(to_string(s));
        else
        ans.push_back(to_string(s)+"->"+to_string(e));
        return ans;

    }
};