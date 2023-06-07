class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int f=checkfl(nums, target,true);
        int l=checkfl(nums, target,false);
        ans.push_back(f);
        ans.push_back(l);
        return ans;

    }
    int checkfl(vector<int> &nums, int target,bool check)
    {
        int l=0,h=nums.size()-1,res=-1;

        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(target>nums[m])
            l=m+1;
            else if(target<nums[m])
            h=m-1;
            else
            {   
                res=m;
                if(check)
                h=m-1;
                else
                l=m+1;
            }
        }
        return res;
    }
};