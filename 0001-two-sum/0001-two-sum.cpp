class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int>m;
    vector<int> ans;
    for(int i=0;i<nums.size();i++)
   {
      int dif=target-nums[i];
      if(m.find(dif)!=m.end())
      {ans.push_back(m[dif]);
      ans.push_back(i);
      break;}
      m[nums[i]]=i;
   }
   return ans;
    }
};