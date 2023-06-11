class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector <int>ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0;
        set<int> s;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]>nums2[j])
            j++;
            else if(nums1[i]<nums2[j])
            i++;
            else
            {s.insert(nums1[i]);
            i++;
            j++;
            }
        }
        for(auto i:s)
        ans.push_back(i);
        return ans;
    }
};