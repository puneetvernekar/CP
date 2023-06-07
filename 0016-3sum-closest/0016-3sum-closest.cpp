class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min1=INT_MAX,s=0,ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {  
            int j=i+1;
            int k=nums.size()-1;
            while(j<k)
            {   s=nums[i]+nums[j]+nums[k];
                if(s==target)
                return target;
                else if(abs(s-target)<min1)
                {min1=abs(s-target);
                ans=s;
                }
                if(s>target)
                k--;
                else
                j++;

            }    
        }
        return ans;
    }
};