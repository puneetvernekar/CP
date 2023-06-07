class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int sq=1;
        while(true)
        {  
            if(count(nums.begin(), nums.end(),sq)==0)
            return sq;
            else
            sq*=2;
        }
        return 0;
    }
};