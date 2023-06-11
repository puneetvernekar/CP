class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int x=0,s=0;
        for(int i=0;i<n;i++)
        {s+=nums[i];
        x+=i;
        }
        return n+x-s;
    }
};