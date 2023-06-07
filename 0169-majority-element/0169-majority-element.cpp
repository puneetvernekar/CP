class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0,ele;
        for(int i=0;i<n;i++)
        {
            if(count==0)
            ele=nums[i];
            if(ele==nums[i])
            count+=1;
            else
            count-=1;
        }
        return ele;
    }
};